/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <nbouchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 22:21:23 by nbouchez          #+#    #+#             */
/*   Updated: 2019/03/12 15:24:57 by rpousseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, t_data *prm)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 69 || key == 78)
	{
		if (key == 69)
			prm->multi++;
		else
			prm->multi--;
		scene_manager(prm);
	}
	if (key == 67)
	{
		prm->view = !prm->view;
		scene_manager(prm);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_data	data;

	data.view = DEFAULT_VIEW;
	data.multi = 1;
	if (ac == 2)
	{
		if (!(data.map = reader(av[1], &data.x, &data.y)))
		{
			write(1, "Usage : ./fdf [filename]\nFile error !\n", 39);
			return (-1);
		}
	}
	else
	{
		write(1, "Usage : ./fdf [filename]\n", 26);
		return (-1);
	}
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, SSI, SSI, "FdF School 19");
	data.view = DEFAULT_VIEW;
	scene_manager(&data);
	mlx_key_hook(data.win_ptr, deal_key, (void *)&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
