/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:13:17 by lolefevr          #+#    #+#             */
/*   Updated: 2023/02/16 17:52:10 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new_s;
	unsigned int	i;
	unsigned int	j;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	new_s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_s)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		new_s[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new_s[i + j] = s2[j];
		j++;
	}
	new_s[i + j] = '\0';
	return (new_s);
}
