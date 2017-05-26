/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 17:49:29 by sfranc            #+#    #+#             */
/*   Updated: 2017/05/26 17:54:15 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_events(int keycode, void *param)
{
	t_holder	*hold;

	hold = param;
	ft_putstr("Keycode :");
	ft_putnbr_endl(keycode);
	if (keycode == 53)
		exit(0);

	// if (keycode == 121) // abaisser la hauteur
	// {
	// 	mlx_destroy_image(hold->mlx, hold->img);
	// 	ft_init_scale(&hold->draw);
	// 	ft_scale_up(hold->map, hold->draw.scale);
	// 	ft_isometric_projection(hold->map, &hold->draw);
	// 	ft_fetch_dim(hold->map, &hold->draw);
	// 	ft_init_dim(&hold->draw);
	// 	ft_center_origin(hold->map, &hold->draw);
	// 	hold->img = ft_fill_image(hold->mlx, hold->map, &hold->draw);
	// 	mlx_put_image_to_window(hold->mlx, hold->win, hold->img, 0, 0);
	// }
	
	return (0);
}
