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

#include "fractol.h"

void scene_manager(t_data *data)
{
	void	*img_ptr;
	int		*image;
	int 	bits_per_pixel;
	int 	size_line;
	int 	endian;

	img_ptr = mlx_new_image (data->mlx_ptr, SCREENSIZE, SCREENSIZE);
	data->map = (int*)mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);

	// Modification de l'image
	draw_mandelbrot(data);

	// Put de l'image dans la fenetre
	mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, img_ptr, 0, 0);
}