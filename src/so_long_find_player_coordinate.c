/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_find_player_coordinate.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:00:59 by zlee              #+#    #+#             */
/*   Updated: 2025/04/06 14:43:47 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Find the player's coordinate 
 * (Maybe in the future you would need a function to find all coordinates
 * of different elements).*/

void	find_player_coordinate(t_list *map, int	*x, int	*y)
{
	char	*temp_line;

	*y = 0;
	while (map)
	{
		*x = -1;
		temp_line = (char *)map->content;
		while (temp_line[++(*x)])
		{
			if (temp_line[*x] == 'P')
				return ;
		}
		map = map->next;
		(*y)++;
	}
}
