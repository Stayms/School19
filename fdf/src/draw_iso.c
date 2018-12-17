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

void draw_iso(int *map, int *image, int sizex, int sizey)
{
	int x;
	int y;
	float size_tuile;

	y = 0;
	size_tuile = (sizex > sizey ? (float)((SCREENSIZE/4)*3)/sizex : (float)((SCREENSIZE/4)*3)/sizey)*ZOOM;
	printf("size x : %d, size y : %d - > Size tuile : %f\n", sizex, sizey, size_tuile);
	//size_tuile = (sizex > sizey ? ((SCREENSIZE/4)*3)/sizex : ((SCREENSIZE/4)*3)/sizey)*ZOOM;
	while(y < sizey)
	{
		x = 0;
		while(x < sizex)
		{
			if(y != sizey - 1)
			{
				draw_line(((x - y) * cos(ROTATION)) * size_tuile, ((y + x) * sin(ROTATION)) * size_tuile - *map * MULTIPLICATION,
				((x - (y + 1)) * cos(ROTATION)) * size_tuile, (((y + 1) + x) * sin(ROTATION)) * size_tuile - *(map + sizex) * MULTIPLICATION,
				image);
			}
			if(x != sizex - 1)
			{
				draw_line(((x - y) * cos(ROTATION)) * size_tuile, ((y + x) * sin(ROTATION)) * size_tuile - *map * MULTIPLICATION,
				(((x + 1) - y) * cos(ROTATION)) * size_tuile, ((y + x + 1) * sin(ROTATION)) * size_tuile - *(map + 1) * MULTIPLICATION,
				image);
			}
			x++;
			map++;
		}
		y++;
	}
}
