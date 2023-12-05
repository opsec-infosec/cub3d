# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/05 20:54:53 by dfurneau          #+#    #+#              #
#    Updated: 2021/10/29 10:25:18 by dfurneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
LIBFT	=	libft.a

SRCS	=	ft_printf.c ft_printf_char.c ft_printf_hex.c ft_printf_int.c \
			ft_printf_uint.c ft_printf_str.c ft_printf_ptr.c \
			ft_printf_helper.c 	libft_ext.c

WLIBFT	=	../ft_putchar_fd.c ../ft_putnbr_fd.c ../ft_atoi.c \
			../ft_strlen.c ../ft_putstr_fd.c 

DLIBFT	=	ft_putchar_fd.o ft_putnbr_fd.o ft_atoi.o \
			ft_strlen.o ft_putstr_fd.o

OBJS	=	${SRCS:.c=.o}
OLIBFT	=	${WLIBFT:.c=.o}
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
DEBUG	=	-g
LIBC	=	ar rcs
RM		=	rm -f


${NAME}:	${OBJS} ${OLIBFT}
			${CC} ${CFLAGS} -c ${SRCS} ${WLIBFT} -I includes
			${LIBC} ${NAME} ${OLIBFT} ${OBJS}

all:		${NAME}

wlibft:		
			${CC} ${CFLAGS} -c ${SRCS} -I includes
			${LIBC} ${NAME} ${OBJS}

debug:		${OBJS}
			${CC} ${CFLAGS} ${DEBUG} -c ${SRCS} ${WLIBFT} -I includes
			${LIBC} ${NAME} ${OLIBFT} ${OBJS}

clean:		
			${RM} ${OBJS} ${DLIBFT}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY : all clean fclean re debug