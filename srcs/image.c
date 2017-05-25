/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 17:12:14 by sfranc            #+#    #+#             */
/*   Updated: 2017/05/25 21:49:28 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

void	ft_isometric_projection(t_map *map, t_draw *draw)
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
			temp_col->iso_y = (82 * temp_col->z) / 2000 - (41 * (temp_col->x + temp_col->y) / 100);
			// if (temp_col->z > 0)
			// 	temp_col->color = 0x0F00FF; // modifier la couleur en fonction de l'altitude
			temp_col->x = temp_col->iso_x;
			temp_col->y = temp_col->iso_y;
			// printf("x: %d\ty: %d\tz: %d\n", temp_col->x, temp_col->y, temp_col->z);
			temp_col = temp_col->next;
		}
		temp_row = temp_row->down;
	}
}

void	ft_scale_up(t_map *map, int gap)
{
	t_map *temp_row;
	t_map *temp_col;

	(void)gap;
	
	temp_row = map;
	while (temp_row)
	{
		temp_col = temp_row;
		while (temp_col)
		{
			temp_col->x *= gap;
			temp_col->y *= gap;
			temp_col->z *= gap; // hauteur non homogene
			temp_col = temp_col->next;
		}
		temp_row = temp_row->down;
	}
	// ft_fdf_display_matrix(map);
}

void	ft_center_origin(t_map *map, t_draw *draw)
{
	t_map *temp_row;
	t_map *temp_col;

	temp_row = map;
	while (temp_row)
	{
		temp_col = temp_row;
		while (temp_col)
		{
			temp_col->x += MARGIN / 2;
			temp_col->y += draw->img_height - draw->ymax - MARGIN / 2;
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

void	*ft_fill_image(void *mlx, t_map *map, t_draw *draw)
{
	void *img;
	char *ram;
	int bits_per_pixel;
	int size_line;
	int endian;

	(void)map;

	img = mlx_new_image(mlx, draw->img_width, draw->img_height);
	ram = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);
	

	// ft_scale_up(map, draw->scale);
	
	// ft_isometric_projection(map, draw);
	
	// ft_center_origin(map, draw);	

	ft_draw_graph(ram, draw, map);
	
	return (img);
}
