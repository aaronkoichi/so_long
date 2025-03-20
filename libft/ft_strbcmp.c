/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:19:29 by zlee              #+#    #+#             */
/*   Updated: 2025/03/20 16:26:40 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strbcmp(const char *s1, const char *s2, size_t n)
{
	size_t	c1;
	size_t	c2;
	size_t 	i;
	
	i = -1;
	c1 = ft_lstsize(s1);
	c2 = ft_lstsize(s2);
	while (++i < n && --c1 >= 0 && --c2 >= 0)
		if (((unsigned char)s1[c1]) - (unsigned char)s2[c2] != 0)
			return ((int)((unsigned char)s1[c1] - (unsigned char)s2[c2]));
	if (i != n)
		return ((int)((unsigned char)s1[c1] - (unsigned char)s2[c2]));
	return(0);
}