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
# define SCREENSIZE 600
# define PADDINGX 100
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

typedef struct		s_data
{
	int		id;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	int		*img_ptr;
	int		endian;
	int		sl;
	int		bpp;
	double	scale;
	int		x;
	int		y;
	double	x1;
	double	y1;
	double	zoom;
	double	color;
}					t_data;

void scene_manager(t_data *data);
void draw_mandelbrot(t_data *data);
void draw_julia(t_data *data);
int draw_point(int x, int y, t_data *data, int color);
void zoomin(t_data *data, int x, int y);
void zoomout(t_data *data, int x, int y);
void scalein(t_data *data);
void scaleout(t_data *data);
void move(t_data *data, int key);
int	mouse_hook(int mousecode, int x, int y, t_data *data);
void set_value_mandelbrot(t_data *data);
void set_value_julia(t_data *data);

#endif