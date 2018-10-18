/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 17:43:24 by nbouchez          #+#    #+#             */
/*   Updated: 2018/10/04 18:49:35 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*c1;
	char	*c2;

	if (n == 0 || dest == src)
		return (dest);
	c1 = (char *)dest;
	c2 = (char *)src;
	n--;
	while (n)
	{
		*c1 = *c2;
		c1++;
		c2++;
		n--;
	}
	*c1 = *c2;
	return (dest);
}
