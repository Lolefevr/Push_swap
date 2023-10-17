/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:13:59 by lolefevr          #+#    #+#             */
/*   Updated: 2023/03/17 23:15:09 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_trimbegin(char *s1, char *set, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (count > 0)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				i++;
				count++;
			}
			else if (set[j] != s1[i])
				j++;
		}
		count--;
	}
	return (i);
}

int	ft_trimend(char *s1, char *set, int count)
{
	int	len;
	int	j;

	len = ft_strlen(s1);
	len--;
	while (count > 0)
	{
		j = 0;
		while (set[j])
		{
			if (set[j] != s1[len])
				j++;
			else if (set[j] == s1[len])
			{
				len--;
				count++;
			}
		}
		count--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		count;
	int		begin;
	int		final;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(""));
	str = (char *)s1;
	count = ft_strlen(set);
	begin = ft_trimbegin(str, (char *)set, count);
	final = ft_trimend(str, (char *)set, count);
	return (ft_substr(s1, begin, (final + 1) - begin));
}
