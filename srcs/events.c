/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 17:49:29 by sfranc            #+#    #+#             */
/*   Updated: 2017/05/30 18:46:31 by sfranc           ###   ########.fr       */
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

static void ft_reset_map(t_holder *hold)
{
	mlx_destroy_image(hold->mlx, hold->img);
	ft_back_origin(hold->map);
	hold->img = ft_fill_image(hold->mlx, hold->map, &hold->draw);
	mlx_put_image_to_window(hold->mlx, hold->win, hold->img, 0, 0);
}

static void	ft_move_map(t_holder *hold, int x_move, int y_move)
{
	mlx_destroy_image(hold->mlx, hold->img);
	ft_new_origin(hold->map, x_move, y_move);
	hold->img = ft_fill_image(hold->mlx, hold->map, &hold->draw);
	mlx_put_image_to_window(hold->mlx, hold->win, hold->img, 0, 0);
}

static void	ft_change_origin(int keycode, t_holder *hold)
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

static void	ft_switch_color(t_holder *hold, int new_color)
{
	mlx_destroy_image(hold->mlx, hold->img);
	ft_new_color(hold->map, new_color);
	hold->img = ft_fill_image(hold->mlx, hold->map, &hold->draw);
	mlx_put_image_to_window(hold->mlx, hold->win, hold->img, 0, 0);
}

static void	ft_change_color(int keycode, t_holder *hold)
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

int		ft_events(int keycode, void *param)
{
	t_holder	*hold;
	
	ft_putstr("Keycode :");
	ft_putnbr_endl(keycode);
	
	hold = param;
	ft_change_origin(keycode, hold);
	ft_change_color(keycode, hold);
	if (keycode == 87)
		ft_reset_map(hold);
	if (keycode == 53)
		exit(0);
	return (0);
}
