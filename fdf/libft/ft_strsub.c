/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:13:00 by nbouchez          #+#    #+#             */
/*   Updated: 2018/10/08 18:13:01 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *sc;
	char *result;

	result = ((char*)NULL);
	if (s)
	{
		sc = (char *)(s + start);
		result = (char *)malloc(sizeof(char) * (len + 1));
		if (result == NULL)
			return (NULL);
		ft_strncpy(result, sc, len);
		result[len] = '\0';
	}
	return (result);
}
