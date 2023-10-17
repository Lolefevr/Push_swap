/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:35:23 by lolefevr          #+#    #+#             */
/*   Updated: 2023/02/14 20:29:29 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*memory;
	size_t	i;
	size_t	temp;

	i = 0;
	if (count == 0 || size == 0)
		return (malloc(0));
	temp = count * size;
	if (size != temp / count)
		return (NULL);
	memory = malloc(count * size);
	if (memory == NULL)
		return (0);
	while (i < count * size)
		memory[i++] = 0;
	return ((void *)memory);
}
