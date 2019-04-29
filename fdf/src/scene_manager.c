/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <nbouchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:16:56 by nbouchez          #+#    #+#             */
/*   Updated: 2019/03/12 16:39:38 by rpousseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scene_manager(t_data *prm)
{
	void	*img_ptr;
	int		*image;
	int		bit_pxl;
	int		size_line;
	int		endian;

	img_ptr = mlx_new_image(prm->mlx_ptr, SSI, SSI);
	image = (int*)mlx_get_data_addr(img_ptr, &bit_pxl, &size_line, &endian);
	if (prm->view == 1)
		draw_iso(*prm, image);
	else
		draw_con(*prm, image);
	mlx_put_image_to_window(prm->mlx_ptr, prm->win_ptr, img_ptr, 0, 0);
	mlx_destroy_image(prm->mlx_ptr, img_ptr);
}
