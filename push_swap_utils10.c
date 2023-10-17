/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils10.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:29:08 by lolefevr          #+#    #+#             */
/*   Updated: 2023/04/30 20:18:56 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"

int	ft_norme_split(char **argv, t_list **lst_a)
{
	char	**str;
	int		first;
	t_list	*temp;
	int		i;
	int		len;

	i = 1;
	len = 1;
	str = ft_split(argv[1], ' ');
	first = atoi(str[0]);
	*lst_a = ft_lstnewv2(first);
	while (str[i])
	{
		first = atoi(str[i++]);
		temp = ft_lstnewv2(first);
		ft_lstadd_backv2(lst_a, temp);
	}
	i = -1;
	while (str[++i])
		len += 1;
	ft_free_tab(str);
	return (len);
}

int	ft_parsing(t_list **lst_a, int argc, char **argv, int i)
{
	int		first;
	t_list	*temp;

	if (argc > 2)
	{
		first = ft_atoi(argv[i++]);
		*lst_a = ft_lstnewv2(first);
		while (argv[i])
		{
			first = ft_atoi(argv[i++]);
			temp = ft_lstnewv2(first);
			ft_lstadd_backv2(lst_a, temp);
		}
	}
	else if (argc == 2)
		i = ft_norme_split(argv, lst_a);
	return (--i);
}

void	ft_start_lst(t_list **lst_a, t_list **lst_b, int i)
{
	int	pivot;

	pivot = ft_find_pivot(*lst_a, i);
	ft_create_lst_b(lst_a, lst_b, pivot);
	if (ft_is_b_sorted(*lst_b, ft_find_border(*lst_b, MAX)) > 0)
		ft_sort_b_croissant(lst_b,
			ft_is_b_sorted(*lst_b, ft_find_border(*lst_b, MAX)), lst_a, pivot);
	while (ft_lstlen(*lst_a) > 3)
	{
		pivot = ft_find_newpivot(*lst_a,
				(ft_lstlen(*lst_a) + (ft_lstlen(*lst_a) / 2)));
		ft_create_lst_b(lst_a, lst_b, pivot);
		if (ft_is_b_sorted(*lst_b, ft_find_border(*lst_b, MAX)) > 0)
			ft_sort_b_croissant(lst_b, ft_is_b_sorted(*lst_b,
					ft_find_border(*lst_b, MAX)), lst_a, pivot);
	}
	ft_sort3a(lst_a, ft_find_border(*lst_a, MAX), ft_find_border(*lst_a, MIN));
	if (ft_is_a_sorted(*lst_a, ft_find_border(*lst_a, MIN)) > 0)
		ft_final_sort_a(lst_a,
			ft_is_a_sorted(*lst_a, ft_find_border(*lst_a, MIN)));
	ft_last_push(lst_a, lst_b);
}

void	ft_bythree(t_list **lst_a, int max, int min)
{
	if (ft_is_b_sorted(*lst_a, ft_find_border(*lst_a, MAX)) == 0)
	{
		ft_sa(lst_a, 1);
		ft_rra(lst_a, 1);
	}
	else if ((*lst_a)->content == min)
	{
		ft_ra(lst_a, 1);
		ft_sa(lst_a, 1);
		ft_rra(lst_a, 1);
	}
	else if ((*lst_a)->content == max)
		ft_ra(lst_a, 1);
	else if ((*lst_a)->content != max)
	{
		if ((*lst_a)->next->content == max)
		{
			ft_ra(lst_a, 1);
			ft_ra(lst_a, 1);
		}
		else
			ft_sa(lst_a, 1);
	}
}

void	ft_start_to_finish(t_list **lst_a, t_list **lst_b, int i)
{
	if (!ft_is_sorted(*lst_a))
	{
		if (ft_special_case(lst_a, lst_b, i))
			return ;
		else
			ft_start_lst(lst_a, lst_b, i);
	}
	ft_lstclear(lst_a);
	ft_lstclear(lst_b);
}
