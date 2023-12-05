# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/05 20:54:53 by dfurneau          #+#    #+#              #
#    Updated: 2021/10/31 12:22:40 by dfurneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libgnl.a

SRCS	=	get_next_line.c get_next_line_utils.c

OBJS	=	${SRCS:.c=.o}
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
DEBUG	=	-g
LIBC	=	ar -rcs
RM		=	rm -f


${NAME}:	${OBJS}
			${CC} ${CFLAGS} -c ${SRCS}
			${LIBC} ${NAME} ${OBJS}

all:		${NAME}

libft:		
			${CC} ${CFLAGS} -c ${SRCS}
			${LIBC} ${NAME} ${OBJS}

debug:		${OBJS}
			${CC} ${CFLAGS} ${DEBUG} -c ${SRCS} -I includes
			${LIBC} ${NAME} ${OBJS}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY : all libft clean fclean re debug
