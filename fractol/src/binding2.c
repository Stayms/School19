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
		data->map.offset_x -= 50;
	}
	else if(key == 124) // Droite
	{
		data->map.offset_x += 50;
	}
	else if(key == 126) // Haut
	{
		data->map.offset_y -= 50;
	}
	else if(key == 125) // Bas
	{
		data->map.offset_y += 50;
	}
}

void quality_change(t_data *data)
{

	if(data->map.quality == 0.5)
		data->map.quality = 1;
	else
		data->map.quality = 0.5;
	printf("%f\n", data->map.quality);
}
