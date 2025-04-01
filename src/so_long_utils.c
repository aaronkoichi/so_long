/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:57:08 by zlee              #+#    #+#             */
/*   Updated: 2025/04/01 14:50:07 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	error_exit(int error_num)
{
	ft_putstr_fd("Error: ", 2);
	if (error_num == 1)
		ft_putstr_fd("Invalid Parameters Entered\n", 2);
	else if (error_num == 2)
		ft_putstr_fd("Invalid Map Defined\n", 2);
	else if (error_num == 3)
		ft_putstr_fd("Invalid Map Size\n", 2);
	else if (error_num == 4)
		ft_putstr_fd("Invalid Map Element Inside\n", 2);
	else if (error_num == 5)
		ft_putstr_fd("Invalid Number of Elements\n", 2);
	else if (error_num == 6)
		ft_putstr_fd("Map Not Covered With Walls\n", 2);
	else if (error_num == 7)
		ft_putstr_fd("Player Not Reachable to All Elements\n", 2);
	else if (error_num == 8)
		ft_putstr_fd("Empty Map / Map Does Not Exist\n", 2);
	return (0);
}

void	remove_new_line(t_list **map)
{
	t_list	*head;
	char	*temp_string;

	head = *map;
	while (*map)
	{
		temp_string = (char *)(*map)->content;
		if (temp_string[ft_strlen(temp_string) - 1] == '\n')
			((char *)(*map)->content)[ft_strlen(temp_string) - 1] = '\0';
		*map = (*map)->next;
	}
	*map = head;
}
