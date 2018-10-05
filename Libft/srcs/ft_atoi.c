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

int		ft_atoi(char *str)
{
	int resultat;
	int index;
	int signe;

	resultat = 0;
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
	while (str[index] >= '0' && str[index] <= '9')
	{
		resultat = resultat * 10 + str[index] - '0';
		index++;
	}
	return (resultat * signe);
}
