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

int		deal_key(int key, t_data *param)
{
	if (key == 75)
		scaleout(param);
	else if (key == 67)
		scalein(param);
	else if (key == 123 || key == 126 || key == 125 || key == 124)
		move(param, key);
	else
		tools(param, key);
	scene_manager(param);
	return (0);
}

void	mlx_init_windows(t_data *data, char **av)
{
	if (!ft_strcmp(av[1], "Mandelbrot"))
	{
		data->id = 1;
		set_value_mandelbrot(data);
	}
	else if (!ft_strcmp(av[1], "Julia"))
	{
		data->id = 2;
		set_value_julia(data);
	}
	else if (!ft_strcmp(av[1], "Burningship"))
	{
		data->id = 3;
		set_value_burningship(data);
	}
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, SCREENSIZE,
		SCREENSIZE, "Fractol School 19");
	data->img = mlx_new_image(data->mlx_ptr,
		SCREENSIZE, SCREENSIZE);
	data->img_ptr = (int*)mlx_get_data_addr(data->img,
		&data->bpp, &data->sl, &data->endian);
}

int		main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "Mandelbrot") || !ft_strcmp(av[1], "Julia")
		|| !ft_strcmp(av[1], "Burningship"))
		{
			mlx_init_windows(&data, av);
			scene_manager(&data);
			mlx_hook(data.win_ptr, 6, 1L < 6, julia_mouse, &data);
			mlx_key_hook(data.win_ptr, deal_key, (void *)&data);
			mlx_mouse_hook(data.win_ptr, mouse_hook, &data);
			mlx_loop(data.mlx_ptr);
		}
		else
		{
			write(1, "Usage : ./fractol [fractol name]\n", 33);
			write(1, "\tName available : Mandelbrot, Julia, Burningship\n", 49);
		}
	}
	else
		write(1, "Usage : ./fractol [fractol name]\n", 33);
	return (0);
}
