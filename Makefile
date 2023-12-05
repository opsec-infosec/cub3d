# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 17:20:57 by dfurneau          #+#    #+#              #
#    Updated: 2022/12/20 17:09:54 by dfurneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D
BNAME		=	cub3D-bonus
OS := $(shell uname)
MINILIBX	=	libmlx.a
LIBFT		=	libft.a

all:		mlibx
			${MAKE} -C ./libft
			cp ./libft/${LIBFT} ./
			${MAKE} -C ./mandatory
			${MAKE} -C ./bonus

mandatory:	mlibx
			${MAKE} -C ./libft
			cp ./libft/${LIBFT} ./
			${MAKE} -C ./mandatory

bonus:		mlibx
			${MAKE} -C ./libft
			cp ./libft/${LIBFT} ./
			${MAKE} -C ./bonus

mlibx:
ifeq (${OS},Darwin)
			${MAKE} all -C ./minilibx
			cp ./minilibx/${MINILIBX} ./
else
			${MAKE} all -C ./minilibx-linux
			cp ./minilibx-linux/${MINILIBX} ./
endif

clean:
			${MAKE} clean -C ./libft
			${MAKE} clean -C ./mandatory
			${MAKE} clean -C ./bonus


fclean:
			${RM} ${NAME} ${BNAME} ./${LIBFT} ./${MINILIBX}
			${MAKE} fclean -C ./libft
			${MAKE} fclean -C ./mandatory
			${MAKE} fclean -C ./bonus
ifeq (${OS},Darwin)
			${MAKE} clean -C ./minilibx
			${RM} ./minilibx/${MINILIBX}
else
			${MAKE} clean -C ./minilibx-linux
			${RM} ./minilibx-linux/${MINILIBX}
endif

re:			fclean all

vg:			mandatory
			valgrind -s --leak-check=full --track-origins=yes --show-reachable=yes --suppressions=./valgrind_filter.supp ./${NAME} ${MAP}

vg-bonus:	bonus
			valgrind -s --leak-check=full --track-origins=yes --show-reachable=yes --suppressions=./valgrind_filter.supp ./${BNAME} ${MAP}

.PHONY : all mlibx mandatory bonus clean re fclean vg vg-bonus
