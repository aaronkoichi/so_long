/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_render_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:33:38 by zlee              #+#    #+#             */
/*   Updated: 2025/04/01 19:45:47 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	// print_individual_sprites(mlx, 'P', 2, &mlx->d_img);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->d_img.img_ptr, 0, 0);
	mlx_destroy_image(mlx->mlx_ptr, mlx->d_img.img_ptr);
	return (0);
}
