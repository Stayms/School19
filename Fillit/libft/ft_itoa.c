/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 16:52:18 by nbouchez          #+#    #+#             */
/*   Updated: 2018/10/08 16:52:19 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		count_size_itoa(int nbr)
{
	int	size;

	size = 0;
	if (nbr < 0)
		size++;
	while (nbr > 9 || nbr < -9)
	{
		nbr = nbr / 10;
		size++;
	}
	size++;
	return (size);
}

extern	char	*ft_itoa(int nbr)
{
	char	*start;
	int		size;
	long	nbr_tmp;
	int		index;

	nbr_tmp = (long)nbr;
	size = count_size_itoa(nbr);
	index = size;
	if ((start = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	start[index] = '\0';
	index--;
	if (nbr_tmp < 0)
	{
		nbr_tmp = -nbr_tmp;
		start[0] = '-';
	}
	while (nbr_tmp > 9)
	{
		start[index] = (nbr_tmp % 10) + '0';
		nbr_tmp = nbr_tmp / 10;
		index--;
	}
	start[index] = nbr_tmp + '0';
	return (start);
}
