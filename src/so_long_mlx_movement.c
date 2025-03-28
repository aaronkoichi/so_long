/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mlx_movement.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 22:30:48 by zlee              #+#    #+#             */
/*   Updated: 2025/03/29 00:28:57 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_data *data)
{
	int	player_x;
	int	player_y;

	player_x = 0;
	player_y = 0;
	find_player_coordinate(data->map_data, &player_x, &player_y);
	while (--player_y >= 0)
		data->map_data = data->map_data->next;
	if (((char *)(data->map_data->prev->content))[player_x] != '1')
	{
		((char *)(data->map_data->prev->content))[player_x] = 'P';
		((char *)(data->map_data->content))[player_x] = '0';
	}
	data->map_data = ft_lstfirst(data->map_data);
	ft_printf("Moves: %d\n", data->counter);
	data->counter++;
}

void	move_down(t_data *data)
{
	int	player_x;
	int	player_y;

	player_x = 0;
	player_y = 0;
	find_player_coordinate(data->map_data, &player_x, &player_y);
	while (--player_y >= 0)
		data->map_data = data->map_data->next;
	if (((char *)(data->map_data->next->content))[player_x] != '1')
	{
		((char *)(data->map_data->next->content))[player_x] = 'P';
		((char *)(data->map_data->content))[player_x] = '0';
	}
	data->map_data = ft_lstfirst(data->map_data);
	ft_printf("Moves: %d\n", data->counter);
	data->counter++;
}

void	move_left(t_data *data)
{
	int	player_x;
	int	player_y;

	player_x = 0;
	player_y = 0;
	find_player_coordinate(data->map_data, &player_x, &player_y);
	while (--player_y >= 0)
		data->map_data = data->map_data->next;
	if (((char *)(data->map_data->content))[player_x - 1] != '1')
	{
		((char *)(data->map_data->content))[player_x - 1] = 'P';
		((char *)(data->map_data->content))[player_x] = '0';
	}
	data->map_data = ft_lstfirst(data->map_data);
	ft_printf("Moves: %d\n", data->counter);
	data->counter++;
}

void	move_right(t_data *data)
{
	int	player_x;
	int	player_y;

	player_x = 0;
	player_y = 0;
	find_player_coordinate(data->map_data, &player_x, &player_y);
	while (--player_y >= 0)
		data->map_data = data->map_data->next;
	if (((char *)(data->map_data->content))[player_x + 1] != '1')
	{
		((char *)(data->map_data->content))[player_x + 1] = 'P';
		((char *)(data->map_data->content))[player_x] = '0';
	}
	data->map_data = ft_lstfirst(data->map_data);
	ft_printf("Moves: %d\n", data->counter);
	data->counter++;
}

int	game_movement(int keysym, t_data *data)
{
	if (keysym == XK_W)
		move_up(data);
	else if (keysym == XK_A)
		move_left(data);
	else if (keysym == XK_S)
		move_down(data);
	else if (keysym == XK_D)
		move_right(data);
	else if (XK_ESC)
		close_win(data);
	return (0);
}

