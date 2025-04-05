/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_render_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:33:38 by zlee              #+#    #+#             */
/*   Updated: 2025/04/05 22:23:07 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	switch_pos(t_data *mlx)
{
	if (mlx->dir == DOWN)
		mlx->textures[2] = mlx->spr_data[0].down[mlx->spr_data[0].frame];
	else if (mlx->dir == UP)
		mlx->textures[2] = mlx->spr_data[0].up[mlx->spr_data[0].frame];
	else if (mlx->dir == LEFT)
		mlx->textures[2] = mlx->spr_data[0].left[mlx->spr_data[0].frame];
	else if (mlx->dir == RIGHT)
		mlx->textures[2] = mlx->spr_data[0].right[mlx->spr_data[0].frame];
}

static void	switch_frames(int t_x, int t_y, t_data *mlx)
{
	if ((t_x == mlx->spr_data[0].pos.x
		&& t_y == mlx->spr_data[0].pos.y) || mlx->frame_counter == 0)
		mlx->spr_data[0].frame = 0;
	else if (mlx->spr_data[0].frame >= 3)
		mlx->spr_data[0].frame = 0;
	else if (mlx->frame_counter % 4 == 0)
		mlx->spr_data[0].frame++;
}

void	print_player(t_data *mlx)
{
	t_pos	target;

	target.x = 0;
	target.y = 0;
	find_player_coordinate(mlx->map_data, &target.x, &target.y);
	target.x = target.x * 32;
	target.y = target.y * 32;
	switch_pos(mlx);
	interpolation(mlx, target);
	switch_frames(target.x, target.y, mlx);
	xpm_image_transparency(mlx, &(mlx->textures[2]), &mlx->d_img, mlx->spr_data[0].pos);
}

int	print_all_elem_bonus(t_data *mlx)
{
	mlx->d_img.img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_x, mlx->win_y);
	mlx->d_img.pixels = mlx_get_data_addr(mlx->d_img.img_ptr, &mlx->d_img.bpp,
			&mlx->d_img.line_size, &mlx->d_img.endian);
	print_ground(mlx, &mlx->d_img);
	print_individual_sprites(mlx, '1', 1, &mlx->d_img);
	print_individual_sprites(mlx, 'C', 3, &mlx->d_img);
	print_individual_sprites(mlx, 'E', 4, &mlx->d_img);
	if (mlx->exit_check == 1)
		print_individual_sprites(mlx, 'P', 4, &mlx->d_img);
	print_player(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->d_img.img_ptr, 0, 0);
	process_number(mlx);
	mlx_destroy_image(mlx->mlx_ptr, mlx->d_img.img_ptr);
	return (0);
}
