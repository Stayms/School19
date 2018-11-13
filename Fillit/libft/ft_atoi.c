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

static	void	part1_atoi(int *pindex, int *psigne, const char *str)
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
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index + 1] < '0' || str[index + 1] > '9')
			str = (NULL);
		else if (str[index] == '-')
			signe = -1;
		index++;
	}
	*pindex = index;
	*psigne = signe;
}

extern	int		ft_atoi(const char *str)
{
	unsigned	long	long	int	resultat;
	int								index;
	int								signe;

	resultat = 0;
	index = 0;
	signe = 1;
	part1_atoi(&index, &signe, str);
	if (str == NULL)
		return (0);
	while (str[index] >= '0' && str[index] <= '9')
	{
		resultat = resultat * 10 + str[index] - '0';
		index++;
		if ((resultat > 9223372036854775807 && signe == 1) ||
			(resultat > 9223372036854775807 && signe == -1))
		{
			if (signe == -1)
				return (0);
			return (-1);
		}
	}
	return (resultat * signe);
}
