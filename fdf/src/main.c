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
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*map;
	int		x;
	int		y;

	if (ac == 2)
	{
		if (!(map = reader(av[1], &x, &y)))
			return (-1);
	}
		else
			return (-1);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, SCREENSIZE, SCREENSIZE, "FdF School 19");
	menu_manager(mlx_ptr, win_ptr);
	scene_manager(mlx_ptr, win_ptr, map, x, y);
	//mlx_put_image_to_window (mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}
