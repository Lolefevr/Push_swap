/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:21:16 by lolefevr          #+#    #+#             */
/*   Updated: 2023/02/26 17:20:06 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str)
{
	int	i;

	if (str == 0)
		return (ft_printstr("(null)"));
	i = 0;
	while (str[i])
		i++;
	ft_putstr_fd(str, 1);
	return (i);
}
