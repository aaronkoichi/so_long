/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:36:06 by zlee              #+#    #+#             */
/*   Updated: 2025/04/06 15:37:37 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_start(t_list *map)
{
	t_data	mlx;

	ft_memset(&mlx, 0, sizeof(t_data));
	mlx.win.x = ft_strlen((char *)map->content) * MUL;
	mlx.win.y = ft_lstsize(map) * MUL;
	mlx.map_data = map;
	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		return ;
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.win.x, mlx.win.y, "So Long!");
	set_sprites(&mlx);
	mlx_loop_hook(mlx.mlx_ptr, print_all_elements, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0, close_win, &mlx);
	mlx_key_hook(mlx.win_ptr, game_movement, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return ;
}
