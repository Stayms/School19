/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 20:55:59 by nbouchez          #+#    #+#             */
/*   Updated: 2018/10/06 20:56:00 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *pc;

	pc = ft_memalloc(size + 1);
	if (pc != NULL)
		ft_bzero(pc, size + 1);
	return (pc);
}
