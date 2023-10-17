/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:20:36 by lolefevr          #+#    #+#             */
/*   Updated: 2023/02/26 17:11:18 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(void *ptr, int *count)
{
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		*count += 5;
		return (1);
	}
	else
		write(1, "0x", 2);
	*count += 2;
	ft_put_ptr((unsigned long)ptr);
	*count += ft_ptr_len((unsigned long)ptr);
	return (1);
}
