/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:46:23 by zlee              #+#    #+#             */
/*   Updated: 2025/03/24 19:32:59 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>

# define XK_W 119
# define XK_A 97
# define XK_S 115
# define XK_D 100

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

int		error_exit(int error_num);
/*maps - walls*/
int		check_all_walls(t_list *map);
/*Check valid input*/
int		check_valid(t_list *map);
int		check_lines(t_list *map);
int		process_map(int fd, t_list **map);
/*Check map items*/
int 	check_map_parameters(t_list *map);
/*Flood Fill*/
int		flood_fill_main(t_list *map);
void	find_player_coordinate(t_list *map, int	*x, int	*y);
#endif
