/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mlx_spr_data_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:12:57 by zlee              #+#    #+#             */
/*   Updated: 2025/04/01 17:38:38 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_enemy_two(t_data *data)
{
	data->spr_data[1]->left[0]
		= create_sprite("./textures/charac/left_frame_1.xpm", data->mlx_ptr);
	data->spr_data[1]->left[1]
		= create_sprite("./textures/charac/left_frame_2.xpm", data->mlx_ptr);
	data->spr_data[1]->left[2]
		= create_sprite("./textures/charac/left_frame_3.xpm", data->mlx_ptr);
	data->spr_data[1]->left[3]
		= create_sprite("./textures/charac/left_frame_4.xpm", data->mlx_ptr);
	data->spr_data[1]->right[0]
		= create_sprite("./textures/charac/right_frame_1.xpm", data->mlx_ptr);
	data->spr_data[1]->left[1]
		= create_sprite("./textures/charac/right_frame_2.xpm", data->mlx_ptr);
	data->spr_data[1]->left[2]
		= create_sprite("./textures/charac/right_frame_3.xpm", data->mlx_ptr);
	data->spr_data[1]->left[3]
		= create_sprite("./textures/charac/right_frame_4.xpm", data->mlx_ptr);
}

static void	set_enemy(t_data *data)
{
	data->spr_data[1]->up[0]
		= create_sprite("./textures/enemy/up_frame_1.xpm", data->mlx_ptr);
	data->spr_data[1]->up[1]
		= create_sprite("./textures/enemy/up_frame_2.xpm", data->mlx_ptr);
	data->spr_data[1]->up[2]
		= create_sprite("./textures/enemy/up_frame_3.xpm", data->mlx_ptr);
	data->spr_data[1]->up[3]
		= create_sprite("./textures/enemy/up_frame_4.xpm", data->mlx_ptr);
	data->spr_data[1]->down[0]
		= create_sprite("./textures/enemy/down_frame_1.xpm", data->mlx_ptr);
	data->spr_data[1]->down[1]
		= create_sprite("./textures/enemy/down_frame_2.xpm", data->mlx_ptr);
	data->spr_data[1]->down[2]
		= create_sprite("./textures/enemy/down_frame_3.xpm", data->mlx_ptr);
	data->spr_data[1]->down[3]
		= create_sprite("./textures/enemy/down_frame_4.xpm", data->mlx_ptr);
	set_enemy_two(data);
}

static void	set_player_two(t_data *data)
{
	data->spr_data[0]->left[0]
		= create_sprite("./textures/charac/a_frame_1.xpm", data->mlx_ptr);
	data->spr_data[0]->left[1]
		= create_sprite("./textures/charac/a_frame_2.xpm", data->mlx_ptr);
	data->spr_data[0]->left[2]
		= create_sprite("./textures/charac/a_frame_3.xpm", data->mlx_ptr);
	data->spr_data[0]->left[3]
		= create_sprite("./textures/charac/a_frame_4.xpm", data->mlx_ptr);
	data->spr_data[0]->right[0]
		= create_sprite("./textures/charac/d_frame_1.xpm", data->mlx_ptr);
	data->spr_data[0]->left[1]
		= create_sprite("./textures/charac/d_frame_2.xpm", data->mlx_ptr);
	data->spr_data[0]->left[2]
		= create_sprite("./textures/charac/d_frame_3.xpm", data->mlx_ptr);
	data->spr_data[0]->left[3]
		= create_sprite("./textures/charac/d_frame_4.xpm", data->mlx_ptr);
}

static void	set_player(t_data *data)
{
	data->spr_data[0]->up[0]
		= create_sprite("./textures/charac/w_frame_1.xpm", data->mlx_ptr);
	data->spr_data[0]->up[1]
		= create_sprite("./textures/charac/w_frame_2.xpm", data->mlx_ptr);
	data->spr_data[0]->up[2]
		= create_sprite("./textures/charac/w_frame_3.xpm", data->mlx_ptr);
	data->spr_data[0]->up[3]
		= create_sprite("./textures/charac/w_frame_4.xpm", data->mlx_ptr);
	data->spr_data[0]->down[0]
		= create_sprite("./textures/charac/s_frame_1.xpm", data->mlx_ptr);
	data->spr_data[0]->down[1]
		= create_sprite("./textures/charac/s_frame_2.xpm", data->mlx_ptr);
	data->spr_data[0]->down[2]
		= create_sprite("./textures/charac/s_frame_3.xpm", data->mlx_ptr);
	data->spr_data[0]->down[3]
		= create_sprite("./textures/charac/s_frame_4.xpm", data->mlx_ptr);
	set_player_two(data);
}

void	set_spr_data(t_data *data)
{
	set_player(data);
	set_enemy(data);
}
