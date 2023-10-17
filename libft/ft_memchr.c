/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:41:48 by lolefevr          #+#    #+#             */
/*   Updated: 2023/02/19 18:41:36 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cpy;

	cpy = (unsigned char *)s;
	while (n > 0)
	{
		if (*cpy == (unsigned char)c)
			return (cpy);
		cpy++;
		n--;
	}
	return (NULL);
}
