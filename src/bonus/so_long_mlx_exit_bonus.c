/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mlx_exit_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 23:45:28 by zlee              #+#    #+#             */
/*   Updated: 2025/04/06 00:00:40 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

static void	destroy_player(t_data *data, int num)
{
	mlx_destroy_image(data->mlx_ptr, data->spr_data[0].down[num].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->spr_data[0].up[num].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->spr_data[0].left[num].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->spr_data[0].right[num].img_ptr);
}

static void	destroy_enemy(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->enemy.frame[0].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->enemy.frame[1].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->enemy.frame[2].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->enemy.frame[3].img_ptr);
}

static void	destroy_numbers(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->numbers[0].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->numbers[1].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->numbers[2].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->numbers[3].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->numbers[4].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->numbers[5].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->numbers[6].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->numbers[7].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->numbers[8].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->numbers[9].img_ptr);
}

int	close_win(t_data *data)
{
	int	count;

	count = 4;
	mlx_destroy_image(data->mlx_ptr, data->textures[0].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->textures[1].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->textures[3].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->textures[4].img_ptr);
	while (--count >= 0)
		destroy_player(data, count);
	destroy_enemy(data);
	destroy_numbers(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	data->map_data = ft_lstfirst(data->map_data);
	ft_lstclear(&(data->map_data), free);
	free(data->mlx_ptr);
	exit (0);
	return (0);
}
