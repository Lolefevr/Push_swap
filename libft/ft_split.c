/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:39:13 by lolefevr          #+#    #+#             */
/*   Updated: 2023/02/19 20:17:46 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcount(char const *s, char c)
{
	int	i;
	int	count;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			count++;
		else if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		index;
	char	**tab;

	index = -1;
	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_strcount(s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (s[i])
	{
		j = 0;
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			while (s[i + j] != c && s[i + j])
				j++;
			tab[++index] = ft_substr(s, i, j);
		}
		i++;
	}
	tab[++index] = NULL;
	return (tab);
}
