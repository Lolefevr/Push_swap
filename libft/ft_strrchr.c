/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:24:40 by lolefevr          #+#    #+#             */
/*   Updated: 2023/02/16 17:07:07 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	if (!c)
		return (((char *)s) + ft_strlen(s));
	str = (char *)s;
	i = ft_strlen(s);
	while (i >= 0 && s[i] != (char)c)
		i--;
	if (i < 0)
		return (0);
	return (str + i);
}
