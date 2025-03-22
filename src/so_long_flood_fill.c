/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_flood_fill.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:35:17 by zlee              #+#    #+#             */
/*   Updated: 2025/03/22 16:02:44 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*This is to search if the map still contains elements of P, E, or C
 * after floodfilling.*/
static int	search_anomaly(t_list *map)
{
	int		index;
	char	*temp_str;

	while (map)
	{
		index = -1;
		temp_str = (char *)map->content;
		while (temp_str[++index])
			if (temp_str[index] == 'P' || temp_str[index] == 'E'
				|| temp_str[index] == 'C')
				return (1);
		map = map->next;
	}
	return (0);
}

/*Flood Fill Algorithm*/
static void	flood_fill(t_list **map, int x, int y)
{
	int	temp_y;

	temp_y = y;
	*map = ft_lstfirst(*map);
	if (x < 0 || x >= ft_strlen((char *)(*map)->content) || y < 0
	|| y >= ft_lstsize(*map))
		return ;
	while (temp_y-- > 0)
		*map = (*map)->next;
	if (((char *)(*map)->content)[x] == '1'
		|| ((char *)(*map)->content)[x] == '2')
		return ;
	((char *)(*map)->content)[x] = '2';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

/*Act as a dummy function to return 1 or 0
 * Replace all 0, P, and E with flood fill with 2
 * Check if 0, P, and E still exists. If so, returns 0. If not, returns 1*/
int	flood_fill_main(t_list *map)
{
	t_list	*temp;
	int		x;
	int		y;

	find_player_coordinate(map, &x, &y);
	temp = ft_lstdup(map);
	flood_fill(&temp, x, y);
	temp = ft_lstfirst(temp);
	if (search_anomaly(temp))
	{
		ft_lstclear(&temp, free);
		return (0);
	}
	ft_lstclear(&temp, free);
	return (1);
}

// int main(void)
// {
// 	t_list	*test;
//
// 	test = NULL;
// 	ft_lstadd_back(&test, ft_lstnew(ft_strdup("111111111")));
// 	ft_lstadd_back(&test, ft_lstnew(ft_strdup("1P00001E1")));
// 	ft_lstadd_back(&test, ft_lstnew(ft_strdup("100100111")));
// 	ft_lstadd_back(&test, ft_lstnew(ft_strdup("100000001")));
// 	ft_lstadd_back(&test, ft_lstnew(ft_strdup("111111111")));
//
// 	flood_fill_main(test);
// 	ft_lstclear(&test, free);
// }
