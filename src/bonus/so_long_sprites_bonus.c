/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_sprites_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:42:15 by zlee              #+#    #+#             */
/*   Updated: 2025/04/06 21:20:09 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_sprites_bonus(t_data *mlx)
{
	t_pos	p;

	p.x = MUL;
	p.y = MUL;
	mlx->textures[0] = create_sprite("./textures/ground_1.xpm",
			mlx->mlx_ptr, p);
	mlx->textures[1] = create_sprite("./textures/wall.xpm", mlx->mlx_ptr, p);
	mlx->textures[2] = mlx->player.down[0];
	mlx->textures[3] = create_sprite("./textures/food.xpm", mlx->mlx_ptr, p);
	mlx->textures[4] = create_sprite("./textures/exit.xpm", mlx->mlx_ptr, p);
	mlx->textures[5] = mlx->enemy.frame[0];
	mlx->dir = DOWN;
}
