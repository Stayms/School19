/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_iso.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 03:40:05 by nbouchez          #+#    #+#             */
/*   Updated: 2018/11/21 03:40:06 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_iso(int *map, void *mxl_ptr, void *win_ptr, int sizex, int sizey)
{
	int x;
	int y;
	int size_tuile;
	float zoom;

	zoom = 0.3;
	y = 0;
	size_tuile = (sizex > sizey ? SCREENSIZE/sizex : SCREENSIZE/sizey)*zoom;

	while(y < sizex + 1)
	{
		x = 0;
		while(x < sizey + 1)
		{
			if(y != sizey)
			{
				draw_line(((x - y) * cos(ROTATION)) * size_tuile, ((y + x) * sin(ROTATION)) * size_tuile,
				((x - (y + 1)) * cos(ROTATION)) * size_tuile, (((y + 1) + x) * sin(ROTATION)) * size_tuile,
				mxl_ptr, win_ptr);
			}
			if(x != sizex)
			{
				draw_line(((x - y) * cos(ROTATION)) * size_tuile, ((y + x) * sin(ROTATION)) * size_tuile,
				(((x + 1) - y) * cos(ROTATION)) * size_tuile, ((y + x + 1) * sin(ROTATION)) * size_tuile,
				mxl_ptr, win_ptr);
			}
			x++;
		}
		y++;
	}
}
