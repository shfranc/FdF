/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 17:12:14 by sfranc            #+#    #+#             */
/*   Updated: 2017/05/22 18:55:39 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_scale_up(t_map *map, int gap)
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
	ft_fdf_display_matrix(map);
}

static void	ft_draw_graph(char *ram, int width, t_map *map)
{
	int i;
	t_map *temp_row;
	t_map *temp_col;

	temp_row = map;
	i = 0;
	while (temp_row)
	{
		temp_col = temp_row;
		while (temp_col)
		{
			if (temp_col->next)
				ft_drawline(ram, width, temp_col->x, temp_col->y, temp_col->next->x, temp_col->next->y, 0xFFFF00); // jaune
			if (temp_col->down)
				ft_drawline(ram, width, temp_col->x, temp_col->y, temp_col->down->x, temp_col->down->y, 0xFFFF); // cyan
			temp_col = temp_col->next;
			// ft_putnbr_endl(i);
			i++;
		}
		temp_row = temp_row->down;
	}
}

void	*ft_fill_image(void *mlx, t_map *map)
{
	void *img;
	char *ram;
	int bits_per_pixel;
	int size_line;
	int endian;

	(void)map;

	img = mlx_new_image(mlx, 800, 800);
	ram = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);
	
	ft_scale_up(map, 40);
	ft_draw_graph(ram, 800, map);
	
	return (img);
}




