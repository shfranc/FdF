/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 17:49:29 by sfranc            #+#    #+#             */
/*   Updated: 2017/05/31 17:51:33 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_back_origin(t_map *map)
{
	t_map *temp_row;
	t_map *temp_col;

	temp_row = map;
	while (temp_row)
	{
		temp_col = temp_row;
		while (temp_col)
		{
			temp_col->x = temp_col->ori_x;
			temp_col->y = temp_col->ori_y;
			temp_col->z = temp_col->ori_z;
			temp_col->color = temp_col->res_color;
			temp_col = temp_col->next;
		}
		temp_row = temp_row->down;
	}
}

static void		ft_reset_map(t_holder *hold)
{
	mlx_destroy_image(hold->mlx, hold->img);
	hold->draw.zoom = 0;
	ft_back_origin(hold->map);
	ft_scale_up(hold->map, hold->draw.scale);
	ft_isometric_projection(hold->map, &hold->draw);
	ft_center_origin(hold->map, &hold->draw);
	hold->img = ft_fill_image(hold->mlx, hold->map, &hold->draw);
	mlx_put_image_to_window(hold->mlx, hold->win, hold->img, 0, 0);
}

static void		ft_change_projection(t_holder *hold)
{
	mlx_destroy_image(hold->mlx, hold->img);
	ft_cavaliere_projection(hold->map, &hold->draw);
	ft_center_origin(hold->map, &hold->draw);
	hold->img = ft_fill_image(hold->mlx, hold->map, &hold->draw);
	mlx_put_image_to_window(hold->mlx, hold->win, hold->img, 0, 0);
}

int				ft_events(int keycode, void *param)
{
	t_holder	*hold;

	hold = param;
	ft_change_origin(keycode, hold);
	ft_change_color(keycode, hold);
	if (keycode == 69)
		ft_zoom_in(hold);
	if (keycode == 78)
		ft_zoom_out(hold);
	if (keycode == 8)
		ft_change_projection(hold);
	if (keycode == 87 || keycode == 49)
		ft_reset_map(hold);
	if (keycode == 53)
		exit(0);
	return (0);
}
