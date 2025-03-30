/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_map_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:48:15 by zlee              #+#    #+#             */
/*   Updated: 2025/03/30 23:29:31 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*Checks if the map has one exit/player, and at least one collectible*/
static void	check_map_parameters_line(char *map_line, int *col_count,
								int *e_count, int *p_count)
{
	int	c;

	c = -1;
	while (map_line[++c])
	{
		if (map_line[c] == 'C')
			(*col_count)++;
		else if (map_line[c] == 'E')
			(*e_count)++;
		else if (map_line[c] == 'P')
			(*p_count)++;
	}
}

int	check_map_parameters(t_list *map)
{
	int	col_count;
	int	e_count;
	int	p_count;

	col_count = 0;
	e_count = 0;
	p_count = 0;
	while (map)
	{
		check_map_parameters_line((char *)map->content, &col_count,
			&e_count, &p_count);
		map = map->next;
	}
	if (p_count != 1 || e_count != 1 || col_count < 1)
		return (error_exit(5));
	else
		return (1);
}
