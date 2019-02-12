/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 01:33:48 by nbouchez          #+#    #+#             */
/*   Updated: 2018/08/20 01:33:49 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	char	*tmp_;
	int		compteur;

	compteur = 0;
	tmp_ = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0' && compteur < (int)nb)
	{
		*dest = *src;
		src++;
		dest++;
		compteur++;
	}
	*dest = '\0';
	return (tmp_);
}
