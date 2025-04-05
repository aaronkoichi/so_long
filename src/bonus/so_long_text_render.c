/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_text_render.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:55:14 by zlee              #+#    #+#             */
/*   Updated: 2025/04/05 18:06:21 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	prep_string(t_data *mlx)
{
	char	*string_one;
	char	*string_two;
	char	*temp;

	string_one = ft_strdup("Moves: ");
	string_two = ft_itoa(mlx->counter);
	temp = ft_strjoin(string_one, string_two);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 10, 0x000000, temp);
	free(string_one);
	free(string_two);
	free(temp);
}
