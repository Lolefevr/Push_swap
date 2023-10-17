/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:22:25 by lolefevr          #+#    #+#             */
/*   Updated: 2023/02/26 19:09:05 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa(unsigned int arg, int *count, char symbol)
{
	if (arg >= 16)
		ft_puthexa(arg / 16, count, symbol);
	arg %= 16;
	if (arg <= 9)
		ft_putchar_fd(arg + '0', 1, count);
	else if (arg > 9 && symbol == 'x')
		ft_putchar_fd((arg - 10) + 'a', 1, count);
	else if (arg > 9 && symbol == 'X')
		ft_putchar_fd((arg - 10) + 'A', 1, count);
}
