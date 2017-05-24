/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 17:46:36 by sfranc            #+#    #+#             */
/*   Updated: 2017/05/24 19:04:40 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_draw(t_draw *draw)
{
	draw->nb_row = 0;
	draw->nb_col = 0;
	draw->scale = 0;
	draw->img_width = 0;
	draw->img_height = 0;
	draw->win_width = 0;
	draw->win_height = 0;
}

void	ft_init_dim(t_draw *draw)
{

	draw->scale = 30;
	while (draw->scale * (draw->nb_col + draw->nb_row) > MAXWIDTH)
		draw->scale--;
	draw->img_width = MAXWIDTH / 2;
	draw->img_height = MAXHEIGHT;
	draw->win_width = draw->img_width;
	draw->win_height = draw->img_height;
}

int		main(int ac, char **av)
{
	t_map	*map;
	t_draw	draw;
	void	*mlx;
	void	*win;
	void	*img;

	if (ac != 2)
		ft_exit("usage: ./fdf <filename>", 1);
	ft_init_draw(&draw);
	map = ft_get_data(av[1], &draw);
	
	ft_putnbr_endl(MAXWIDTH);
	ft_putnbr_endl(MAXHEIGHT);
	ft_putnbr_endl(draw.nb_col);
	ft_putnbr_endl(draw.nb_row);
	ft_init_dim(&draw);
	ft_putnbr_endl(draw.img_width);
	ft_putnbr_endl(draw.img_height);
	ft_putnbr_endl(draw.win_width);
	ft_putnbr_endl(draw.win_height);

	
	
	ft_isometric_projection(map, &draw);
	ft_scale_up(map, draw.scale);
	ft_center_origin(map, &draw);

	mlx = mlx_init();
	// win = mlx_new_window(mlx, 2560, 1315, "fdf");
	win = mlx_new_window(mlx, draw.win_width, draw.win_height, "fdf");

	img = ft_fill_image(mlx, map, &draw);

	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_key_hook(win, ft_escape, 0);
	mlx_loop(mlx);
	return (0);
}

	// img = mlx_new_image(mlx, 800, 800);
	// ram = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);
	
	// printf("%d\t", bits_per_pixel);
	// printf("%d\t", size_line);
	// printf("%d\n", endian);

	// x = 0;
	// while(x < (200 * 200))
	// {
	// 	ft_putpixel(ram, x, 0xFF);
	// 	x++;
	// }

	// ft_drawline(ram, 200, 0, 0, 200, 200, 0xFF); // anti diagonal bleu fonce
	// ft_drawline(ram, 200, 0, 0, 200, 0, 0xFFFF); // horizontal cyan
	// ft_drawline(ram, 200, 0, 0, 0, 200, 0xFFFFFF); // vertical blanc

	// ft_drawline(ram, 800, 0, 799, 0, 0, 0xFF00FF); // -1 ; -1
	// ft_drawline(ram, 800, 0, 799, 400, 0, 0xFFFF); // 1 ; -1
	// ft_drawline(ram, 800, 0, 799, 799, 0, 0xFFFF); //  1 ; -1 increment sur les y magenta
	// ft_drawline(ram, 800, 0, 799, 799, 400, 0xFFFF); //  1 ; -1 increment sur les x cyan
	// ft_drawline(ram, 800, 0, 799, 799, 799, 0xFFFF); //  1 ; -1 increment sur les x cyan
	// ft_drawline(ram, 800, 0, 0, 799, 799, 0xFF); // 1 ; 1
	// ft_drawline(ram, 800, 0, 0, 799, 799, 0xFF); // 1 ; 1
