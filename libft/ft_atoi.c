/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:06:48 by lolefevr          #+#    #+#             */
/*   Updated: 2023/02/10 16:25:13 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	isnegative;

	result = 0;
	isnegative = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			isnegative = -isnegative;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str -48;
		str++;
	}
	return (result * isnegative);
}
