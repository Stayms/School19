/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 01:28:46 by nbouchez          #+#    #+#             */
/*   Updated: 2018/11/21 01:28:47 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>

int draw_line(int x0, int y0, int x1, int y1, int *image)
{
	int dx;
	int sx;
	int dy;
	int sy;
	int err;
	int e2;
	int *img_tmp;

	dx = abs(x1 - x0);
	sx = x0 < x1 ? 1 : -1;
	dy = abs(y1 - y0);
	sy = y0<y1 ? 1 : -1; 
	err = (dx > dy ? dx : -dy)/2;
 
	while(1)
	{
		img_tmp = image + (x0 + PADDINGX) + ((y0 + PADDINGY) * (SCREENSIZE/4)*3);
		*img_tmp = 255;
		//mlx_pixel_put(mxl_ptr, win_ptr, x0 + PADDINGX, y0 + PADDINGY, 16777215);
		//printf("Point : %d, %d\n", x0, y0);
		if (x0 == x1 && y0 == y1) 
			break;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
	}
	return (0);
}
