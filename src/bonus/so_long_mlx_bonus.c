/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mlx_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:01:51 by zlee              #+#    #+#             */
/*   Updated: 2025/04/06 15:36:42 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_pos(t_data *mlx)
{
	find_player_coordinate(mlx->map_data, &(mlx->player.pos.x),
		&(mlx->player.pos.y));
	mlx->player.pos.x = mlx->player.pos.x * 32;
	mlx->player.pos.y = mlx->player.pos.y * 32;
	mlx->player.target_pos.x = mlx->player.pos.x;
	mlx->player.target_pos.y = mlx->player.pos.y;
}

void	mlx_start(t_list *map)
{
	t_data	mlx;

	ft_memset(&mlx, 0, sizeof(t_data));
	mlx.win.x = ft_strlen((char *)map->content) * MUL;
	mlx.win.y = ft_lstsize(map) * MUL;
	mlx.map_data = map;
	init_pos(&mlx);
	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		return ;
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.win.x,
			mlx.win.y, "So Long Bonus!");
	set_spr_data(&mlx);
	init_numbers(&mlx);
	set_sprites_bonus(&mlx);
	mlx_loop_hook(mlx.mlx_ptr, print_all_elem_bonus, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0, close_win, &mlx);
	mlx_key_hook(mlx.win_ptr, game_movement_bonus, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return ;
}
