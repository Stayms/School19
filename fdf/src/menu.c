/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:42:06 by nbouchez          #+#    #+#             */
/*   Updated: 2018/12/17 17:42:08 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void menu_manager(void *mlx_ptr, void *win_ptr)
{
	void	*img_ptr;

	img_ptr = mlx_new_image (mlx_ptr, SCREENSIZE/4, SCREENSIZE);
	color_img(img_ptr, SCREENSIZE/4, SCREENSIZE , HOME_COLOR);
	mlx_put_image_to_window (mlx_ptr, win_ptr, img_ptr, (SCREENSIZE/4) * 3, 0);

}
