# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/13 16:59:41 by zlee              #+#    #+#              #
#    Updated: 2025/04/06 15:24:36 by zlee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

BONUS_NAME = so_long_bonus

INCLUDES = -Iincludes/ -Ilibft/

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
	   $(SRC_FOLDER)/so_long_mlx_utils.c \
	   $(SRC_FOLDER)/so_long_mlx_movement.c \
	   $(SRC_FOLDER)/so_long_mlx_movement_check.c \
	   $(SRC_FOLDER)/so_long_mlx_exit.c \

BONUS_SRCS = $(SRC_FOLDER)/so_long_utils.c \
			 $(SRC_FOLDER)/so_long_check_map_1.c \
			 $(SRC_FOLDER)/so_long_check_walls.c \
			 $(SRC_FOLDER)/so_long_check_map_2.c \
	   		 $(SRC_FOLDER)/so_long_find_player_coordinate.c \
	   		 $(SRC_FOLDER)/so_long_mlx_sprites.c \
	   		 $(SRC_FOLDER)/so_long_mlx_map.c \
	   		 $(SRC_FOLDER)/so_long_mlx_utils.c \
	   		 $(SRC_FOLDER)/so_long_mlx_movement.c \
			 $(SRC_FOLDER)/bonus/so_long_check_map_bonus.c \
			 $(SRC_FOLDER)/bonus/so_long_game_handling_bonus.c \
			 $(SRC_FOLDER)/bonus/so_long_main_bonus.c \
			 $(SRC_FOLDER)/bonus/so_long_mlx_bonus.c \
			 $(SRC_FOLDER)/bonus/so_long_mlx_spr_data_bonus.c \
			 $(SRC_FOLDER)/bonus/so_long_render_bonus.c \
			 $(SRC_FOLDER)/bonus/so_long_sprites_bonus.c \
			 $(SRC_FOLDER)/bonus/so_long_movement_bonus.c \
			 $(SRC_FOLDER)/bonus/so_long_movement_render.c \
			 $(SRC_FOLDER)/bonus/so_long_init_numbers.c \
			 $(SRC_FOLDER)/bonus/so_long_ff_bonus.c \
			 $(SRC_FOLDER)/bonus/so_long_mlx_exit_bonus.c \

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

# MEM_CHECK = -fsanitize=address -fsanitize=undefined -g3

all : $(NAME)
	
bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJS)
	@echo "Compiling MLX.."
	@cd minilibx-linux && ./configure
	@echo "Compiling libft.."
	@make -C libft bonus
	@echo "Compiling game bonus.."
	@$(CC) $(CFLAGS) $(MEM_CHECK) $(INCLUDES) $^ ./libft/libft.a -Lminilibx-linux -lmlx_Linux -L/usr/lib -Iincludes -Iminilibx-linux -lXext -lX11 -lm -lz -o $@
	@echo "Done!"


$(NAME) : $(OBJS)
	@cd minilibx-linux && ./configure
	@make -C libft bonus
	@$(CC) $(CFLAGS) $(MEM_CHECK) $(INCLUDES) $^ ./libft/libft.a -Lminilibx-linux -lmlx_Linux -L/usr/lib -Iincludes -Iminilibx-linux -lXext -lX11 -lm -lz -o $@
	@echo "Done!"

%.o : %.c 
	@$(CC) $(CFLAGS) $(MEM_CHECK) $(INCLUDES) -I/usr/include -Iminilibx-linux -O3 -c $< -o $@

clean: 
	cd minilibx-linux && ./configure clean
	make -C libft clean
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	cd libft; rm -rf libft.a
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
