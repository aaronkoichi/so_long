/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mlx_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:03:03 by zlee              #+#    #+#             */
/*   Updated: 2025/03/26 16:14:26 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_ground(t_data *mlx, t_list *map)
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
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					mlx->textures[0].img_ptr, x, y);
			x += MUL;
		}
		y += MUL;
		map = map->next;
	}
}
