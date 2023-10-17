/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 00:27:33 by lolefevr          #+#    #+#             */
/*   Updated: 2023/05/06 12:11:41 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"

int	ft_still_under_pivot(t_list *lst, int pivot)
{
	while (lst)
	{
		if (lst->content <= pivot)
			return (0);
		lst = lst->next;
	}
	return (1);
}

t_list	*ft_b_sort1(t_list *temp, int *i, int max)
{
	while (temp && temp->content != max)
	{
		(*i)++;
		temp = temp->next;
	}
	if (temp->next)
		temp = temp->next;
	while (temp)
	{
		if (temp->next)
		{
			if (temp->content > temp->next->content)
				temp = temp->next;
			else
				break ;
		}
		else
			break ;
	}
	return (temp);
}

int	ft_is_b_sorted(t_list *lst_b, int max)
{
	t_list	*temp;
	int		i;
	int		j;

	temp = lst_b;
	i = 0;
	temp = ft_b_sort1(temp, &i, max);
	if (temp->next)
		return (-1);
	else if (lst_b->content == max)
		return (i);
	j = 0;
	if (temp->content > lst_b->content)
	{
		while (lst_b && j++ < (i - 1))
		{
			if (lst_b->content > lst_b->next->content)
				lst_b = lst_b->next;
			else
				return (-1);
		}
	}
	else
		return (-1);
	return (i);
}

int	ft_find_border(t_list *lst, int bool)
{
	int	number;

	number = lst->content;
	lst = lst->next;
	while (lst)
	{
		if (bool == 1)
		{
			if (number < lst->content)
				number = lst->content;
			lst = lst->next;
		}
		if (bool == 0)
		{
			if (number > lst->content)
				number = lst->content;
			lst = lst->next;
		}
	}
	return (number);
}

int	ft_next_after_pivot(t_list *lst, int pivot)
{
	int		min;
	t_list	*temp;

	min = ft_find_border(lst, MAX);
	temp = lst;
	while (temp)
	{
		if (temp->content > pivot && temp->content < min)
			min = temp->content;
		temp = temp->next;
	}
	return (min);
}
