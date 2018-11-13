/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:12:09 by nbouchez          #+#    #+#             */
/*   Updated: 2018/10/06 17:12:10 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *stmp;

	stmp = (NULL);
	while (*s != '\0')
	{
		if (*s == c)
		{
			stmp = (char*)s;
		}
		s++;
	}
	if (c == '\0')
	{
		stmp = (char*)s;
	}
	return (stmp);
}
