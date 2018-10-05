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
	char *tmpdest;
	char *tmpsrc;

	if (n == 0 || dest == src)
		return (dest);
	tmpsrc = (char*)src;
	tmpdest = (char*)dest;
	while (*tmpsrc != '\0' && n > 0)
	{
		*tmpdest = *tmpsrc;
		tmpsrc++;
		tmpDest++;
		n--;
	}
	return (dest);
}
