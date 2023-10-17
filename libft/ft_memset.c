/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:23:34 by lolefevr          #+#    #+#             */
/*   Updated: 2023/02/11 22:47:14 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = str;
	i = 0;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (str);
}
