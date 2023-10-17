/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:20:51 by lolefevr          #+#    #+#             */
/*   Updated: 2023/02/26 17:12:27 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd_printf(int n, int fd, int *count)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		*count += 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd, count);
		n *= -1;
	}
	if (n > 9)
		ft_putnbr_fd_printf(n / 10, fd, count);
	ft_putchar_fd(n % 10 + '0', fd, count);
}
