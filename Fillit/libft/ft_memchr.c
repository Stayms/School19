/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 12:40:18 by nbouchez          #+#    #+#             */
/*   Updated: 2018/10/08 12:40:19 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char c2;
	unsigned char *str2;

	c2 = (unsigned char)c;
	str2 = (unsigned char*)s;
	while (n > 0)
	{
		if (*str2 == c2)
			return (str2);
		n--;
		str2++;
	}
	return (NULL);
}
