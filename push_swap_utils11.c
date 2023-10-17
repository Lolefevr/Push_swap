/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils11.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:52:43 by lolefevr          #+#    #+#             */
/*   Updated: 2023/04/30 20:20:12 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pushswap.h"

void	ft_beginsix(t_list **lst_a, t_list **lst_b, int i)
{
	int	pivot;

	pivot = ft_find_pivot(*lst_a, 4);
	ft_create_lst_b(lst_a, lst_b, pivot);
	if (!ft_is_sorted(*lst_a))
	{
		ft_bythree(lst_a, ft_find_border(*lst_a, MAX),
			ft_find_border(*lst_a, MIN));
	}
	if (ft_is_b_sorted(*lst_b, ft_find_border(*lst_b, MAX)) != 0)
	{
		while (i < 2)
		{
			if ((*lst_b)->content == ft_find_border(*lst_b, MAX))
			{
				ft_pa(lst_a, lst_b);
				i++;
			}
			else
				ft_rb(lst_b, 1);
		}
	}
}

void	ft_bysix(t_list **lst_a, t_list **lst_b)
{
	ft_beginsix(lst_a, lst_b, 0);
	if (ft_is_b_sorted(*lst_b, ft_find_border(*lst_b, MAX)) == 0)
	{
		ft_pa(lst_a, lst_b);
		ft_pa(lst_a, lst_b);
		ft_pa(lst_a, lst_b);
	}
}

int	ft_check_error2(char **argv)
{
	if (ft_strlen(argv[1]) < 2)
		return (1);
	else
		return (0);
}

int	ft_splitlen(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int	ft_check_dble_n_max_min2(char **argv, int argc)
{
	int	temp;
	int	i;
	int	j;
	int	count;

	i = 1;
	if (argc < 3)
		i = 0;
	argc = ft_splitlen(argv);
	while (i < argc)
	{
		temp = ft_atoi(argv[i++]);
		j = 1;
		count = 0;
		while (j < argc)
		{
			if (temp == ft_atoi(argv[j++]))
				count++;
			if ((count > 1) || (temp > 2147483647) || temp < -2147483647)
				return (1);
		}
	}
	return (0);
}
