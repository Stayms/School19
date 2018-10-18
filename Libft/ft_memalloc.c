/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 20:35:46 by nbouchez          #+#    #+#             */
/*   Updated: 2018/10/06 20:35:47 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *pv;

	pv = (void *)malloc(size);
	if (pv == (void *)NULL)
		return (pv);
	ft_bzero(pv, size);
	return (pv);
}
