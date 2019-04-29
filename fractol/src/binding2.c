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

void	move(t_data *data, int key)
{
	if (key == 123)
	{
		data->x1 -= 30 / data->zoom;
	}
	else if (key == 124)
	{
		data->x1 += 30 / data->zoom;
	}
	else if (key == 126)
	{
		data->y1 -= 30 / data->zoom;
	}
	else if (key == 125)
	{
		data->y1 += 30 / data->zoom;
	}
}

void	tools(t_data *data, int key)
{
	if (key == 37)
	{
		data->julia_mouse = !data->julia_mouse;
	}
	if (key == 53)
		exit(EXIT_SUCCESS);
}
