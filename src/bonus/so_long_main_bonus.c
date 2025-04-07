/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:13:06 by zlee              #+#    #+#             */
/*   Updated: 2025/04/07 12:42:54 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_list	*map;

	map = NULL;
	if (argc != 2)
		exit(error_exit(1));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || ft_strrncmp(argv[1], ".ber", 4))
		exit(error_exit(2));
	if (process_map_bonus(fd, &map))
		mlx_start(map);
	if (map)
		ft_lstclear(&map, free);
	close(fd);
}
