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

#include <stdlib.h>

static	int		ft_strlen(char *str)
{
	int count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

static	char	*ft_strcpy(char *dest, char *src)
{
	char *dest_tmp;

	dest_tmp = dest;
	while (*src != '\0')
	{
		*dest_tmp = *src;
		dest_tmp++;
		src++;
	}
	*dest_tmp = *src;
	return (dest);
}

extern	char	*ft_strdup(char *src)
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
