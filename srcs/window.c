/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 12:21:02 by sfranc            #+#    #+#             */
/*   Updated: 2017/05/31 16:45:24 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_win_display_menu2(t_holder *hold)
{
	mlx_string_put(hold->mlx, hold->win, hold->draw.img_width + 10, 185,\
		0xFF0000, "r: red");
	mlx_string_put(hold->mlx, hold->win, hold->draw.img_width + 100, 185,\
		0x00FF00, "g: green");
	mlx_string_put(hold->mlx, hold->win, hold->draw.img_width + 10, 205,\
		0x0000FF, "b: blue");
	mlx_string_put(hold->mlx, hold->win, hold->draw.img_width + 100, 205,\
		0xFFFF00, "y: yellow");
	mlx_string_put(hold->mlx, hold->win, hold->draw.img_width + 10, 225,\
		0xFFFFFF, "+: zoom+");
	mlx_string_put(hold->mlx, hold->win, hold->draw.img_width + 100, 225,\
		0xFFFFFF, "-: zoom-");
	mlx_string_put(hold->mlx, hold->win, hold->draw.img_width + 10, 245,\
		0xFFFFFF, "c: cavalier (no zoom)");
	mlx_string_put(hold->mlx, hold->win, hold->draw.img_width + 10, 265,\
		0xFFFFFF, "5 or space: RESET");
}

void			ft_win_display_menu(t_holder *hold)
{
	mlx_string_put(hold->mlx, hold->win, hold->draw.img_width + 10, 5,\
		0x00FFFF, "Keys:");
	mlx_string_put(hold->mlx, hold->win, hold->draw.img_width + 10, 25,\
		0xFFFFFF, "8 or ^: up");
	mlx_string_put(hold->mlx, hold->win, hold->draw.img_width + 10, 45,\
		0xFFFFFF, "2 or v: down");
	mlx_string_put(hold->mlx, hold->win, hold->draw.img_width + 10, 65,\
		0xFFFFFF, "6 or >: right");
	mlx_string_put(hold->mlx, hold->win, hold->draw.img_width + 10, 85,\
		0xFFFFFF, "4 or <: left");
	mlx_string_put(hold->mlx, hold->win, hold->draw.img_width + 10, 105,\
		0xFFFFFF, "7: up & left");
	mlx_string_put(hold->mlx, hold->win, hold->draw.img_width + 10, 125,\
		0xFFFFFF, "9: up & right");
	mlx_string_put(hold->mlx, hold->win, hold->draw.img_width + 10, 145,\
		0xFFFFFF, "1: down & left");
	mlx_string_put(hold->mlx, hold->win, hold->draw.img_width + 10, 165,\
		0xFFFFFF, "3: down & right");
	ft_win_display_menu2(hold);
}
