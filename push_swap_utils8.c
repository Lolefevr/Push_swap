/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils8.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 00:27:43 by lolefevr          #+#    #+#             */
/*   Updated: 2023/04/23 05:29:43 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"

void	ft_create_lst_b(t_list **lst_a, t_list **lst_b, int pivot)
{
	static int		count;

	count = 0;
	while (*lst_a && ft_still_under_pivot(*lst_a, pivot) == 0)
	{
		if (count == 3 && ft_lstlen(*lst_b) == 3)
		{
			if (ft_is_b_sorted(*lst_b, ft_find_border(*lst_b, MAX)) != 0)
				ft_sort3(lst_b, ft_find_border(*lst_b, MAX),
					ft_find_border(*lst_b, MIN));
			count++;
		}
		if ((*lst_a)->content <= pivot)
			ft_create_lst_bpush(lst_a, lst_b, pivot, &count);
		else
			ft_create_lst_bra(lst_a, lst_b, pivot, count);
	}
}

void	ft_sortb1(t_list **lst_b, int check, t_list **lst_a, int pivot)
{
	int	i;
	int	len;

	len = ft_lstlen(*lst_b);
	i = 0;
	if (check <= (len / 2))
	{
		while (i < check)
		{
			if ((*lst_a)->content > pivot)
			{
				ft_rr(lst_a, lst_b);
				i++;
			}
			else
			{
				ft_rb(lst_b, 1);
				i++;
			}
		}
	}
}

void	ft_sortb2(t_list **lst_b, int check, t_list **lst_a, int pivot)
{
	int	i;
	int	len;

	len = ft_lstlen(*lst_b);
	i = 0;
	if (check > (len / 2))
	{
		while (i < (len - check))
		{
			if ((*lst_a)->content > pivot)
			{
				ft_rrr(lst_a, lst_b);
				i++;
			}
			else
			{
				ft_rrb(lst_b, 1);
				i++;
			}
		}
	}
}

void	ft_sort_b_croissant(t_list **lst_b, int check, t_list **lst_a, int piv)
{
	int	len;

	len = ft_lstlen(*lst_b);
	if (check <= (len / 2))
		ft_sortb1(lst_b, check, lst_a, piv);
	if (check > (len / 2))
		ft_sortb2(lst_b, check, lst_a, piv);
}

void	ft_final_sort_a(t_list **lst_a, int check)
{
	int	len;
	int	i;

	len = ft_lstlen(*lst_a);
	i = 0;
	if (check <= (len / 2))
	{
		while (i < check)
		{
			ft_ra(lst_a, 1);
			i++;
		}
	}
	else
	{
		while (i < (len - check))
		{
			ft_rra(lst_a, 1);
			i++;
		}
	}
}
