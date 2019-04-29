/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_iso.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <nbouchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 03:40:05 by nbouchez          #+#    #+#             */
/*   Updated: 2019/03/12 15:17:57 by rpousseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		init_arg(t_arg *arg, t_data *prm, t_drawi drawi, char tru)
{
	arg->x0 = ((drawi.x - drawi.y) * cos(ROT)) * drawi.s_tui;
	arg->y0 = ((drawi.y + drawi.x) * sin(ROT)) * drawi.s_tui -
	*prm->map * prm->multi;
	arg->x1 = ((drawi.x - (drawi.y + 1)) * cos(ROT)) * drawi.s_tui;
	arg->y1 = (((drawi.y + 1) + drawi.x) * sin(ROT)) *
	drawi.s_tui - *(prm->map + prm->x) * prm->multi;
	if (tru)
	{
		arg->x0 = ((drawi.x - drawi.y) * cos(ROT)) * drawi.s_tui;
		arg->y0 = ((drawi.y + drawi.x) * sin(ROT)) * drawi.s_tui -
		*prm->map * prm->multi;
		arg->x1 = (((drawi.x + 1) - drawi.y) * cos(ROT)) * drawi.s_tui;
		arg->y1 = ((drawi.y + drawi.x + 1) * sin(ROT)) * drawi.s_tui -
		*(prm->map + 1) * prm->multi;
	}
}

void			draw_iso(t_data prm, int *image)
{
	t_drawi	drawi;
	t_arg	arg;

	drawi.y = 0;
	drawi.s_tui = (prm.x > prm.y ? (float)SSI / prm.x : (float)SSI / prm.y);
	while (drawi.y < prm.y)
	{
		drawi.x = 0;
		while (drawi.x < prm.x)
		{
			if (drawi.y != prm.y - 1)
			{
				init_arg(&arg, &prm, drawi, 0);
				draw_line(arg, image);
			}
			if (drawi.x != prm.x - 1)
			{
				init_arg(&arg, &prm, drawi, 1);
				draw_line(arg, image);
			}
			drawi.x++;
			prm.map++;
		}
		drawi.y++;
	}
}
