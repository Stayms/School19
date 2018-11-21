/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 22:21:23 by nbouchez          #+#    #+#             */
/*   Updated: 2018/11/20 22:21:24 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int main()
{
	void *mxl_ptr;
	void *win_ptr;
	int map[4][4];


	map[0][0] = 1;
	map[0][1] = 1;
	map[0][2] = 2;
	map[0][3] = 1;

	mxl_ptr = mlx_init();
	win_ptr = mlx_new_window(mxl_ptr, 1000, 1000, "FdF School 19");
	draw_iso(&map[0][0], mxl_ptr, win_ptr);
	mlx_loop(mxl_ptr);
}