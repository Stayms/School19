/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 22:34:54 by nbouchez          #+#    #+#             */
/*   Updated: 2018/11/20 22:35:28 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"


int draw_line(int x0, int y0, int x1, int y1, void *mxl_ptr, void *win_ptr);
void draw_iso(int *map, void *mxl_ptr, void *win_ptr);
