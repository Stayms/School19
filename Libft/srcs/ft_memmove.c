/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 19:30:33 by nbouchez          #+#    #+#             */
/*   Updated: 2018/10/04 19:30:34 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	char *src_malloc;

	if(n ==0)
	{

	}
	src_malloc = (char*)malloc(sizeof(ft_strlen((char*)src)));

	return (dest);
}
