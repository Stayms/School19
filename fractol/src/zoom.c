/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:02:13 by nbouchez          #+#    #+#             */
/*   Updated: 2019/02/12 19:02:14 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void zoomin(t_data *data)
{
	data->map.scale += 0.5;
	//data->map.zoom += 0.6;
	data->map.x_min = data->map.x_min + 0.05;
	data->map.x_max = data->map.x_max - 0.05;
	data->map.y_min = data->map.y_min + 0.05;
	data->map.y_max = data->map.y_max - 0.05;
	data->map.image_x = 270 * data->map.zoom;
	data->map.image_y = 240 * data->map.zoom;
	data->map.zoom_x = data->map.image_x/(data->map.x_max - data->map.x_min);
	data->map.zoom_y = data->map.image_y/(data->map.y_max - data->map.y_min);
	printf("ZoomIn : %f\n", data->map.scale);
}

void zoomout(t_data *data)
{
	data->map.scale -= 0.5;
	data->map.x_min -= 0.05;
	data->map.x_max += 0.05;
	data->map.y_min -= 0.05;
	data->map.y_max += 0.05;
	data->map.image_x = 270 * data->map.zoom;
	data->map.image_y = 240 * data->map.zoom;
	data->map.zoom_x = data->map.image_x/(data->map.x_max - data->map.x_min);
	data->map.zoom_y = data->map.image_y/(data->map.y_max - data->map.y_min);
	printf("ZoomOut %f\n", data->map.scale);
}

void offset(t_data *data)
{

}