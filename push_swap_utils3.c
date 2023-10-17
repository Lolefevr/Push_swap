/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 00:27:26 by lolefevr          #+#    #+#             */
/*   Updated: 2023/05/06 11:51:42 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"
#include "ft_printf.h"

void	ft_rr(t_list **a, t_list **b)
{
	ft_ra(a, 0);
	ft_rb(b, 0);
	ft_printf("rr\n");
}

void	ft_rra(t_list **a, int print)
{
	t_list	*last;
	t_list	*temp;

	last = *a;
	temp = *a;
	while (temp->next->next)
		temp = temp->next;
	while (last->next)
		last = last->next;
	last->next = *a;
	*a = last;
	temp->next = NULL;
	if (print == 1)
		ft_printf("rra\n");
}

void	ft_rrb(t_list **b, int print)
{
	t_list	*last;
	t_list	*temp;

	last = *b;
	temp = *b;
	while (temp->next->next)
		temp = temp->next;
	while (last->next)
		last = last->next;
	last->next = *b;
	*b = last;
	temp->next = NULL;
	if (print == 1)
		ft_printf("rrb\n");
}

void	ft_rrr(t_list **a, t_list **b)
{
	ft_rra(a, 0);
	ft_rrb(b, 0);
	ft_printf("rrr\n");
}

int	ft_is_sorted(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		if (temp->next)
		{
			if (temp->content > temp->next->content)
				return (0);
		}
		temp = temp->next;
	}
	return (1);
}
