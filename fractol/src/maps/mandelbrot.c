/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:49:30 by nbouchez          #+#    #+#             */
/*   Updated: 2019/02/12 16:49:31 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void draw_mandelbrot(t_data *data)
{
	int x;
	int y;
	t_complex c;
	t_complex z;
	int i;
	double tmp;

	y = 0;
	while(y < SCREENSIZE)
	{
		x = 0;
		while(x < SCREENSIZE)
		{
			c.r = (x + data->map.offset_x) / data->map.zoom_x + data->map.x_min;
			c.i = (y + data->map.offset_y) / data->map.zoom_y + data->map.y_min;
			z.r = 0;
			z.i = 0;
			i = 0;

			while(z.r * z.r + z.i * z.i < 4 && i < data->map.scale)
			{
				tmp = z.r;
				z.r = z.r * z.r - z.i * z.i + c.r;
				z.i = 2 * z.i * tmp + c.i;
				i++;
			}
			if(i == data->map.scale)
				draw_point(x, y, data, 0);
			else
				draw_point(x, y, data, i * 255/data->map.scale);
			x = x + 1 / data->map.quality;
		}
		y = y + 1 / data->map.quality;
	}
}
