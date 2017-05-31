/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 18:47:31 by sfranc            #+#    #+#             */
/*   Updated: 2017/05/31 11:29:36 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_new_origin(t_map *map, int x_move, int y_move)
{
	t_map *temp_row;
	t_map *temp_col;

	temp_row = map;
	while (temp_row)
	{
		temp_col = temp_row;
		while (temp_col)
		{
			temp_col->iso_x += x_move;
			temp_col->iso_y += y_move;
			temp_col = temp_col->next;
		}
		temp_row = temp_row->down;
	}
}

static void		ft_move_map(t_holder *hold, int x_move, int y_move)
{
	mlx_destroy_image(hold->mlx, hold->img);
	ft_new_origin(hold->map, x_move, y_move);
	hold->img = ft_fill_image(hold->mlx, hold->map, &hold->draw);
	mlx_put_image_to_window(hold->mlx, hold->win, hold->img, 0, 0);
}

void			ft_change_origin(int keycode, t_holder *hold)
{
	if (keycode == 123 || keycode == 86)
		ft_move_map(hold, -10, 0);
	if (keycode == 124 || keycode == 88)
		ft_move_map(hold, 10, 0);
	if (keycode == 125 || keycode == 84)
		ft_move_map(hold, 0, 10);
	if (keycode == 126 || keycode == 91)
		ft_move_map(hold, 0, -10);
	if (keycode == 92)
		ft_move_map(hold, 10, -10);
	if (keycode == 89)
		ft_move_map(hold, -10, -10);
	if (keycode == 83)
		ft_move_map(hold, -10, 10);
	if (keycode == 85)
		ft_move_map(hold, 10, 10);
}
