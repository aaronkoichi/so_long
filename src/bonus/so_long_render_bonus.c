/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_render_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:33:38 by zlee              #+#    #+#             */
/*   Updated: 2025/04/06 21:20:27 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	switch_pos(t_data *mlx)
{
	if (mlx->dir == DOWN)
		mlx->textures[2] = mlx->player.down[mlx->player.frame];
	else if (mlx->dir == UP)
		mlx->textures[2] = mlx->player.up[mlx->player.frame];
	else if (mlx->dir == LEFT)
		mlx->textures[2] = mlx->player.left[mlx->player.frame];
	else if (mlx->dir == RIGHT)
		mlx->textures[2] = mlx->player.right[mlx->player.frame];
}

/*counter:
 * 1 --> player
 * else --> enemy*/
static void	switch_frames(int t_x, int t_y, t_data *mlx, int counter)
{
	if (counter == 1)
	{
		if ((t_x == mlx->player.pos.x
				&& t_y == mlx->player.pos.y) || mlx->frame_counter == 0)
			mlx->player.frame = 0;
		else if (mlx->player.frame >= 3)
			mlx->player.frame = 0;
		else if (mlx->frame_counter % FRAME_MUL == 0)
			mlx->player.frame++;
	}
	else
	{
		if (mlx->enemy.fps > TOTAL_ENEMY_FRAME)
			mlx->enemy.fps = 0;
		if (mlx->enemy.frame_num >= 3)
			mlx->enemy.frame_num = 0;
		else if (mlx->enemy.fps % FRAME_MUL == 0)
			mlx->enemy.frame_num++;
		mlx->enemy.fps++;
	}
}

void	print_player(t_data *mlx)
{
	t_pos	target;

	target.x = 0;
	target.y = 0;
	find_player_coordinate(mlx->map_data, &target.x, &target.y);
	target.x = target.x * MUL;
	target.y = target.y * MUL;
	switch_pos(mlx);
	interpolation(mlx, target);
	switch_frames(target.x, target.y, mlx, 1);
	put_img_on_canvas(mlx, &(mlx->textures[2]),
		&mlx->display, mlx->player.pos);
}

int	print_all_elem_bonus(t_data *mlx)
{
	mlx->display.img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win.x, mlx->win.y);
	mlx->display.pixels = mlx_get_data_addr(mlx->display.img_ptr, &mlx->display.bpp,
			&mlx->display.line_size, &mlx->display.endian);
	print_ground(mlx, &mlx->display);
	print_individual_sprites(mlx, '1', 1, &mlx->display);
	print_individual_sprites(mlx, 'C', 3, &mlx->display);
	print_individual_sprites(mlx, 'E', 4, &mlx->display);
	if (mlx->exit_check == 1)
		print_individual_sprites(mlx, 'P', 4, &mlx->display);
	print_player(mlx);
	switch_frames(0, 0, mlx, 2);
	mlx->textures[5] = mlx->enemy.frame[mlx->enemy.frame_num];
	print_individual_sprites(mlx, 'N', 5, &mlx->display);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->display.img_ptr, 0, 0);
	process_number(mlx);
	mlx_destroy_image(mlx->mlx_ptr, mlx->display.img_ptr);
	return (0);
}
