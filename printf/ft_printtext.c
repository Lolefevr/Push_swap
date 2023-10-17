/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:21:57 by lolefevr          #+#    #+#             */
/*   Updated: 2023/02/26 17:11:46 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_text(const char *format, int i, int *count)
{
	while (format[i] && format[i] != '%')
	{
		write(1, format + i, 1);
		*count += 1;
		i++;
	}
	return (i);
}
