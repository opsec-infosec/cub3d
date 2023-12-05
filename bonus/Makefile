# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 17:20:57 by dfurneau          #+#    #+#              #
#    Updated: 2022/12/22 00:21:04 by dfurneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	../cub3D-bonus
MINILIBX	=	libmlx.a
LIBFT		=	libft.a

OS := $(shell uname)
ifeq (${OS},Darwin)
	MLXFLAGS	= 	-framework OpenGL -framework AppKit ../${MINILIBX}
	CFLAGS		+=	-D OSX
else
	MLXFLAGS 	=	../${MINILIBX} -lXext -lX11 -lm
	CFLAGS		+=	-D LINUX
endif

SRCS		=	cub3d.c \
				\
				./debug/debug.c \
				\
				./memory/error.c \
				./memory/memory_alloc.c \
				./memory/memory_free.c \
				\
				./parsing/parse_file.c \
				./parsing/parse_textures.c \
				./parsing/parse_colors.c \
				./parsing/parse_map.c \
				./parsing/parse_doors.c \
				./parsing/validate_map.c \
				\
				./events/key_evt.c \
				./events/mouse_evt.c \
				\
				../pixel_utils/frame_buffer.c \
				../pixel_utils/pixel_utils.c \
				\
				math.c \
				graphics.c \
				dynamic.c \
				\
				./mouse/mouse_linux.c \
				./mouse/mouse_osx.c \
				./mouse/pause.c \
				\
				./sprites/alloc_sprites.c \
				\
				./minimap/minimap.c \
				./minimap/minimap_utils.c \
				./wallcollision/wallcollision.c \
				./wallcollision/wallcollisioninit.c \
				\
				./wallcollision/doorcollision.c \
				./wallcollision/doorcollisioninit.c \
				\
				./fullmap/map_alloc.c \
				./fullmap/map_utils.c \
				\
 				./ray_cast/ray_cast.c \
				./ray_cast/ray_project.c \
				./ray_cast/wall_check.c \
				./textures/texture.c \
				./ray_cast/plot_line.c

OBJS		=	${SRCS:.c=.o}

CC			=	gcc
CFLAGS		+=	-Wall -Wextra -Werror -Ofast
LIBC		=	ar rcs
RM			=	rm -f


${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} ../${LIBFT} ${MLXFLAGS} -o ${NAME} -I./includes -I../includes

all:		${NAME}

bonus:		all

clean:
			${RM} ${OBJS}

fclean:		clean

re:			fclean all

.PHONY : all bonus clean re fclean
