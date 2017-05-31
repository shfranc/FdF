/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 17:12:14 by sfranc            #+#    #+#             */
/*   Updated: 2017/05/31 16:37:11 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_scale_up(t_map *map, int gap)
{
	t_map *temp_row;
	t_map *temp_col;

	temp_row = map;
	while (temp_row)
	{
		temp_col = temp_row;
		while (temp_col)
		{
			temp_col->x *= gap;
			temp_col->y *= gap;
			temp_col->z *= gap;
			temp_col = temp_col->next;
		}
		temp_row = temp_row->down;
	}
}

void		ft_center_origin(t_map *map, t_draw *draw)
{
	t_map *temp_row;
	t_map *temp_col;

	temp_row = map;
	while (temp_row)
	{
		temp_col = temp_row;
		while (temp_col)
		{
			temp_col->iso_x += MARGIN / 2;
			temp_col->res_x = temp_col->iso_x;
			temp_col->iso_y += draw->img_height - draw->ymax - MARGIN / 2;
			temp_col->res_y = temp_col->iso_y;
			temp_col = temp_col->next;
		}
		temp_row = temp_row->down;
	}
}

static void	ft_draw_graph(char *ram, t_draw *draw, t_map *map)
{
	t_map *temp_row;
	t_map *temp_col;

	temp_row = map;
	while (temp_row)
	{
		temp_col = temp_row;
		while (temp_col)
		{
			if (temp_col->next)
				ft_drawline(ram, draw, temp_col, temp_col->next);
			if (temp_col->down)
				ft_drawline(ram, draw, temp_col, temp_col->down);
			temp_col = temp_col->next;
		}
		temp_row = temp_row->down;
	}
}

void		*ft_fill_image(void *mlx, t_map *map, t_draw *draw)
{
	void	*img;
	char	*ram;
	int		bits_per_pixel;
	int		size_line;
	int		endian;

	img = mlx_new_image(mlx, draw->img_width, draw->img_height);
	ram = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);
	ft_draw_graph(ram, draw, map);
	return (img);
}
