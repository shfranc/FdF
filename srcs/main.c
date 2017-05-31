/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 17:46:36 by sfranc            #+#    #+#             */
/*   Updated: 2017/05/31 16:42:43 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	void		*param;
	t_holder	hold;

	if (ac != 2)
		ft_exit("usage: ./fdf <filename>", 1);
	param = &hold;
	ft_init_draw(&hold.draw);
	hold.map = ft_get_data(av[1], &hold.draw);
	ft_fetch_height(hold.map, &hold.draw);
	ft_init_scale(&hold.draw);
	ft_scale_up(hold.map, hold.draw.scale);
	ft_isometric_projection(hold.map, &hold.draw);
	ft_fetch_dim(hold.map, &hold.draw);
	ft_init_dim(&hold.draw);
	ft_center_origin(hold.map, &hold.draw);
	hold.mlx = mlx_init();
	hold.win = mlx_new_window(hold.mlx, hold.draw.img_width + 230,\
		hold.draw.img_height, av[1]);
	ft_win_display_menu(&hold);
	hold.img = ft_fill_image(hold.mlx, hold.map, &hold.draw);
	mlx_put_image_to_window(hold.mlx, hold.win, hold.img, 0, 0);
	mlx_key_hook(hold.win, ft_events, param);
	mlx_loop(hold.mlx);
	ft_fdf_lstdel(&hold.map);
	return (0);
}
