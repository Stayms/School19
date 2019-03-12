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

int		julia_mouse(int x, int y, t_data *data)
{
	if (data->id == 2 && data->julia_mouse == 1)
	{
		data->c.r = x * 2;
		data->c.i = y * 2 - 800;
		scene_manager(data);
	}
	return (0);
}

void	draw_julia2(t_data *data, int i)
{
	double	tmp;

	data->z.r = data->x / data->zoom + data->x1;
	data->z.i = data->y / data->zoom + data->y1;
	i = 0;
	while (data->z.r * data->z.r + data->z.i * data->z.i < 4 && i < data->scale)
	{
		tmp = data->z.r;
		data->z.r = data->z.r * data->z.r -
		data->z.i * data->z.i - 0.8 + (data->c.r / SCREENSIZE);
		data->z.i = 2 * data->z.i * tmp + data->c.i / SCREENSIZE;
		i++;
	}
	if (i == data->scale)
		draw_point(data->x, data->y, data, 0);
	else
		draw_point(data->x, data->y, data, i * 255);
}

void	draw_julia(t_data *data)
{
	int i;

	data->x = 0;
	while (data->x < SCREENSIZE)
	{
		data->y = 0;
		while (data->y < SCREENSIZE)
		{
			draw_julia2(data, i);
			data->y++;
		}
		data->x++;
	}
}
