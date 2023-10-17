/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:14:13 by lolefevr          #+#    #+#             */
/*   Updated: 2023/05/06 11:50:57 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pushswap.h"
#include "ft_printf.h"

int	ft_main_error(int argc, char **argv)
{
	char	**split;

	if (argc > 2)
	{
		if (ft_check_error(argc, argv, 0, 0))
			return (1);
	}
	else if (argc == 2)
	{
		if (ft_check_error2(argv))
			return (1);
		split = ft_split(argv[1], ' ');
		ft_splitlen(split);
		if (ft_check_error(argc, split, -1, 0))
		{
			ft_free_tab(split);
			return (1);
		}
		ft_free_tab(split);
	}
	return (0);
}

int	ft_special_case(t_list **lst_a, t_list **lst_b, int i)
{
	if (i == 2)
	{
		ft_sa(lst_a, 1);
		ft_lstclear(lst_a);
		return (1);
	}
	if (i == 3)
	{
		ft_bythree(lst_a, ft_find_border(*lst_a, MAX),
			ft_find_border(*lst_a, MIN));
		ft_lstclear(lst_a);
		return (1);
	}
	if (i == 6)
	{
		ft_bysix(lst_a, lst_b);
		ft_lstclear(lst_a);
		ft_lstclear(lst_b);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	int		i;

	lst_b = NULL;
	if (argc == 1)
		return (0);
	if (ft_main_error(argc, argv))
		return (0);
	i = ft_parsing(&lst_a, argc, argv, 1);
	ft_start_to_finish(&lst_a, &lst_b, i);
	return (0);
}
