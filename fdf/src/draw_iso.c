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

void draw_iso(int *map, void *mxl_ptr, void *win_ptr)
{
	int x;
	int y;
	int i;
	int size_tuile;
	int originx;
	int originy;

	originx = 20;
	originy = 20;
	i = 0;
	x = 0;
	y = 0;
	size_tuile = 100;


	while(y < 4)
	{
		x = 0;
		while(x < 4)
		{
			if (y == 3)
				draw_line(originx + x * size_tuile, originy + (y + 1) * size_tuile, originx + (x + 1) * size_tuile, originy + (y + 1) * size_tuile, mxl_ptr, win_ptr);
			draw_line(originx + x * size_tuile, originy + y * size_tuile, originx + (x + 1) * size_tuile, originy + y * size_tuile, mxl_ptr, win_ptr);
			draw_line(originx + x * size_tuile, originy + y * size_tuile, originx + x * size_tuile, originy + (y + 1) * size_tuile, mxl_ptr, win_ptr);
			x++;
		}
		draw_line(originx + x * size_tuile, originy + y * size_tuile, originx + x * size_tuile, originy + (y + 1) * size_tuile, mxl_ptr, win_ptr);
		y++;
	}
}

void draw_all_lines()
{





}