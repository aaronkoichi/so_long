/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mlx_spr_data_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:12:57 by zlee              #+#    #+#             */
/*   Updated: 2025/04/08 00:42:01 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_enemy(t_data *data)
{
	data->enemy.frame[0]
		= create_sprite("./textures/enemy/down_frame_1.xpm", data->mlx_ptr);
	data->enemy.frame[1]
		= create_sprite("./textures/enemy/down_frame_2.xpm", data->mlx_ptr);
	data->enemy.frame[2]
		= create_sprite("./textures/enemy/down_frame_3.xpm", data->mlx_ptr);
	data->enemy.frame[3]
		= create_sprite("./textures/enemy/down_frame_4.xpm", data->mlx_ptr);
}

static void	set_player_two(t_data *data)
{
	data->player.left[0]
		= create_sprite("./textures/charac/a_frame_1.xpm", data->mlx_ptr);
	data->player.left[1]
		= create_sprite("./textures/charac/a_frame_2.xpm", data->mlx_ptr);
	data->player.left[2]
		= create_sprite("./textures/charac/a_frame_3.xpm", data->mlx_ptr);
	data->player.left[3]
		= create_sprite("./textures/charac/a_frame_4.xpm", data->mlx_ptr);
	data->player.right[0]
		= create_sprite("./textures/charac/d_frame_1.xpm", data->mlx_ptr);
	data->player.right[1]
		= create_sprite("./textures/charac/d_frame_2.xpm", data->mlx_ptr);
	data->player.right[2]
		= create_sprite("./textures/charac/d_frame_3.xpm", data->mlx_ptr);
	data->player.right[3]
		= create_sprite("./textures/charac/d_frame_4.xpm", data->mlx_ptr);
}

static void	set_player(t_data *data)
{
	data->player.up[0]
		= create_sprite("./textures/charac/w_frame_1.xpm", data->mlx_ptr);
	data->player.up[1]
		= create_sprite("./textures/charac/w_frame_2.xpm", data->mlx_ptr);
	data->player.up[2]
		= create_sprite("./textures/charac/w_frame_3.xpm", data->mlx_ptr);
	data->player.up[3]
		= create_sprite("./textures/charac/w_frame_4.xpm", data->mlx_ptr);
	data->player.down[0]
		= create_sprite("./textures/charac/s_frame_1.xpm", data->mlx_ptr);
	data->player.down[1]
		= create_sprite("./textures/charac/s_frame_2.xpm", data->mlx_ptr);
	data->player.down[2]
		= create_sprite("./textures/charac/s_frame_3.xpm", data->mlx_ptr);
	data->player.down[3]
		= create_sprite("./textures/charac/s_frame_4.xpm", data->mlx_ptr);
	set_player_two(data);
}

void	set_spr_data(t_data *data)
{
	data->player.frame = 0;
	data->enemy.frame_num = 0;
	set_player(data);
	set_enemy(data);
}
