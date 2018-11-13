/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 13:48:15 by nbouchez          #+#    #+#             */
/*   Updated: 2018/10/08 13:48:16 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char *pstr1;
	unsigned char *pstr2;

	pstr1 = (unsigned char*)str1;
	pstr2 = (unsigned char*)str2;
	while (n > 0)
	{
		if (*pstr1 < *pstr2 || *pstr1 > *pstr2)
		{
			return (*pstr1 - *pstr2);
		}
		pstr1++;
		pstr2++;
		n--;
	}
	return (0);
}
