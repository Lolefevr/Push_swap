/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:24:34 by lolefevr          #+#    #+#             */
/*   Updated: 2023/02/16 16:21:47 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	if (!s || !c)
		return (((char *)s) + ft_strlen(s));
	i = -1;
	while (s[++i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
	}
	if ((char)c == *s)
		return ((char *)s);
	return (0);
}
