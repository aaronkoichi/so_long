/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game_handling_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:16:26 by zlee              #+#    #+#             */
/*   Updated: 2025/04/06 15:39:56 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Check if the map contains any collectibles. 
 * Yes --> returns 0
 * No --> returns 1*/
static int	check_collectibles(t_list *list)
{
	int	i;

	list = ft_lstfirst(list);
	while (list)
	{
		i = -1;
		while (((char *)list->content)[++i])
			if (((char *)list->content)[i] == 'C')
				return (0);
		list = list->next;
	}
	return (1);
}

static void	handle_exit(t_data *data, char *current, char *to_move)
{
	if (check_collectibles(data->map_data))
		close_win(data);
	else
	{
		data->exit_check = 1;
		if (*to_move != '1')
		{
			*to_move = 'P';
			*current = '0';
		}
	}
}

static void	handle_movement(t_data *data, char *current, char *to_move)
{
	*to_move = 'P';
	*current = '0';
	if (data->exit_check == 1)
	{
		*current = 'E';
		data->exit_check = 0;
	}
}

void	movement_check(t_data *data, char *current, char *to_move)
{
	if (*to_move == 'E')
		handle_exit(data, current, to_move);
	else if (*to_move == 'N')
	{
		ft_printf("Game Over! You Touched An Enemy Patrol!\n");
		close_win(data);
	}
	else if (*to_move != '1')
		handle_movement(data, current, to_move);
}
