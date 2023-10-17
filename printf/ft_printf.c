/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:39:14 by lolefevr          #+#    #+#             */
/*   Updated: 2023/02/27 16:09:58 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int					count;
	long unsigned int	i;
	va_list				arg;

	va_start(arg, format);
	i = 0;
	count = 0;
	while (i < ft_strlen(format))
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				ft_putchar_fd('%', 1, &count);
				i += 2;
			}
			else
				i = ft_find_symbol((char *) format, i + 1, arg, &count);
		}
		else
			i = ft_print_text((char *) format, i, &count);
	}
	va_end(arg);
	return (count);
}
