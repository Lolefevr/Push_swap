/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:31:23 by lolefevr          #+#    #+#             */
/*   Updated: 2023/02/18 00:47:25 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*d;
	int		i;

	i = ft_strlen(s1);
	d = (char *)malloc((i + 1) * sizeof(char));
	if (!d)
		return (0);
	i = -1;
	while (s1[++i])
	{
		d[i] = s1[i];
	}
	d[i] = 0;
	return (d);
}
