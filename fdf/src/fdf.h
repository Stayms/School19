/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <nbouchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 22:34:54 by nbouchez          #+#    #+#             */
/*   Updated: 2019/03/12 15:16:33 by rpousseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define SSI 1300
# define PADX 0
# define PADY 50
# define ROT 0.509066
# define DEFAULT_VIEW 1
# define MULTIPLICATION 5
# define HOME_COLOR 100

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				*map;
	int				x;
	int				y;
	int				multi;
	int				view;

}					t_data;

typedef struct		s_drawl
{
	int				dx;
	int				sx;
	int				dy;
	int				sy;
	int				err;
	int				e2;
	int				*img_tmp;
}					t_drawl;

typedef struct		s_drawc
{
	double			size_tuile;
	double			diff_size;
	double			diff_size_sub;
	double			percent;
	double			percent_n;
	int				x;
	int				y;
}					t_drawc;

typedef struct		s_drawi
{
	int				x;
	int				y;
	float			s_tui;
}					t_drawi;

typedef struct		s_arg
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
}					t_arg;

void				draw_line(t_arg arg, int *image);
void				scene_manager(t_data *param);
void				draw_iso(t_data prm, int *image);
void				draw_con(t_data prm, int *image);
int					*reader(char *file, int *x, int *y);

#endif
