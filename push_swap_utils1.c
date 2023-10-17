/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 00:26:17 by lolefevr          #+#    #+#             */
/*   Updated: 2023/05/06 11:51:18 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"
#include "ft_printf.h"

t_list	*ft_lstnewv2(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_backv2(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next != 0)
		temp = temp->next;
	temp->next = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_sa(t_list **a, int print)
{
	t_list	*temp;
	t_list	*temp2;
	t_list	*temp3;

	if (!(*a)->next)
		return ;
	temp = *a;
	temp2 = (*a)->next;
	*a = (*a)->next;
	temp3 = (*a)->next;
	temp->next = temp3;
	temp2->next = temp;
	if (print == 1)
		ft_printf("sa\n");
}

void	ft_sb(t_list **b, int print)
{
	t_list	*temp;
	t_list	*temp2;
	t_list	*temp3;

	if (!(*b)->next)
		return ;
	temp = *b;
	temp2 = (*b)->next;
	*b = (*b)->next;
	temp3 = (*b)->next;
	temp->next = temp3;
	temp2->next = temp;
	if (print == 1)
		ft_printf("sb\n");
}
