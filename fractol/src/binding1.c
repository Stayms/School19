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

void zoomin(t_data *data, int x, int y)
{
	data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom * 1.3));
	data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom * 1.3));
	data->zoom *= 1.3;
}

void zoomout(t_data *data, int x, int y)
{
	data->x1 = (x / data->zoom + data->x1)  - (x / (data->zoom / 1.3));
	data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom / 1.3));
	data->zoom /= 1.3;
}

void scalein(t_data *data)
{
	data->scale += 5;
}

void scaleout(t_data *data)
{
	data->scale -= 5;
}

int	mouse_hook(int mousecode, int x, int y, t_data *data)
{
	if (mousecode == 4 || mousecode == 1)
		zoomout(data, x, y);
	else if (mousecode == 5 || mousecode == 2)
		zoomin(data, x, y);
	scene_manager(data);
	return (0);
}
