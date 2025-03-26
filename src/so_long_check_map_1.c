/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_map_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:30:16 by zlee              #+#    #+#             */
/*   Updated: 2025/03/26 15:11:24 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*Checks all conditions at once.*/
int	check_all_conditions(t_list *map)
{
	if (!map)
		return(error_exit(8));
	if (!check_lines(map) || !check_valid(map) || !check_map_parameters(map)
		|| !check_all_walls(map) || !flood_fill_main(map))
		return (0);
	else
		return (1);
}

/*Checks if each line contains the correct defined character.*/
int	check_valid(t_list *map)
{
	int		i;
	char	*temp;
	
	while (map)
	{
		i = -1;
		temp = (char *)map->content;
		while (temp[++i])
			if (!(temp[i] == '0' || temp[i] == '1' || temp[i] == 'C'
				|| temp[i] == 'E' || temp[i] == 'P'))
				return (error_exit(4));
		map = map->next;
	}
	return (1);
}
/*Checks if the map structure is a rectangle/square or otherwise..*/
int	check_lines(t_list *map)
{
	int	count;

	count = 0;
	count = ft_strlen((char *)map->content);
	map = map->next;
	while (map)
	{
		if (count != ft_strlen((char *)map->content))
			return (error_exit(3));
		map = map->next;
	}
	return (1);	
}
/*Process the map file based on the .ber file inputed.
 - returns 1 if the map is ready to be processed;
  - returns 0 if the map has a major error. */
int	process_map(int fd, t_list **map)
{
	char	*string;
	int		size;

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
