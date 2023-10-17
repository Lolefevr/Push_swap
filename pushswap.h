/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:02:16 by lolefevr          #+#    #+#             */
/*   Updated: 2023/04/30 20:22:31 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# define MAX 1
# define MIN 0
# define B 1
# define A 0

void	ft_start_to_finish(t_list **lst_a, t_list **lst_b, int i);
void	ft_start_lst(t_list **lst_a, t_list **lst_b, int i);
int		ft_parsing(t_list **lst_a, int argc, char **argv, int i);
int		ft_norme_split(char **argv, t_list **lst_a);
t_list	*ft_lstnewv2(int content);
void	ft_lstadd_backv2(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_sa(t_list **a, int print);
void	ft_sb(t_list **b, int print);
void	ft_rb(t_list **b, int print);
void	ft_ra(t_list **a, int print);
void	ft_pb(t_list **a, t_list **b);
void	ft_pa(t_list **a, t_list **b);
void	ft_ss(t_list **a, t_list **b);
void	ft_rr(t_list **a, t_list **b);
void	ft_rra(t_list **a, int print);
void	ft_rrb(t_list **b, int print);
void	ft_rrr(t_list **a, t_list **b);
int		ft_is_sorted(t_list *lst);
int		ft_lstlen(t_list *lst);
int		ft_find_newpivot(t_list *a, int len);
int		ft_find_pivot(t_list *a, int len);
int		ft_best_rotateb(t_list *lst, int pivot);
int		ft_best_rotatev2(t_list *lst, int pivotindex, int pivot, int bool);
int		ft_still_under_pivot(t_list *lst, int pivot);
t_list	*ft_b_sort1(t_list *temp, int *i, int max);
int		ft_is_b_sorted(t_list *lst_b, int max);
int		ft_find_border(t_list *lst, int bool);
int		ft_next_after_pivot(t_list *lst, int pivot);
int		ft_just_before_pivot(t_list *lst, int pivot);
int		ft_chr_place_in_lst(t_list *lst_b, int start);
int		ft_futur_piv_num(t_list *lst_a, int pivot);
int		ft_futur_pivot_index(t_list *lst_a, int pivot);
t_list	*ft_a_sort1(t_list *temp, int *i, int min);
int		ft_is_a_sorted(t_list *lst_a, int min);
void	ft_sort3(t_list **lst_b, int max, int min);
void	ft_sort3a(t_list **lst_a, int max, int min);
void	ft_create_lst_bpush(t_list **lst_a, t_list **lst_b, int piv, int *cnt);
void	ft_create_lst_bra(t_list **lst_a, t_list **lst_b, int piv, int cnt);
void	ft_create_lst_b(t_list **lst_a, t_list **lst_b, int pivot);
void	ft_sortb1(t_list **lst_b, int check, t_list **lst_a, int pivot);
void	ft_sortb2(t_list **lst_b, int check, t_list **lst_a, int pivot);
void	ft_sort_b_croissant(t_list **lst_b, int check, t_list **lst_a, int piv);
void	ft_final_sort_a(t_list **lst_a, int check);
void	ft_last_push(t_list **lst_a, t_list **lst_b);
void	ft_lstclear(t_list **lst);
int		ft_check_dble_n_max_min(char **argv, int argc);
int		ft_check_error(int argc, char **argv, int i, int j);
void	ft_free_tab(char **str);
void	ft_bythree(t_list **lst_a, int max, int min);
void	ft_bysix(t_list **lst_a, t_list **lst_b);
void	ft_beginsix(t_list **lst_a, t_list **lst_b, int i);
int		ft_check_error2(char **argv);
int		ft_splitlen(char **split);
int		ft_check_dble_n_max_min2(char **argv, int argc);
int		ft_main_error(int argc, char **argv);
int		ft_special_case(t_list **lst_a, t_list **lst_b, int i);

#endif
