/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:16:56 by nbouchez          #+#    #+#             */
/*   Updated: 2018/12/17 18:16:57 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_value_mandelbrot(t_data *data)
{
	data->scale = 150;
	data->x1 = -2.05;
	data->y1 = -1.3;
	data->zoom = 200;
	data->color = 255;
}

void	set_value_julia(t_data *data)
{
	data->scale = 80;
	data->x1 = -2.0;
	data->y1 = -1.9;
	data->zoom = 200;
	data->color = 255;
	data->c.r = 0.285;
	data->c.i = 0.01;
	data->julia_mouse = 1;
}

void	scene_manager(t_data *data)
{
	if (data->id == 1)
		draw_mandelbrot(data);
	else if (data->id == 2)
		draw_julia(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}
