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

void	draw_mandelbrot2(t_data *data, t_complex c, t_complex z, int i)
{
	double		tmp;

	c.r = data->x / data->zoom + data->x1;
	c.i = data->y / data->zoom + data->y1;
	z.r = 0;
	z.i = 0;
	i = 0;
	while (z.r * z.r + z.i * z.i < 4 && i < data->scale)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * tmp + c.i;
		i++;
	}
	if (i == data->scale)
		draw_point(data->x, data->y, data, 0);
	else
		draw_point(data->x, data->y, data, i * 255 / data->scale);
}

void	draw_mandelbrot(t_data *data)
{
	t_complex	c;
	t_complex	z;
	int			i;

	data->x = 0;
	while (data->x < SCREENSIZE)
	{
		data->y = 0;
		while (data->y < SCREENSIZE)
		{
			draw_mandelbrot2(data, c, z, i);
			data->y++;
		}
		data->x++;
	}
}
