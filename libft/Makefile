# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/05 20:54:53 by dfurneau          #+#    #+#              #
#    Updated: 2022/12/21 17:35:19 by dfurneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
PRINTF	=	libftprintf.a
GNL		=	libgnl.a

P_D 	=	./ft_printf
G_D 	= 	./get_next_line

SRCS	=	ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			ft_isprint.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
			ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c \
			ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
			ft_memcmp.c ft_calloc.c ft_strdup.c ft_strjoin.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_split.c \
			ft_putnbr_fd.c ft_substr.c ft_strtrim.c ft_itoa.c ft_striteri.c \
			ft_strmapi.c ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstadd_front.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c \
			ft_putnumber.c ft_abs.c ft_atol.c ft_atof.c \
			ft_strisdigit.c ft_strisnumber.c ft_strisalpha.c ft_strisalnum.c \
			ft_strisascii.c ft_strisprint.c ft_isneg.c  ft_strrmc.c ft_strrmstr.c\
			ft_spliti.c ft_splitn.c ft_strcmp.c  ft_atoll.c ft_atoull.c \
			ft_swapi.c ft_swap.c ft_strnjoin.c ft_realloc.c ft_splitis.c \
			ft_ptrptrlen.c ft_ispunctuation.c ft_strispunctuation.c \
			ft_strchri.c ft_strrchri.c ft_dtoa.c ft_free_split.c

OBJS	=	${SRCS:.c=.o}

PF_H	=	./ft_printf/includes/ft_printf.h
GNL_H 	=	./get_next_line/get_next_line.h
LFT_H	=	./libft.h
INC		=	./includes/
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -O3
LIBC	=	ar -rcs
RM		=	rm -f

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -c ${SRCS}
			${LIBC} T${NAME} ${OBJS}
			cp T${NAME} ${P_D}/${PRINTF}
			${MAKE} -j 4 wlibft -C ./ft_printf
			cp ${P_D}/${PRINTF} ${G_D}/${GNL}
			${MAKE} -j 4 libft -C ./get_next_line
			cp ${G_D}/${GNL} ${NAME}
			${RM} T${NAME}
			cp ${NAME} ../

all:		${NAME}


printf:
			${MAKE} -j 4 all -C ./ft_printf
			cp ${P_D}/${PRINTF} ./
			cp ${P_D}/${PRINTF} ../

gnl:
			${MAKE} -j 4 all -C ./get_next_line
			cp ${G_D}/${GNL} ./
			cp ${G_D}/${GNL} ../

libft:		${OBJS}
			${CC} ${CFLAGS} -c ${SRCS}
			${LIBC} ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}
			${MAKE} -j 4 clean -C ./ft_printf
			${MAKE} -j 4 clean -C ./get_next_line

fclean:		clean
			${RM} ${NAME} ${PRINTF} ${GNL}
			${MAKE} -j 4 fclean -C ./ft_printf
			${MAKE} -j 4 fclean -C ./get_next_line

re:			fclean all printf gnl libft

.PHONY : all printf gnl libft clean re fclean
