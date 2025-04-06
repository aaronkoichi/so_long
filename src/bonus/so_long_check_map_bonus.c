/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_map_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:15:07 by zlee              #+#    #+#             */
/*   Updated: 2025/04/06 14:44:17 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_valid_bonus(t_list *map)
{
	int		i;
	char	*temp;

	while (map)
	{
		i = -1;
		temp = (char *)map->content;
		while (temp[++i])
			if (!(temp[i] == '0' || temp[i] == '1' || temp[i] == 'C'
					|| temp[i] == 'N' || temp[i] == 'E' || temp[i] == 'P'))
				return (error_exit(4));
		map = map->next;
	}
	return (1);
}

/*Checks all conditions at once.*/
static int	check_all_conditions(t_list *map)
{
	if (!map)
		return (error_exit(8));
	if (!check_lines(map) || !check_valid_bonus(map)
		|| !check_map_parameters(map) || !check_all_walls(map)
		|| !flood_fill_main(map))
		return (0);
	else
		return (1);
}

/*Process the map file based on the .ber file inputed.
 - returns 1 if the map is ready to be processed;
  - returns 0 if the map has a major error. */
int	process_map_bonus(int fd, t_list **map)
{
	char	*string;

	string = get_next_line(fd);
	while (string)
	{
		ft_lstadd_back(map, ft_lstnew(string));
		string = get_next_line(fd);
	}
	remove_new_line(map);
	if (!check_all_conditions(*map))
		return (0);
	else
		return (1);
}
