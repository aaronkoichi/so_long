/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mlx_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:03:03 by zlee              #+#    #+#             */
/*   Updated: 2025/03/30 14:29:14 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_ground(t_data *mlx, t_list *map, t_sprite *img)
{
	int x;
	int	y;
	int i;
	
	y = 0;
	while (map)
	{
		i = -1;
		x = 0;
		while (((char *)map->content)[++i])
		{
			xpm_image_transparency(mlx, &(mlx->textures[0]), img, x, y);
			x += MUL;
		}
		y += MUL;
		map = map->next;
	}
}

void	print_individual_sprites(t_data *mlx, t_list *map,
				char element, int num, t_sprite *img)
{
	int x;
	int	y;
	int i;
	
	y = 0;
	while (map)
	{
		i = -1;
		x = 0;
		while (((char *)map->content)[++i])
		{
			if (((char *)map->content)[i] == element)
				xpm_image_transparency(mlx, &(mlx->textures[num]), img, x, y);
			x += MUL;
		}
		y += MUL;
		map = map->next;
	}
}

int	print_all_elements(t_data *mlx)
{
	mlx->d_img.img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_x, mlx->win_y);
	mlx->d_img.pixels = mlx_get_data_addr(mlx->d_img.img_ptr, &mlx->d_img.bpp, &mlx->d_img.line_size, &mlx->d_img.endian);
	print_ground(mlx, mlx->map_data, &mlx->d_img);
	print_individual_sprites(mlx, mlx->map_data, '1', 1, &mlx->d_img);
	print_individual_sprites(mlx, mlx->map_data, 'C', 3, &mlx->d_img);
	print_individual_sprites(mlx, mlx->map_data, 'E', 4, &mlx->d_img);
	if (mlx->exit_check == 1)
		print_individual_sprites(mlx, mlx->map_data, 'P', 4, &mlx->d_img);
	print_individual_sprites(mlx, mlx->map_data, 'P', 2, &mlx->d_img);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->d_img.img_ptr, 0, 0);
	mlx_destroy_image(mlx->mlx_ptr, mlx->d_img.img_ptr);
	return (0);
}
