/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:16:56 by nbouchez          #+#    #+#             */
/*   Updated: 2018/12/17 18:16:57 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void scene_manager(void *mlx_ptr, void *win_ptr, int *map, int x, int y)
{
	void	*img_ptr;
	int		*image;
	int 	bits_per_pixel;
	int 	size_line;
	int 	endian;

	img_ptr = mlx_new_image (mlx_ptr, (SCREENSIZE/4)*3, SCREENSIZE);
	//color_img(img_ptr, (SCREENSIZE/4)*3, SCREENSIZE , 10);

	image = (int*)mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);

	draw_iso(map, image, x, y);
	mlx_put_image_to_window (mlx_ptr, win_ptr, img_ptr, SCREENSIZE/4, 0);


}