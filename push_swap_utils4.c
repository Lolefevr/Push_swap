/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 00:27:28 by lolefevr          #+#    #+#             */
/*   Updated: 2023/05/06 11:51:48 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"
#include "ft_printf.h"

int	ft_lstlen(t_list *lst)
{
	int	i;

	i = 1;
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	ft_find_newpivot(t_list *a, int len)
{
	int		number;
	t_list	*bigtemp;
	t_list	*smalltemp;
	int		count;

	bigtemp = a;
	len = (len / 2);
	count = 0;
	while (bigtemp)
	{
		number = bigtemp->content;
		smalltemp = a;
		count = 0;
		while (smalltemp)
		{
			if (number < smalltemp->content)
				count++;
			smalltemp = smalltemp->next;
		}
		bigtemp = bigtemp->next;
		if (count == len)
			return (number);
	}
	return (0);
}

int	ft_find_pivot(t_list *a, int len)
{
	int			number;
	t_list		*bigtemp;
	t_list		*smalltemp;
	int			count;

	bigtemp = a;
	len = (len / 4) * 3;
	count = 0;
	while (bigtemp)
	{
		number = bigtemp->content;
		smalltemp = a;
		count = 0;
		while (smalltemp)
		{
			if (number < smalltemp->content)
				count++;
			smalltemp = smalltemp->next;
		}
		bigtemp = bigtemp->next;
		if (count == len)
			return (number);
	}
	return (0);
}
/* rb = 0 , rrb = 1*/

int	ft_best_rotateb(t_list *lst, int pivot)
{
	t_list	*temp;
	int		countrb;
	int		countrrb;
	int		len;

	len = ft_lstlen(lst);
	countrb = 0;
	temp = lst;
	while (temp && temp->content != pivot)
	{
		countrb++;
		temp = temp->next;
	}
	countrrb = len - countrb;
	if (countrb < countrrb)
		return (0);
	else
		return (1);
}
/* 0 = rb et bool 0 = pour ra */

int	ft_best_rotatev2(t_list *lst, int pivotindex, int pivot, int bool)
{
	t_list	*temp;
	int		countrb;
	int		len;

	len = ft_lstlen(lst);
	countrb = 0;
	temp = lst;
	while (temp && temp->content != pivot)
	{
		countrb++;
		temp = temp->next;
	}
	if (bool == 0)
	{
		if ((countrb - pivotindex) <= (len / 2))
			return (0);
		else
			return (1);
	}
	else
	{
		if ((countrb + pivotindex) <= (len / 2))
			return (0);
	}
	return (1);
}
