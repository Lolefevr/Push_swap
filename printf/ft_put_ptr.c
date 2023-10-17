/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:20:25 by lolefevr          #+#    #+#             */
/*   Updated: 2023/02/26 17:12:02 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_ptr(unsigned long num)
{
	int	nul;

	nul = 0;
	if (num >= 16)
		ft_put_ptr(num / 16);
	num = num % 16;
	if (num <= 9)
		ft_putchar_fd((num + '0'), 1, &nul);
	else
		ft_putchar_fd((num - 10) + 'a', 1, &nul);
}
