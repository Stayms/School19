/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <nbouchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 01:28:46 by nbouchez          #+#    #+#             */
/*   Updated: 2019/03/12 14:25:04 by rpousseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>

void	init_drawl(t_drawl *draw, t_arg arg)
{
	draw->dx = abs(arg.x1 - arg.x0);
	draw->sx = arg.x0 < arg.x1 ? 1 : -1;
	draw->dy = abs(arg.y1 - arg.y0);
	draw->sy = arg.y0 < arg.y1 ? 1 : -1;
	draw->err = (draw->dx > draw->dy ? draw->dx : -draw->dy) / 2;
}

void	draw_line(t_arg arg, int *img)
{
	t_drawl draw;

	init_drawl(&draw, arg);
	while (19)
	{
		if (arg.x0 + PADX < SSI && arg.x0 + PADX > 0)
			if ((arg.y0 + PADY) * SSI < SSI * SSI && arg.y0 + PADY > 0)
			{
				draw.img_tmp = img + (arg.x0 + PADX) + ((arg.y0 + PADY) * SSI);
				*draw.img_tmp = 255;
			}
		if (arg.x0 == arg.x1 && arg.y0 == arg.y1)
			break ;
		draw.e2 = draw.err;
		if (draw.e2 > -draw.dx)
		{
			draw.err -= draw.dy;
			arg.x0 += draw.sx;
		}
		if (draw.e2 < draw.dy)
		{
			draw.err += draw.dx;
			arg.y0 += draw.sy;
		}
	}
}
