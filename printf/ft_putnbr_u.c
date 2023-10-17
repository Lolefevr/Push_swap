/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:22:16 by lolefevr          #+#    #+#             */
/*   Updated: 2023/02/26 17:12:39 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int nbr, int *count)
{
	if (nbr == 4294967295)
	{
		ft_putstr_fd("4294967295", 1);
		*count += 10;
		return (0);
	}
	if (nbr > 9)
		ft_putnbr_fd_printf(nbr / 10, 1, count);
	ft_putchar_fd(nbr % 10 + '0', 1, count);
	return (0);
}
