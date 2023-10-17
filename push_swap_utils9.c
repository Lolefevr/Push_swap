/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils9.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 00:27:46 by lolefevr          #+#    #+#             */
/*   Updated: 2023/04/30 14:17:59 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"

void	ft_last_push(t_list **lst_a, t_list **lst_b)
{
	while (*lst_b)
		ft_pa(lst_a, lst_b);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	if (!lst)
		return ;
	while (*lst != 0)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
	*lst = NULL ;
}

int	ft_check_dble_n_max_min(char **argv, int argc)
{
	int	temp;
	int	i;
	int	j;
	int	count;

	i = 1;
	if (argc < 3)
		i = 0;
	while (i < argc)
	{
		temp = ft_atoi(argv[i++]);
		j = 1;
		count = 0;
		while (j < argc)
		{
			if (temp == ft_atoi(argv[j++]))
				count++;
			if ((count > 1) || (temp > 2147483647) || temp < -2147483647)
				return (1);
		}
	}
	return (0);
}

int	ft_check_error(int argc, char **argv, int i, int j)
{
	while (argv[++i])
	{
		j = 0;
		if ((argv[i][j] == '-') || ft_isdigit(argv[i][j]) == 1)
		{
			if (argv[i][j] == '-' && (!ft_isdigit(argv[i][(j + 1)])))
				return (1);
			while (argv[i][++j])
				if (!ft_isdigit(argv[i][j]))
					return (1);
		}
		else
			return (1);
	}
	if (argc == 2)
	{
		if (ft_check_dble_n_max_min2(argv, argc))
			return (1);
	}
	else if (ft_check_dble_n_max_min(argv, argc))
		return (1);
	return (0);
}

void	ft_free_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
