/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 17:49:29 by sfranc            #+#    #+#             */
/*   Updated: 2017/05/31 11:30:14 by sfranc           ###   ########.fr       */
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
			temp_col->iso_x = temp_col->res_x;
			temp_col->iso_y = temp_col->res_y;
			temp_col->color = temp_col->res_color;
			temp_col = temp_col->next;
		}
		temp_row = temp_row->down;
	}
}

static void		ft_reset_map(t_holder *hold)
{
	mlx_destroy_image(hold->mlx, hold->img);
	ft_back_origin(hold->map);
	hold->img = ft_fill_image(hold->mlx, hold->map, &hold->draw);
	mlx_put_image_to_window(hold->mlx, hold->win, hold->img, 0, 0);
}

int				ft_events(int keycode, void *param)
{
	t_holder	*hold;

	hold = param;
	ft_change_origin(keycode, hold);
	ft_change_color(keycode, hold);
	if (keycode == 87 || keycode == 49)
		ft_reset_map(hold);
	if (keycode == 53)
		exit(0);
	return (0);
}
