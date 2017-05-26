/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 17:48:37 by sfranc            #+#    #+#             */
/*   Updated: 2017/05/26 17:55:00 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_draw(t_draw *draw)
{
	draw->nb_row = 0;
	draw->nb_col = 0;
	draw->scale = 0;
	draw->xmin = 0;
	draw->xmax = 0;
	draw->ymin = 0;
	draw->ymax = 0;
	draw->height = 100;
	draw->img_width = 0;
	draw->img_height = 0;
}

void	ft_init_scale(t_draw *draw)
{
	draw->scale = 30;
	while (draw->scale * (draw->nb_col + draw->nb_row) > MAXWIDTH\
		&& draw->scale > 3)
		draw->scale--;
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
			temp_col->x < draw->xmin ?  draw->xmin = temp_col->x : 0;
			temp_col->x > draw->xmax ?  draw->xmax = temp_col->x : 0;
			temp_col->y < draw->ymin ?  draw->ymin = temp_col->y : 0;
			temp_col->y > draw->ymax ?  draw->ymax = temp_col->y : 0;
			temp_col = temp_col->next;
		}
		temp_row = temp_row->down;
	}
}

void	ft_init_dim(t_draw *draw)
{
	draw->img_width = (abs(draw->xmin) + abs(draw->xmax)) < MAXWIDTH ?\
	(abs(draw->xmin) + abs(draw->xmax)) + MARGIN : MAXWIDTH;
	draw->img_height = (abs(draw->ymin) + abs(draw->ymax)) < MAXHEIGHT ?\
	(abs(draw->ymin) + abs(draw->ymax)) + MARGIN : MAXHEIGHT;
}

