/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mlx_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:30:07 by zlee              #+#    #+#             */
/*   Updated: 2025/03/30 14:50:38 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

 int	close_win(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->textures[0].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->textures[1].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->textures[2].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->textures[3].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->textures[4].img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	data->map_data = ft_lstfirst(data->map_data);
	ft_lstclear(&(data->map_data), free);
	free(data->mlx_ptr);
	exit (0);
	return (0);
}

/* Check if the map contains any collectibles. 
 * Yes --> returns 0
 * No --> returns 1*/
static int	check_collectibles(t_list *list)
{
	int i;

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

void	movement_check(t_data *data, char *current, char *to_move)
{
	if (*to_move == 'E')
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
	else if (*to_move != '1')
	{
		*to_move = 'P';
		*current = '0';
		if (data->exit_check == 1)
		{
			*current = 'E';
			data->exit_check = 0;
		}
	}
}
