SRCS	= 	ft_printf.c \
			ft_strlen.c \
			ft_putstr_fd.c \
			ft_putchar_fd.c \
			ft_ptr_len.c \
			ft_print_p.c \
			ft_put_ptr.c \
			ft_putnbr_fd_printf.c \
			ft_printstr.c \
			ft_printtext.c \
			ft_putnbr_u.c \
			ft_puthexa.c \
			ft_findsymbol.c  

NAME	=	libftprintf.a
	
OBJS	=  ${SRCS:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	ar rcs ${NAME} ${OBJS}

.c.o	:
	gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all
