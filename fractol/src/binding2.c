/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binding2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:29:57 by nbouchez          #+#    #+#             */
/*   Updated: 2019/02/19 15:29:58 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void move(t_data *data, int key)
{
	if(key == 123) // Gauche
	{
		data->x1 -= 30 / data->zoom;
	}
	else if(key == 124) // Droite
	{
		data->x1 += 30 / data->zoom;
	}
	else if(key == 126) // Haut
	{
		data->y1 -= 30 / data->zoom;
	}
	else if(key == 125) // Bas
	{
		data->y1 += 30 / data->zoom;
	}
}
