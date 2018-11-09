/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 19:21:11 by nbouchez          #+#    #+#             */
/*   Updated: 2018/10/06 19:21:12 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char		*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	char	*to_find_tmp;
	char	*str_tmp;
	long	n2;
	int		n2_tmp;

	n2 = (long)n;
	to_find_tmp = (char*)to_find;
	while (*str != '\0' && n2 >= 0)
	{
		str_tmp = (char*)str;
		to_find_tmp = (char*)to_find;
		n2_tmp = 0;
		while ((*to_find_tmp == *str_tmp || *to_find_tmp == '\0') && n2 >= 0)
		{
			if (*to_find_tmp == '\0')
				return ((char*)str);
			to_find_tmp++;
			str_tmp++;
			n2--;
			n2_tmp++;
		}
		n2 = n2 + n2_tmp - 1;
		str++;
	}
	return ((void*)0);
}
