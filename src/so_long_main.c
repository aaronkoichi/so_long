/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:45:59 by zlee              #+#    #+#             */
/*   Updated: 2025/03/20 17:10:19 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int key_hook(int keysym, t_data *data)
{
	ft_printf("Keycode: %d\n", keysym);
	return (0);
}

void	process_map(int fd)
{
	char	*string;

	string = get_next_line(fd);
}

int main(int argc, char **argv)
{
	t_data	data;
	int		fd;

	if (argc != 2)
		exit(error_exit(1));
	fd = open(argv[1], O_RDONLY);
	if (!fd || ft_strbcmp(argv[1], ".ber", 4))
		exit(error_exit(2));
	process_map(fd);
	close(fd);
}
