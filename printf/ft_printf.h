/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:07:48 by lolefevr          #+#    #+#             */
/*   Updated: 2023/02/27 18:52:50 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <ctype.h>
# include <stddef.h>
# include <stdio.h>
# include <stdarg.h>

size_t		ft_strlen(const char *s);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putchar_fd(char c, int fd, int *count);
int			ft_ptr_len(unsigned long num);
void		ft_put_ptr(unsigned long num);
int			ft_print_p(void *ptr, int *count);
void		ft_putnbr_fd_printf(int n, int fd, int *count);
int			ft_printstr(char *str);
int			ft_print_text(const char *format, int i, int *count);
int			ft_putnbr_u(unsigned int nbr, int *count);
void		ft_puthexa(unsigned int arg, int *count, char symbol);
int			ft_find_symbol(char *format, int i, va_list arg, int *count);
int			ft_printf(const char *format, ...);

#endif
