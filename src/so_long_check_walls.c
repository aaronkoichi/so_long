/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_walls.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:11:55 by zlee              #+#    #+#             */
/*   Updated: 2025/03/30 23:32:07 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*Checks if the middle line of the map is a has a wall on both ends.*/
static int	check_middle_wall(char *map_line)
{
	int	check;

	check = 0;
	if (map_line[0] != '1')
		return (0);
	else
	{
		while (map_line[check])
			check++;
		if (map_line[check - 1] != '1')
			return (0);
		else
			return (1);
	}
}

/*Checks if the line has walls on both ends.*/
static int	check_first_last_wall(char *map_line)
{
	int	check;

	check = -1;
	while (map_line[++check])
		if (map_line[check] != '1')
			return (0);
	return (1);
}

/*Checks if the first/last line is a wall, then checks if the middle
line, has wall on the left/right panel*/
int	check_all_walls(t_list *map)
{
	if (!check_first_last_wall((char *)ft_lstfirst(map)->content))
		return (0);
	else
	{
		map = map->next;
		while (map->next)
		{
			if (!check_middle_wall((char *)map->content))
				return (error_exit(6));
			map = map->next;
		}
		if (!check_first_last_wall((char *)ft_lstlast(map)->content))
			return (error_exit(6));
		else
			return (1);
	}
}
