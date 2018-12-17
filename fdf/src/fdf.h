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


#ifndef FDF_H
# define FDF_H
# define SCREENSIZE 1300
# define PADDINGX 200
# define PADDINGY 200
# define ROTATION 0.509066
# define ZOOM 1
# define MULTIPLICATION 0.001
# include "../minilibx_macos/mlx.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# define HOME_COLOR 100

int count_point(char *v_tmp_split);
int draw_line(int x0, int y0, int x1, int y1, int *image);
void color_img(void *img_ptr, int sizex, int sizey, int color);
void menu_manager(void *mlx_ptr, void *win_ptr);
void scene_manager(void *mlx_ptr, void *win_ptr, int *map, int x, int y);
void draw_iso(int *map, int *image, int sizex, int sizey);
int	*reader(char *file, int *x, int *y);

#endif