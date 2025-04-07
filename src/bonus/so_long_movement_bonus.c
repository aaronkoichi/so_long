/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_movement_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:03:20 by zlee              #+#    #+#             */
/*   Updated: 2025/04/07 15:19:05 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	movement_bonus_two(int keysym, t_data *data)
{
	if (keysym == XK_d)
	{
		move_right(data);
		data->dir = RIGHT;
	}
	else if (keysym == XK_Escape)
		close_win(data);
	return (0);
}

int	game_movement_bonus(int keysym, t_data *data)
{
	if (keysym == XK_w)
	{
		move_up(data);
		data->dir = UP;
	}
	else if (keysym == XK_a)
	{
		move_left(data);
		data->dir = LEFT;
	}
	else if (keysym == XK_s)
	{
		move_down(data);
		data->dir = DOWN;
	}
	else
		movement_bonus_two(keysym, data);
	return (0);
}
