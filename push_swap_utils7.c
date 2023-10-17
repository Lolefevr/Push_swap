/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils7.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 00:27:41 by lolefevr          #+#    #+#             */
/*   Updated: 2023/04/23 05:15:32 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"

int	ft_is_a_sorted(t_list *lst_a, int min)
{
	t_list	*temp;
	int		i;
	int		j;

	temp = lst_a;
	i = 0;
	temp = ft_a_sort1(temp, &i, min);
	if (temp->next)
		return (-1);
	else if (lst_a->content == min)
		return (i);
	j = 0;
	if (temp->content < lst_a->content)
	{
		while (lst_a && j++ < i -1)
		{
			if (lst_a->content < lst_a->next->content)
				lst_a = lst_a->next;
			else
				return (-1);
		}
	}
	else
		return (-1);
	return (i);
}

void	ft_sort3(t_list **lst_b, int max, int min)
{
	if (ft_is_b_sorted(*lst_b, max) != -1)
		return ;
	if (((*lst_b)->content == min) || (*lst_b)->content == max)
	{
		if ((*lst_b)->content == min)
			if ((*lst_b)->next->next->content == max)
				ft_sb(lst_b, 1);
		if ((*lst_b)->content == max)
			if ((*lst_b)->next->content == min)
				ft_sb(lst_b, 1);
	}
	else
		ft_sb(lst_b, 1);
	if ((*lst_b)->content != max)
	{
		if ((*lst_b)->next->next->content == max)
			ft_rrb(lst_b, 1);
		else
			ft_rb(lst_b, 1);
	}
}

void	ft_sort3a(t_list **lst_a, int max, int min)
{
	if (ft_is_a_sorted(*lst_a, min) != -1)
		return ;
	if (ft_lstlen(*lst_a) < 3)
	{
		ft_sa(lst_a, 1);
		return ;
	}
	if (((*lst_a)->content == min) || (*lst_a)->content == max)
	{
		if ((*lst_a)->content == min)
		{
			ft_ra(lst_a, 1);
			ft_sa(lst_a, 1);
			ft_rra(lst_a, 1);
		}
		if ((*lst_a)->content == max)
		{
			ft_ra(lst_a, 1);
			ft_sa(lst_a, 1);
		}
	}
	else
		ft_sa(lst_a, 1);
}

void	ft_create_lst_bpush(t_list **lst_a, t_list **lst_b, int piv, int *cnt)
{
	if ((*lst_a)->content <= piv)
	{
		if (*lst_b && ((*cnt >= 4) || ft_lstlen(*lst_b) >= 4))
		{
			while ((*lst_b)->content
				!= ft_chr_place_in_lst(*lst_b, (*lst_a)->content))
			{
				if (ft_best_rotateb(*lst_b, ft_chr_place_in_lst
						(*lst_b, (*lst_a)->content)) == 1)
					ft_rrb(lst_b, 1);
				else
					ft_rb(lst_b, 1);
			}
		}
		ft_pb(lst_a, lst_b);
		(*cnt)++;
	}
}

void	ft_create_lst_bra(t_list **lst_a, t_list **lst_b, int piv, int cnt)
{
	if (cnt >= 3)
	{
		while ((*lst_a)->content > piv)
		{
			if ((*lst_b)->content
				!= ft_chr_place_in_lst(*lst_b, ft_futur_piv_num(*lst_a, piv)))
			{
				if (ft_best_rotatev2(*lst_b, ft_futur_pivot_index(*lst_a, piv),
						ft_chr_place_in_lst(*lst_b,
							ft_futur_piv_num(*lst_a, piv)), 0) == 1)
					ft_rrb(lst_b, 1);
				else
					ft_rr(lst_a, lst_b);
			}
			else
				ft_ra(lst_a, 1);
		}
	}
	else
		ft_ra(lst_a, 1);
}
