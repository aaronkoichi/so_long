# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/13 16:59:41 by zlee              #+#    #+#              #
#    Updated: 2025/03/26 16:18:44 by zlee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

INCLUDES = -Iincludes/

SRC_FOLDER = ./src

SRCS = $(SRC_FOLDER)/so_long_main.c \
	   $(SRC_FOLDER)/so_long_utils.c \
	   $(SRC_FOLDER)/so_long_check_map_1.c \
	   $(SRC_FOLDER)/so_long_check_walls.c \
	   $(SRC_FOLDER)/so_long_check_map_2.c \
	   $(SRC_FOLDER)/so_long_find_player_coordinate.c \
	   $(SRC_FOLDER)/so_long_flood_fill.c \
	   $(SRC_FOLDER)/so_long_mlx.c \
	   $(SRC_FOLDER)/so_long_mlx_map.c \
	   $(SRC_FOLDER)/so_long_mlx_sprites.c \

OBJS = $(SRCS:.c=.o)

CC = cc

# CFLAGS = -Wall -Wextra -Werror

MEM_CHECK = -fsanitize=address -fansanitize=undefined -g3

all : $(NAME)
	
$(NAME) : $(OBJS)
	cd mlx_linux && ./configure
	make -C libft bonus
	$(CC) $(CFLAGS) $(INCLUDES) $^ ./libft/libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $@

%.o : %.c 
	$(CC) $(CFLAGS) $(INCLUDES) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean: 
	cd mlx_linux && ./configure clean
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	cd libft; rm -rf libft.a
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
