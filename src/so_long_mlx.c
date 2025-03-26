/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:36:06 by zlee              #+#    #+#             */
/*   Updated: 2025/03/27 01:46:20 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	game_movement(int keysym, t_data *data)
{
	if (keysym == XK_W)
		;
	else if (keysym == XK_A)
		;
	else if (keysym == XK_S)
		;
	else if (keysym == XK_D)
		;
	else if (XK_ESC)
		; // destroy the window and exit.
	return (0);
}

void	mlx_start(t_list *map)
{
	t_data 		mlx;
	int			x;
	int			y;
	t_sprite	test;

	x = ft_strlen((char *)map->content) * MUL;
	y = ft_lstsize(map) * MUL;
	mlx.map_data = map;
	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		return ;	
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, x, y, "Hello World Test");
	set_sprites(&mlx);
	mlx_key_hook(mlx.win_ptr, game_movement, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, print_all_elements, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return ;
}
