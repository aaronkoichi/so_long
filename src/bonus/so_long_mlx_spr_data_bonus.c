/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mlx_spr_data_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:12:57 by zlee              #+#    #+#             */
/*   Updated: 2025/04/05 23:27:41 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_enemy(t_data *data)
{
	t_pos	p;

	p.x = 32;
	p.y = 32;
	data->enemy.frame[0]
		= create_sprite("./textures/enemy/down_frame_1.xpm", data->mlx_ptr, p);
	data->enemy.frame[1]
		= create_sprite("./textures/enemy/down_frame_2.xpm", data->mlx_ptr, p);
	data->enemy.frame[2]
		= create_sprite("./textures/enemy/down_frame_3.xpm", data->mlx_ptr, p);
	data->enemy.frame[3]
		= create_sprite("./textures/enemy/down_frame_4.xpm", data->mlx_ptr, p);
}

static void	set_player_two(t_data *data)
{
	t_pos	p;

	p.x = 32;
	p.y = 32;
	data->spr_data[0].left[0]
		= create_sprite("./textures/charac/a_frame_1.xpm", data->mlx_ptr, p);
	data->spr_data[0].left[1]
		= create_sprite("./textures/charac/a_frame_2.xpm", data->mlx_ptr, p);
	data->spr_data[0].left[2]
		= create_sprite("./textures/charac/a_frame_3.xpm", data->mlx_ptr, p);
	data->spr_data[0].left[3]
		= create_sprite("./textures/charac/a_frame_4.xpm", data->mlx_ptr, p);
	data->spr_data[0].right[0]
		= create_sprite("./textures/charac/d_frame_1.xpm", data->mlx_ptr, p);
	data->spr_data[0].right[1]
		= create_sprite("./textures/charac/d_frame_2.xpm", data->mlx_ptr, p);
	data->spr_data[0].right[2]
		= create_sprite("./textures/charac/d_frame_3.xpm", data->mlx_ptr, p);
	data->spr_data[0].right[3]
		= create_sprite("./textures/charac/d_frame_4.xpm", data->mlx_ptr, p);
}

static void	set_player(t_data *data)
{
	t_pos	p;

	p.x = 32;
	p.y = 32;
	data->spr_data[0].up[0]
		= create_sprite("./textures/charac/w_frame_1.xpm", data->mlx_ptr, p);
	data->spr_data[0].up[1]
		= create_sprite("./textures/charac/w_frame_2.xpm", data->mlx_ptr, p);
	data->spr_data[0].up[2]
		= create_sprite("./textures/charac/w_frame_3.xpm", data->mlx_ptr, p);
	data->spr_data[0].up[3]
		= create_sprite("./textures/charac/w_frame_4.xpm", data->mlx_ptr, p);
	data->spr_data[0].down[0]
		= create_sprite("./textures/charac/s_frame_1.xpm", data->mlx_ptr, p);
	data->spr_data[0].down[1]
		= create_sprite("./textures/charac/s_frame_2.xpm", data->mlx_ptr, p);
	data->spr_data[0].down[2]
		= create_sprite("./textures/charac/s_frame_3.xpm", data->mlx_ptr, p);
	data->spr_data[0].down[3]
		= create_sprite("./textures/charac/s_frame_4.xpm", data->mlx_ptr, p);
	set_player_two(data);
}

void	set_spr_data(t_data *data)
{
	data->spr_data[0].frame = 0;
	data->enemy.frame_num = 0;
	set_player(data);
	set_enemy(data);
}
