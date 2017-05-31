/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:52:06 by sfranc            #+#    #+#             */
/*   Updated: 2017/05/31 15:48:21 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_modify_size(t_map *map, int zoom)
{
	t_map *temp_row;
	t_map *temp_col;

	if (zoom < 2)
		return ;
	temp_row = map;
	while (temp_row)
	{
		temp_col = temp_row;
		while (temp_col)
		{
			temp_col->x = temp_col->ori_x * zoom;
			temp_col->y = temp_col->ori_y * zoom;
			temp_col->z = temp_col->ori_z * zoom;
			temp_col = temp_col->next;
		}
		temp_row = temp_row->down;
	}
}

void			ft_zoom_in(t_holder *hold)
{
	mlx_destroy_image(hold->mlx, hold->img);
	ft_modify_size(hold->map, hold->draw.scale + ++hold->draw.zoom);
	ft_isometric_projection(hold->map, &hold->draw);
	ft_center_origin(hold->map, &hold->draw);
	hold->img = ft_fill_image(hold->mlx, hold->map, &hold->draw);
	mlx_put_image_to_window(hold->mlx, hold->win, hold->img, 0, 0);
}

void			ft_zoom_out(t_holder *hold)
{
	mlx_destroy_image(hold->mlx, hold->img);
	ft_modify_size(hold->map, hold->draw.scale + --hold->draw.zoom);
	ft_isometric_projection(hold->map, &hold->draw);
	ft_center_origin(hold->map, &hold->draw);
	hold->img = ft_fill_image(hold->mlx, hold->map, &hold->draw);
	mlx_put_image_to_window(hold->mlx, hold->win, hold->img, 0, 0);
}
