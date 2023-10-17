/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 00:27:23 by lolefevr          #+#    #+#             */
/*   Updated: 2023/05/06 11:51:30 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"
#include "ft_printf.h"

void	ft_ss(t_list **a, t_list **b)
{
	ft_sa(a, 0);
	ft_sb(b, 0);
	ft_printf("ss\n");
}

void	ft_pa(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	ft_printf("pa\n");
}

void	ft_pb(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!*a)
		return ;
	if (!b)
		b = malloc(sizeof(t_list));
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	ft_printf("pb\n");
}

void	ft_ra(t_list **a, int print)
{
	t_list	*temp;
	t_list	*last;

	last = *a;
	temp = *a;
	*a = (*a)->next;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
	if (print == 1)
		ft_printf("ra\n");
}

void	ft_rb(t_list **b, int print)
{
	t_list	*temp;
	t_list	*last;

	last = *b;
	temp = *b;
	*b = (*b)->next;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
	if (print == 1)
		ft_printf("rb\n");
}
