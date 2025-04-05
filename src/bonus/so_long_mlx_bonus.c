/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mlx_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:01:51 by zlee              #+#    #+#             */
/*   Updated: 2025/04/05 22:28:39 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_pos(t_data *mlx)
{
	find_player_coordinate(mlx->map_data, &(mlx->spr_data[0].pos.x),
		&(mlx->spr_data[0].pos.y));
	mlx->spr_data[0].pos.x = mlx->spr_data[0].pos.x * 32;
	mlx->spr_data[0].pos.y = mlx->spr_data[0].pos.y * 32;
	mlx->spr_data[0].target_pos.x = mlx->spr_data[0].pos.x;
	mlx->spr_data[0].target_pos.y = mlx->spr_data[0].pos.y;
}

void	mlx_start(t_list *map)
{
	t_data	mlx;

	mlx.win_x = ft_strlen((char *)map->content) * MUL;
	mlx.win_y = ft_lstsize(map) * MUL;
	mlx.map_data = map;
	mlx.counter = 0;
	mlx.exit_check = 0;
	mlx.frame_counter = 0;
	init_pos(&mlx);
	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		return ;
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.win_x, mlx.win_y, "So Long Bonus!");
	set_spr_data(&mlx);
	init_numbers(&mlx);
	set_sprites_bonus(&mlx);
	mlx_loop_hook(mlx.mlx_ptr, print_all_elem_bonus, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0, close_win, &mlx);
	mlx_key_hook(mlx.win_ptr, game_movement_bonus, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return ;
}
