# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 14:55:38 by lolefevr          #+#    #+#              #
#    Updated: 2023/05/04 16:56:00 by lolefevr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	push_swap_utils10.c \
			push_swap_utils1.c \
			push_swap_utils2.c \
			push_swap_utils3.c \
			push_swap_utils4.c \
			push_swap_utils5.c \
			push_swap_utils6.c \
			push_swap_utils7.c \
			push_swap_utils8.c \
			push_swap_utils9.c \
			push_swap_utils11.c \
			push_swap.c

OBJS	=	$(SRCS:.c=.o)

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I $(LIB) -I $(LIBPRF) -g -fsanitize=address

RM = rm -f

NAME	=	push_swap

LIBFT	=	libft/libft.a

LIB = ./libft

LIBFTPRINTF = printf/libftprintf.a

LIBPRF = ./printf

all:	$(LIBFT) $(LIBFTPRINTF) $(NAME)

$(LIBFT):
		@make -C $(LIB) bonus

$(LIBFTPRINTF):
		@make -C $(LIBPRF)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L ${LIB} -lft -L ${LIBPRF} -lftprintf

clean:
		$(RM) $(OBJS)
		@make -C $(LIB) clean
		@make -C $(LIBPRF) clean

fclean:	clean
		$(RM) $(NAME)
		@make -C $(LIB) fclean
		@make -C $(LIBPRF) fclean

re:		fclean all

