/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:36:35 by zlee              #+#    #+#             */
/*   Updated: 2025/04/05 20:30:53 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_numbers(t_data *mlx)
{
	t_pos	p;

	p.x = 16;
	p.y = 32;
	mlx->numbers[0] = create_sprite("./textures/numbers/digit_0.xpm", 
		mlx->mlx_ptr, p);
	mlx->numbers[1] = create_sprite("./textures/numbers/digit_1.xpm",
		mlx->mlx_ptr, p);
	mlx->numbers[2] = create_sprite("./textures/numbers/digit_2.xpm",
		mlx->mlx_ptr, p);
	mlx->numbers[3] = create_sprite("./textures/numbers/digit_3.xpm",
		mlx->mlx_ptr, p);
	mlx->numbers[4] = create_sprite("./textures/numbers/digit_4.xpm",
		mlx->mlx_ptr, p);
	mlx->numbers[5] = create_sprite("./textures/numbers/digit_5.xpm",
		mlx->mlx_ptr, p);
	mlx->numbers[6] = create_sprite("./textures/numbers/digit_6.xpm",
		mlx->mlx_ptr, p);
	mlx->numbers[7] = create_sprite("./textures/numbers/digit_7.xpm",
		mlx->mlx_ptr, p);
	mlx->numbers[8] = create_sprite("./textures/numbers/digit_8.xpm",
		mlx->mlx_ptr, p);
	mlx->numbers[9] = create_sprite("./textures/numbers/digit_9.xpm",
		mlx->mlx_ptr, p);
}

void	process_number(t_data *mlx)
{
	char	*text;
	t_pos	pos;
	int		i;

	i = -1;
	pos.x = 10;
	pos.y = 10;
	text = ft_itoa(mlx->counter);
	while (text[++i])
	{
		xpm_image_transparency(mlx, &mlx->numbers[text[i] - '0'],
				&mlx->d_img, pos);
		pos.x += 17;
	}
	free(text);
}
