/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 00:27:38 by lolefevr          #+#    #+#             */
/*   Updated: 2023/05/06 12:11:48 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"

int	ft_just_before_pivot(t_list *lst, int pivot)
{
	int		max;
	t_list	*temp;

	max = ft_find_border(lst, MIN);
	temp = lst;
	while (temp)
	{
		if (temp->content < pivot && temp->content > max)
			max = temp->content;
		temp = temp->next;
	}
	return (max);
}

int	ft_chr_place_in_lst(t_list *lst_b, int start)
{
	t_list	*temp;
	int		goodnum;

	if ((start < ft_find_border(lst_b, MIN))
		|| start > ft_find_border(lst_b, MAX))
		return (ft_find_border(lst_b, MAX));
	temp = lst_b;
	goodnum = 0;
	while (temp)
	{
		if (start > temp->content)
		{
			if (temp->content > goodnum || goodnum == 0)
				goodnum = temp->content;
		}
		temp = temp->next;
	}
	return (goodnum);
}

int	ft_futur_piv_num(t_list *lst_a, int pivot)
{
	while (lst_a)
	{
		if (lst_a->content > pivot)
			lst_a = lst_a->next;
		else
			break ;
	}
	if (lst_a == NULL)
		return (-1);
	return (lst_a->content);
}

int	ft_futur_pivot_index(t_list *lst_a, int pivot)
{
	int	i;

	i = 0;
	while (lst_a)
	{
		if (lst_a->content > pivot)
		{
			i++;
			lst_a = lst_a->next;
		}
		else
			break ;
	}
	return (i);
}

t_list	*ft_a_sort1(t_list *temp, int *i, int min)
{
	while (temp && temp->content != min)
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
			if (temp->content < temp->next->content)
				temp = temp->next;
			else
				break ;
		}
		else
			break ;
	}
	return (temp);
}
