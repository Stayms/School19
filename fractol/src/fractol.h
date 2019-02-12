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


#ifndef FRACTOL_H
# define FRACTOL_H
# define SCREENSIZE 1300
# define PADDINGX 0
# define PADDINGY 0
# include "../minilibx_macos/mlx.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# define HOME_COLOR 100


typedef struct 		s_complex
{
	double	r;
	double	i;			
}					t_complex;

typedef struct		s_map
{
	int		zoom;
	int		*map;
	int		offset_x;
	int		offset_y;
	double	scale;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double image_x;
	double image_y;
	double zoom_x;
	double zoom_y;
	double color;
}					t_map;

typedef struct		s_data
{
	int		id;
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
}					t_data;

int draw_line(int x0, int y0, int x1, int y1, int *image);
void scene_manager(t_data *data);
void draw_mandelbrot(t_data *data);
int draw_point(int x, int y, t_data *data, int color);
void zoomin(t_data *data);
void zoomout(t_data *data);

#endif