/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 17:48:37 by sfranc            #+#    #+#             */
/*   Updated: 2017/06/01 10:56:57 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fetch_height(t_map *map, t_draw *draw)
{
	t_map *temp_row;
	t_map *temp_col;

	temp_row = map;
	while (temp_row)
	{
		temp_col = temp_row;
		while (temp_col)
		{
			temp_col->z > draw->zmax ? draw->zmax = temp_col->z : 0;
			temp_col->z < draw->zmin ? draw->zmin = temp_col->z : 0;
			temp_col = temp_col->next;
		}
		temp_row = temp_row->down;
	}
	draw->height = ft_abs(draw->zmin) + ft_abs(draw->zmax);
}

void	ft_init_scale(t_draw *draw)
{
	draw->scale = 30;
	while ((draw->scale * draw->nb_col > MAXWIDTH\
		|| (draw->height + draw->nb_row) * draw->scale > MAXHEIGHT)\
		&& draw->scale > 3)
	{
		draw->scale--;
	}
}

void	ft_fetch_dim(t_map *map, t_draw *draw)
{
	t_map *temp_row;
	t_map *temp_col;

	temp_row = map;
	while (temp_row)
	{
		temp_col = temp_row;
		while (temp_col)
		{
			temp_col->iso_x < draw->xmin ? draw->xmin = temp_col->iso_x : 0;
			temp_col->iso_x > draw->xmax ? draw->xmax = temp_col->iso_x : 0;
			temp_col->iso_y < draw->ymin ? draw->ymin = temp_col->iso_y : 0;
			temp_col->iso_y > draw->ymax ? draw->ymax = temp_col->iso_y : 0;
			temp_col = temp_col->next;
		}
		temp_row = temp_row->down;
	}
}

void	ft_init_dim(t_draw *draw)
{
	draw->img_width = (ft_abs(draw->xmin) + ft_abs(draw->xmax)) < MAXWIDTH ?\
	(ft_abs(draw->xmin) + ft_abs(draw->xmax)) + MARGIN : MAXWIDTH;
	draw->img_height = (ft_abs(draw->ymin) + ft_abs(draw->ymax)) < MAXHEIGHT ?\
	(ft_abs(draw->ymin) + ft_abs(draw->ymax)) + MARGIN : MAXHEIGHT;
	if (draw->img_height < 290)
		draw->img_height = 290;
}
