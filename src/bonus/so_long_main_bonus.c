/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:13:06 by zlee              #+#    #+#             */
/*   Updated: 2025/04/01 14:42:07 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_list	*map;

	map = NULL;
	if (argc != 2)
		exit(error_exit(1));
	fd = open(argv[1], O_RDONLY);
	if (!fd || ft_strrncmp(argv[1], ".ber", 4))
		exit(error_exit(2));
	if (process_map(fd, &map))
		mlx_start(map);
	if (map)
		ft_lstclear(&map, free);
	close(fd);
}
