/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 13:38:10 by zlee              #+#    #+#             */
/*   Updated: 2025/03/22 13:38:51 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list *list)
{
	t_list	*temp;

	temp = NULL;
	while (list)
	{
		ft_lstadd_back(&temp, ft_lstnew(ft_strdup(list->content)));
		list = list->next;
	}
	return (temp);
}
