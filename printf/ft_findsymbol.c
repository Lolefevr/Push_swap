/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findsymbol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:22:39 by lolefevr          #+#    #+#             */
/*   Updated: 2023/02/26 18:46:01 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_find_symbol(char *format, int i, va_list arg, int *count)
{
	if (format[i] == 'c')
		ft_putchar_fd(va_arg(arg, int), 1, count);
	else if (format[i] == 's')
		*count += ft_printstr(va_arg(arg, char *));
	else if (format[i] == 'd' || format[i] == 'i')
		ft_putnbr_fd_printf(va_arg(arg, int), 1, count);
	else if (format[i] == 'p')
		return (ft_print_p(va_arg(arg, void *), count) + i);
	else if (format[i] == 'x' || format[i] == 'X')
		ft_puthexa(va_arg(arg, long long int), count, format[i]);
	else if (format[i] == 'u')
		return (ft_putnbr_u(va_arg(arg, int), count) + i + 1);
	else
	{
		write(1, "%", 1);
		return (ft_print_text(format, i, count) + 1);
	}
	return (i + 1);
}
