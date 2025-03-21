/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_flood_fill.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:35:17 by zlee              #+#    #+#             */
/*   Updated: 2025/03/21 17:05:33 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*Act as a dummy function to return 1 or 0
 * Replace all 0, P, and E with flood fill with 2
 * Check if 0, P, and E still exists. If so, returns 0. If not, returns 1*/
int	flood_fill_main(t_list *map)
{
	t_list	*temp;

	temp = map;
	flood_fill(&temp, 0, 0);
	return (0);
}

/*Flood Fill Algorithm*/
void	flood_fill(t_list **map, int x, int y)
{
	*map = ft_lstfirst(*map);
	if (x < 0 || x > ft_strlen((char *)(*map)->content) || y < 0
	|| y > ft_lstsize(*map))
		return ;

	while (y > 0)
		*map = (*map)->next;
	if (((char *)(*map)->content)[x] == '1')
		return ;
	((char *)(*map)->content)[x] = '2';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}
