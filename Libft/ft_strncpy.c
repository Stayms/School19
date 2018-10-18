/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 13:37:44 by nbouchez          #+#    #+#             */
/*   Updated: 2018/08/16 13:37:45 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char *dest_tmp;

	dest_tmp = dest;
	while (*src != '\0' && n > 0)
	{
		*dest_tmp = *src;
		dest_tmp++;
		src++;
		n--;
	}
	while (n > 0)
	{
		*dest_tmp = '\0';
		dest_tmp++;
		n--;
	}
	return (dest);
}
