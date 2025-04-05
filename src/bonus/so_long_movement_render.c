/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_movement_render.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:20:48 by zlee              #+#    #+#             */
/*   Updated: 2025/04/05 23:06:36 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void exec_interpo(t_pos *src, t_pos target, int intensity)
{
	src->x =
		((SLOW_INT - intensity) * src->x + intensity * target.x) / SLOW_INT;
	src->y =
		((SLOW_INT - intensity) * src->y + intensity * target.y) / SLOW_INT;
}

void interpolation(t_data *mlx, t_pos target)
{
	if (mlx->spr_data[0].target_pos.x != target.x
		|| mlx->spr_data[0].target_pos.y != target.y)
	{
		mlx->spr_data[0].target_pos.x = target.x;
		mlx->spr_data[0].target_pos.y = target.y;
		mlx->frame_counter = 0;
	}
	if (mlx->frame_counter <= SLOW_INT)
	{
		exec_interpo(&(mlx->spr_data[0].pos),
			mlx->spr_data[0].target_pos, mlx->frame_counter);
		mlx->frame_counter++;
	}
	if (mlx->frame_counter > SLOW_INT)
	{
		mlx->frame_counter = 0;
		mlx->spr_data[0].pos.x = target.x;
		mlx->spr_data[0].pos.y = target.y;
	}
}

