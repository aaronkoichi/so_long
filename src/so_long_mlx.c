/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:36:06 by zlee              #+#    #+#             */
/*   Updated: 2025/03/28 23:03:25 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	mlx_start(t_list *map)
{
	t_data 		mlx;
	t_sprite	test;

	mlx.win_x = ft_strlen((char *)map->content) * MUL;
	mlx.win_y = ft_lstsize(map) * MUL;
	mlx.map_data = map;
	mlx.counter = 0;
	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		return ;	
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.win_x, mlx.win_y, "Hello World Test");
	set_sprites(&mlx);
	mlx_key_hook(mlx.win_ptr, game_movement, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, print_all_elements, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return ;
}
