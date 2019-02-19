/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:36:27 by nbouchez          #+#    #+#             */
/*   Updated: 2019/02/12 17:36:28 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int draw_point(int x, int y, t_data *data, int color)
{
	int offset;
	int *img_tmp;
	int pixel_point;
	int i;
	int j;

	pixel_point = (int)1 / data->map.quality;
	//printf("%d\n", pixel_point);
 	offset = x + y * SCREENSIZE;
 	i = 0;
 	while(i < pixel_point)
 	{
 		j = 0;
 		while(j < pixel_point)
 		{
 			if(offset + j + i * SCREENSIZE < SCREENSIZE * SCREENSIZE - 1)
 			{
 				img_tmp = data->map.map + offset + j + i * SCREENSIZE;
 				*img_tmp = color;
			}
			j++;
 		}
		i++;
 	}
	return (0);
}
