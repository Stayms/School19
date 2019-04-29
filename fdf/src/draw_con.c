/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_con.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <nbouchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 03:40:05 by nbouchez          #+#    #+#             */
/*   Updated: 2019/03/12 15:19:29 by rpousseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		init_drawc(t_drawc *drawc, t_data *prm, char tru)
{
	drawc->percent = (double)(drawc->y / (double)prm->y) + 0.9;
	drawc->percent_n = (double)((drawc->y + 1) / (double)prm->y) + 0.9;
	drawc->x = 0;
	if (tru)
	{
		drawc->y = 0;
		drawc->size_tuile = (double)(SSI / (prm->x - 1)) / 2;
		drawc->diff_size = (double)(drawc->size_tuile * (prm->x - 1) * 1.9 -
		(drawc->size_tuile * 0.9 * (prm->x - 1))) / 2;
		drawc->diff_size_sub = drawc->diff_size / (prm->y - 1);
	}
}

static void		init_arg(t_arg *arg, t_drawc drawc, t_data prm, char tru)
{
	arg->x0 = drawc.x * (drawc.size_tuile * drawc.percent) + drawc.diff_size;
	arg->y0 = drawc.y * drawc.size_tuile - *prm.map * prm.multi * drawc.percent;
	arg->x1 = drawc.x * drawc.size_tuile * drawc.percent_n + drawc.diff_size -
	drawc.diff_size_sub;
	arg->y1 = (drawc.y + 1) * drawc.size_tuile - *(prm.map + prm.x)
	* prm.multi * drawc.percent_n;
	if (tru)
	{
		arg->x0 = drawc.x * drawc.size_tuile * drawc.percent + drawc.diff_size;
		arg->y0 = drawc.y * drawc.size_tuile - *prm.map * prm.multi
		* drawc.percent;
		arg->x1 = (drawc.x + 1) * drawc.size_tuile * drawc.percent
		+ drawc.diff_size;
		arg->y1 = drawc.y * drawc.size_tuile - *(prm.map + 1) * prm.multi
		* drawc.percent;
	}
}

void			draw_con(t_data prm, int *image)
{
	t_drawc	drawc;
	t_arg	arg;

	init_drawc(&drawc, &prm, 1);
	while (drawc.y < prm.y)
	{
		init_drawc(&drawc, &prm, 0);
		while (drawc.x < prm.x)
		{
			if (drawc.y != prm.y - 1)
			{
				init_arg(&arg, drawc, prm, 0);
				draw_line(arg, image);
			}
			if (drawc.x != prm.x - 1)
			{
				init_arg(&arg, drawc, prm, 1);
				draw_line(arg, image);
			}
			drawc.x++;
			prm.map++;
		}
		drawc.diff_size = drawc.diff_size - drawc.diff_size_sub;
		drawc.y++;
	}
}
