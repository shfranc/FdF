/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 18:47:37 by sfranc            #+#    #+#             */
/*   Updated: 2017/05/31 11:30:25 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_new_color(t_map *map, int new_color)
{
	t_map *temp_row;
	t_map *temp_col;

	temp_row = map;
	while (temp_row)
	{
		temp_col = temp_row;
		while (temp_col)
		{
			temp_col->color = new_color;
			temp_col = temp_col->next;
		}
		temp_row = temp_row->down;
	}
}

static void		ft_switch_color(t_holder *hold, int new_color)
{
	mlx_destroy_image(hold->mlx, hold->img);
	ft_new_color(hold->map, new_color);
	hold->img = ft_fill_image(hold->mlx, hold->map, &hold->draw);
	mlx_put_image_to_window(hold->mlx, hold->win, hold->img, 0, 0);
}

void			ft_change_color(int keycode, t_holder *hold)
{
	if (keycode == 15)
		ft_switch_color(hold, 0xFF0000);
	if (keycode == 5)
		ft_switch_color(hold, 0x00FF00);
	if (keycode == 11)
		ft_switch_color(hold, 0x0000FF);
	if (keycode == 16)
		ft_switch_color(hold, 0xFFFF00);
}
