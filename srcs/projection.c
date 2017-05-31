/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 16:35:25 by sfranc            #+#    #+#             */
/*   Updated: 2017/05/31 16:38:16 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_cavaliere_projection(t_map *map, t_draw *draw)
{
	t_map *temp_row;
	t_map *temp_col;

	(void)draw;
	temp_row = map;
	while (temp_row)
	{
		temp_col = temp_row;
		while (temp_col)
		{
			temp_col->iso_x = temp_col->x + (-temp_col->y * 35 / 100);
			temp_col->iso_y = temp_col->z + (-temp_col->y * 35 / 100);
			temp_col = temp_col->next;
		}
		temp_row = temp_row->down;
	}
}

void		ft_isometric_projection(t_map *map, t_draw *draw)
{
	t_map *temp_row;
	t_map *temp_col;

	(void)draw;
	temp_row = map;
	while (temp_row)
	{
		temp_col = temp_row;
		while (temp_col)
		{
			temp_col->iso_x = 70 * (temp_col->x - temp_col->y) / 100;
			temp_col->iso_y = ((82 * temp_col->z) / 100 -\
				(41 * (temp_col->x + temp_col->y) / 100));
			temp_col = temp_col->next;
		}
		temp_row = temp_row->down;
	}
}
