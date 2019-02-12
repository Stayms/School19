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

	int interation_max = 50;
	double x_min = -2.1;
	double x_max = 0.6;
	double y_min = -1.2;
	double y_max = 1.2;
	double zoom = 100;

	double image_x = (x_max - x_min) * zoom;
	double image_y = (y_max - y_min) * zoom;

	y = 0;
	while(y < image_y)
	{
		x = 0;
		while(x < image_x)
		{
			c.r = x / zoom + x_min;
			c.i = y / zoom + y_min;
			z.r = 0;
			z.i = 0;
			i = 0;

			while(z.r * z.r + z.i * z.i < 4 && i < interation_max)
			{
				tmp = z.r;
				z.r = z.r * z.r - z.i * z.i + c.r;
				z.i = 2 * z.i * tmp + c.i;
				i++;
			}
			if(i == interation_max)
			{
				draw_point(x, y, data);
			}

			x++;
		}
		y++;
	}
}
