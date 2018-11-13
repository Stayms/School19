/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:29:51 by nbouchez          #+#    #+#             */
/*   Updated: 2018/10/08 18:29:52 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *sc1;
	char *sc2;
	char *result;

	result = ((char *)NULL);
	if (s1 && s2)
	{
		sc1 = (char *)s1;
		sc2 = (char *)s2;
		result = (char *)malloc(sizeof(char) *
			(ft_strlen(sc1) + ft_strlen(sc2) + 1));
		if (result == NULL)
			return (NULL);
		ft_strcpy(result, sc1);
		ft_strcat(result, sc2);
	}
	return (result);
}
