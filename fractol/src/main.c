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

void set_value(t_data *data)
{
	data->map.zoom = 6;
	data->map.offset_x = PADDINGX;
	data->map.offset_y = PADDINGY;
	data->map.scale = 20;
	data->map.x_min = -2.1;
	data->map.x_max = 0.6;
	data->map.y_min = -1.2;
	data->map.y_max = 1.2;
	data->map.image_x = 270 * data->map.zoom;
	data->map.image_y = 240 * data->map.zoom;
	data->map.zoom_x = data->map.image_x/(data->map.x_max - data->map.x_min);
	data->map.zoom_y = data->map.image_y/(data->map.y_max - data->map.y_min);
	data->map.color = 0;
}


int deal_key(int key, t_data *param)
{
	if(key == 69 || key == 78)
	{
		if(key == 69)
			zoomin(param);
		else if(key == 78)
			zoomout(param);
		scene_manager(param);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	set_value(&data);
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
