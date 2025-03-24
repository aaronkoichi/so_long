/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:45:59 by zlee              #+#    #+#             */
/*   Updated: 2025/03/24 20:05:32 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int key_hook(int keysym, t_data *data)
{
	ft_printf("Keycode: %d\n", keysym);
	return (0);
}

int main(int argc, char **argv)
{
	t_data	data;
	int		fd;
	t_list	*map;

	map = NULL;
	if (argc != 2)
		exit(error_exit(1));
	fd = open(argv[1], O_RDONLY);
	if (!fd || ft_strrncmp(argv[1], ".ber", 4))
		exit(error_exit(2));
	if (process_map(fd, &map))
		mlx_start(map); //  main game loop
	if (map)
		ft_lstclear(&map, free);
	close(fd);
}
