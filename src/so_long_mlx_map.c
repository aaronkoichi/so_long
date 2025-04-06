/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mlx_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:03:03 by zlee              #+#    #+#             */
/*   Updated: 2025/04/06 15:48:01 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_ground(t_data *mlx, t_sprite *img)
{
	t_pos	pos;
	int		i;
	t_list	*map;

	map = mlx->map_data;
	pos.y = 0;
	while (map)
	{
		i = -1;
		pos.x = 0;
		while (((char *)map->content)[++i])
		{
			put_img_on_canvas(mlx, &(mlx->textures[0]), img, pos);
			pos.x += MUL;
		}
		pos.y += MUL;
		map = map->next;
	}
}

void	print_individual_sprites(t_data *mlx,
				char element, int num, t_sprite *img)
{
	int		i;
	t_list	*map;
	t_pos	pos;

	map = mlx->map_data;
	pos.y = 0;
	while (map)
	{
		i = -1;
		pos.x = 0;
		while (((char *)map->content)[++i])
		{
			if (((char *)map->content)[i] == element)
				put_img_on_canvas(mlx, &(mlx->textures[num]), img, pos);
			pos.x += MUL;
		}
		pos.y += MUL;
		map = map->next;
	}
}

int	print_all_elements(t_data *mlx)
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
	print_individual_sprites(mlx, 'P', 2, &mlx->display);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->display.img_ptr, 0, 0);
	mlx_destroy_image(mlx->mlx_ptr, mlx->display.img_ptr);
	return (0);
}
