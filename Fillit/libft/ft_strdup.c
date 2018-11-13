/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 00:01:03 by nbouchez          #+#    #+#             */
/*   Updated: 2018/08/22 00:01:04 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*pc;
	int		size;

	size = ft_strlen(src);
	pc = (char *)malloc(size + 1);
	if (pc == NULL)
		return (NULL);
	ft_strcpy(pc, src);
	return (pc);
}
