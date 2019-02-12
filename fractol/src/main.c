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

#include "fractol.h"

int deal_key(int key, t_data *param)
{
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "Mandelbrot") || !ft_strcmp(av[1], "Julia"))
		{
			if(!ft_strcmp(av[1], "Mandelbrot"))
				data.id = 1;
			else if(!ft_strcmp(av[1], "Julia"))
				data.id = 2;
			data.mlx_ptr = mlx_init();
			data.win_ptr = mlx_new_window(data.mlx_ptr, SCREENSIZE, SCREENSIZE, "Fractol School 19");
			scene_manager(&data);
			mlx_key_hook (data.win_ptr, deal_key, (void *)&data);
			mlx_loop(data.mlx_ptr);
		}
		else
		{
			write(1,"Usage : ./fractol [fractol name]\n",33);
			write(1,"\tName available : Mandelbrot\n",28);
		}
	}
	else
		write(1,"Usage : ./fractol [fractol name]\n",33);
	return (0);
}
