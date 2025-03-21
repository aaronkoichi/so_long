/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_map_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:48:15 by zlee              #+#    #+#             */
/*   Updated: 2025/03/21 16:06:15 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"



int check_map_parameters(t_list *map)
{
	while (map)
	{
		if (!check_map_parameters_line((char *)map->content))
			return (0);
		map = map->next;
	}
	return (0);
}

/*Checks if the map has one exit/player, and at least one collectible*/
int	check_map_parameters_line(char *map_line)
{
	int	col_count;
	int	e_count;
	int	p_count;
	int	c;

	col_count = 0;
	e_count = 0;
	p_count = 0;
	c = -1;
	while (map_line[++c])
	{
		if (map_line[c] == 'C')
			col_count++;
		else if (map_line[c] == 'E')
			e_count++;
		else if (map_line[c] == 'P')
			p_count++;
	}
	if (p_count != 1 || e_count != 1 || col_count < 1)
		return (0);
	else
		return (1);
}
