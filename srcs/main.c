/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 17:46:36 by sfranc            #+#    #+#             */
/*   Updated: 2017/05/19 18:53:21 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	void *mlx;
	void *win;
	void *img;
	char *ram;
	
	int bits_per_pixel;
	int size_line;
	int endian;
	// int x;

	(void)ac;
	(void)av;

	mlx = mlx_init(); // renvoi 0 si echec connexion
	win = mlx_new_window(mlx, 800, 800, "TEST");
	img = mlx_new_image(mlx, 800, 800); // range 0-199
	ram = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);
	
	printf("%d\t", bits_per_pixel);
	printf("%d\t", size_line);
	printf("%d\n", endian);

	// x = 0;
	// while(x < (200 * 200))
	// {
	// 	ft_putpixel(ram, x, 0xFF);
	// 	x++;
	// }

	// ft_drawline(ram, 200, 0, 0, 200, 200, 0xFF); // anti diagonal bleu fonce
	// ft_drawline(ram, 200, 0, 0, 200, 0, 0xFFFF); // horizontal cyan
	// ft_drawline(ram, 200, 0, 0, 0, 200, 0xFFFFFF); // vertical blanc

	ft_drawline(ram, 800, 0, 799, 0, 0, 0xFF00FF); // -1 ; -1
	// ft_drawline(ram, 800, 0, 799, 400, 0, 0xFFFF); // 1 ; -1
	// ft_drawline(ram, 800, 0, 799, 799, 0, 0xFFFF); //  1 ; -1 increment sur les y magenta
	// ft_drawline(ram, 800, 0, 799, 799, 400, 0xFFFF); //  1 ; -1 increment sur les x cyan
	// ft_drawline(ram, 800, 0, 799, 799, 799, 0xFFFF); //  1 ; -1 increment sur les x cyan
	// ft_drawline(ram, 800, 0, 0, 799, 799, 0xFF); // 1 ; 1
	// ft_drawline(ram, 800, 0, 0, 799, 799, 0xFF); // 1 ; 1

	mlx_put_image_to_window(mlx, win, img, 0, 0);

	mlx_key_hook(win, ft_exit, 0);
	mlx_loop(mlx); // asynchrone, les pixels sont affiches dans la fenetre au moment de l'appel de cette fonction, et elle gere aussi les evenements. Important de laisser cette ligne a la fin.
	return 0;
}
