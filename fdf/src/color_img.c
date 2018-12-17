/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:58:33 by nbouchez          #+#    #+#             */
/*   Updated: 2018/12/17 16:58:34 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void color_img(void *img_ptr, int sizex, int sizey , int color)
{
	int bits_per_pixel;
	int size_line;
	int endian;
	int *image;
	int i;

	i = 0;
	image = (int*)mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);
	while(i < sizex * sizey)
	{
		*image = color;
		image++;
		i++;
	}
}