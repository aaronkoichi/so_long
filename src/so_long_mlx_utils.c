/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mlx_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:39:00 by zlee              #+#    #+#             */
/*   Updated: 2025/03/30 13:58:59 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	xpm_image_transparency(t_data *data, t_sprite *sprite, t_sprite *target,
				int offset_x, int offset_y)
{
	int	y;
	int	x;
	int	pixel_location;
	int	color;

	y = 0;
	while (y < MUL)
	{
		x = 0;
		while (x < MUL)
		{
			pixel_location = (y * sprite->line_size) + (x * sprite->bpp / 8);
			color = *(unsigned int*)(sprite->pixels + pixel_location);
			custom_pixel_put(data, target, x + offset_x, y + offset_y, color);
			x++;
		}
		y++;
	}
}

void	custom_pixel_put(t_data *data, t_sprite *spr, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < data->win_x && y >= 0 && y < data->win_y &&
		color != (int)0xFF000000)
	{
		dst = spr->pixels + ((y * spr->line_size) +
				(x * (spr->bpp / 8)));
		*(unsigned int *)dst = color;
	}
}
