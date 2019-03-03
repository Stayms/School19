/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 06:21:57 by nbouchez          #+#    #+#             */
/*   Updated: 2019/03/03 06:21:58 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void draw_julia(t_data *data)
{
	t_complex c;
	t_complex z;
	int i;
	double tmp;

	data->x = 0;
	while(data->x < SCREENSIZE)
	{
		data->y = 0;
		while(data->y < SCREENSIZE)
		{
			c.r = data->x / data->zoom + data->x1;
			c.i = data->y / data->zoom + data->y1;
			z.r = 0;
			z.i = 0;
			i = 0;
			while(z.r * z.r + z.i * z.i < 4 && i < data->scale)
			{
				tmp = z.r;
				z.r = z.r * z.r - z.i * z.i + c.r;
				z.i = 2 * z.i * tmp + c.i;
				i++;
			}
			if(i == data->scale)
				draw_point(data->x, data->y, data, 0);
			else
				draw_point(data->x, data->y, data, i * 255 /data->scale);
			data->y++;
		}
		data->x++;
	}
}
