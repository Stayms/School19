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

int	main(int ac, char **av)
{
	void	*mxl_ptr;
	void	*win_ptr;
	int		fd;
	int map[0][0];


	mxl_ptr = mlx_init();
	win_ptr = mlx_new_window(mxl_ptr, SCREENSIZE, SCREENSIZE, "FdF School 19");
	draw_iso(&map[0][0], mxl_ptr, win_ptr, 10, 10);
	mlx_loop(mxl_ptr);
	return (0);
}