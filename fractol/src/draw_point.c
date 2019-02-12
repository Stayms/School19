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

int draw_point(int x, int y, t_data *data)
{
	int offset;
	int *img_tmp;
 
 	offset = x + y * SCREENSIZE;

 	img_tmp = data->map + offset;
 	*img_tmp = 255;
	return (0);
}
