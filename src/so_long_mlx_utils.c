/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mlx_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:39:00 by zlee              #+#    #+#             */
/*   Updated: 2025/03/30 23:54:10 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	xpm_image_transparency(t_data *data, t_sprite *sprite, t_sprite *target,
				t_pos offset)
{
	int		y;
	int		x;
	int		pixel_location;
	int		color;
	t_pos	temp;

	y = 0;
	while (y < MUL)
	{
		x = 0;
		while (x < MUL)
		{
			pixel_location = (y * sprite->line_size) + (x * sprite->bpp / 8);
			color = *(unsigned int *)(sprite->pixels + pixel_location);
			temp.x = x + offset.x;
			temp.y = y + offset.y;
			custom_pixel_put(data, target, temp, color);
			x++;
		}
		y++;
	}
}

void	custom_pixel_put(t_data *data, t_sprite *spr, t_pos pos, int color)
{
	char	*dst;

	if (pos.x >= 0 && pos.y < data->win_x && pos.y >= 0 && pos.y < data->win_y
		&& color != (int)0xFF000000)
	{
		dst = spr->pixels + ((pos.y * spr->line_size)
				+ (pos.x * (spr->bpp / 8)));
		*(unsigned int *)dst = color;
	}
}
