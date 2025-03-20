/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:57:08 by zlee              #+#    #+#             */
/*   Updated: 2025/03/20 13:59:30 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	error_exit(int error_num)
{
	if (error_num == 1)
		ft_putstr_fd("Error: invalid parameters entered.\n", 2);
	return (EXIT_FAILURE);
}
