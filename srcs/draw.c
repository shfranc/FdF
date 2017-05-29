/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 18:02:23 by sfranc            #+#    #+#             */
/*   Updated: 2017/05/29 17:19:00 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_xaxis_draw(char *ram, t_draw *draw, int color)
{
	int	cumul;
	int	i;

	cumul = draw->dx / 2;
	i = 1;
	while (i < draw->dx)
	{
		draw->start_x += draw->xinc;
		cumul += draw->dy;
		if (cumul >= draw->dx)
		{
			cumul -= draw->dx;
			draw->start_y += draw->yinc;
		}
		if (draw->start_x >= 0\
			&& draw->start_x <= draw->img_width\
			&& draw->start_y >= 0\
			&& draw->start_y <= draw->img_height)
			ft_putpixel(ram, draw->start_y * draw->img_width + draw->start_x,\
				color);
		i++;
	}
}

static void	ft_yaxis_draw(char *ram, t_draw *draw, int color)
{
	int	cumul;
	int	i;

	cumul = draw->dy / 2;
	i = 1;
	while (i < draw->dy)
	{
		draw->start_y += draw->yinc;
		cumul += draw->dx;
		if (cumul >= draw->dy)
		{
			cumul -= draw->dy;
			draw->start_x += draw->xinc;
		}
		if (draw->start_x >= 0\
			&& draw->start_x <= draw->img_width\
			&& draw->start_y >= 0\
			&& draw->start_y <= draw->img_height)
			ft_putpixel(ram, draw->start_y * draw->img_width + draw->start_x,\
				color);
		i++;
	}
}

void		ft_drawline(char *ram, t_draw *draw, t_map *pt_x, t_map *pt_y)
{
	draw->start_x = pt_x->iso_x;
	draw->start_y = pt_x->iso_y;
	draw->dx = pt_y->iso_x - pt_x->iso_x;
	draw->dy = pt_y->iso_y - pt_x->iso_y;
	draw->xinc = (draw->dx > 0) ? 1 : -1;
	draw->yinc = (draw->dy > 0) ? 1 : -1;
	draw->dx = (draw->dx > 0) ? draw->dx : -draw->dx;
	draw->dy = (draw->dy > 0) ? draw->dy : -draw->dy;
	if (draw->start_x >= 0\
		&& draw->start_x <= draw->img_width\
		&& draw->start_y >= 0\
		&& draw->start_y <= draw->img_height)
		ft_putpixel(ram, draw->start_y * draw->img_width + draw->start_x,\
			pt_x->color);
	if (draw->dx > draw->dy)
		ft_xaxis_draw(ram, draw, pt_x->color);
	else
		ft_yaxis_draw(ram, draw, pt_x->color);
}
