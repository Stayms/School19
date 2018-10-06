/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 11:39:32 by nbouchez          #+#    #+#             */
/*   Updated: 2018/08/16 11:39:34 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	part1_atoi(int *pindex, int *psigne, char *str)
{
	int index;
	int signe;

	index = 0;
	signe = 1;
	while (str[index] == '\t' || str[index] == '\n' || str[index] == '\r' ||
	str[index] == '\v' || str[index] == '\f' || str[index] == ' ')
	{
		index++;
	}
	if (str[index] == '-')
	{
		signe = -1;
		index++;
	}
	if (str[index] == '+')
		index++;
	*pindex = index;
	*psigne = signe;
}

extern	int		ft_atoi(char *str)
{
	unsigned int	resultat;
	int				index;
	int				signe;

	resultat = 0;
	index = 0;
	signe = 1;
	part1_atoi(&index, &signe, str);
	while (str[index] >= '0' && str[index] <= '9')
	{
		resultat = resultat * 10 + str[index] - '0';
		index++;
		if ((resultat > 2147483647 && signe == 1) ||
			(resultat > 2147483648 && signe == -1))
		{
			if (signe == -1)
				return (0);
			return (-1);
		}
	}
	return (resultat * signe);
}
