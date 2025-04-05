/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_movement_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:03:20 by zlee              #+#    #+#             */
/*   Updated: 2025/04/06 00:10:16 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	movement_bonus_two(int keysym, t_data *data)
{
	if (keysym == XK_D)
	{
		move_right(data);
		data->dir = RIGHT;
	}
	else if (keysym == XK_ESC)
		close_win(data);
	return (0);
}

int	game_movement_bonus(int keysym, t_data *data)
{
	if (keysym == XK_W)
	{
		move_up(data);
		data->dir = UP;
	}
	else if (keysym == XK_A)
	{
		move_left(data);
		data->dir = LEFT;
	}
	else if (keysym == XK_S)
	{
		move_down(data);
		data->dir = DOWN;
	}
	else
		movement_bonus_two(keysym, data);
	return (0);
}
