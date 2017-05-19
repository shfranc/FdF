/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 18:02:23 by sfranc            #+#    #+#             */
/*   Updated: 2017/05/19 19:01:19 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drawline(char *ram, int width, int x1, int y1, int x2, int y2, int color)
{
	int x;
	int y;
	int	dx;
	int	dy;
	int cumul;
	int xinc;
	int yinc;
	int i;

	x = x1;
	y = y1;
	dx = x2 - x1;
	dy = y2 - y1;
	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	printf("xinc: %d\tyinc: %d\n", xinc, yinc);

	dx = abs(dx);
	dy = abs(dy);

	ft_putpixel(ram, y * width + x , color);

	if (dx > dy)
	{
		printf("increment sur les x\n");
		cumul = dx / 2;
		i = 1;
		while (i < dx)
		{
			x += xinc;
			cumul += dy;
			if (cumul >= dx)
			{
				cumul -= dx;
				y += yinc;
			}
			ft_putpixel(ram, y * width + x , color);
			i++;
		}
	}
	else
	{
		printf("increment sur les y\n");
		cumul = dy / 2;
		i = 1;
		while (i < dy)
		{
			y += yinc;
			cumul += dx;
			if (cumul >= dy)
			{
				cumul -= dy;
				x += xinc;
			}
			ft_putpixel(ram, y * width + x , color);
			i++;
		}
	}
}

/*
** Test avec equation cartesienne
*/
	// int x;
	// int y;
	// double a;
	// double b;

	// a = (double)(dy / dx);
	// b =	y1 - (a * x1);
	// x = x1;
	// while (x1 <= x2)
	// {
	// 	y = (int)(a * x + b);
	// 	ft_putpixel(ram, y * width + x , 0xFFFFFF);
	// 	x++;
	// }

/*
** Bresenham sur 1/4 du repere
*/
	// int x;
	// int y;
	// int	dx;
	// int	dy;
	// int cumul;

	// x = x1;
	// y = y1;
	// dx = x2 - x1;
	// dy = y2 - y1;
	// ft_putpixel(ram, y * width + x , 0xFFFFFF);

	// cumul = dx / 2;
	// printf("dy :%d\tdx :%d\n", dy, dx);
	// x++;
	// while (x < x2)
	// {
	// 	cumul += dy;
	// 	printf("dy :%d\tcumul :%d\n", dy, cumul);
	// 	if (cumul >= dx)
	// 	{
	// 		cumul -= dx;
	// 		printf("dx :%d\tcumul :%d\n", dx, cumul);
	// 		y++;
	// 	}
	// 	printf("x :%d\ty :%d\n", x, y);
	// 	ft_putpixel(ram, y * width + x , 0xFFFFFF);
	// 	x++;
	// }

/*
** Bresenham super compact
*/
	// int x;
	// int y;
	// int	dx;
	// int	dy;
	// int cumul;
	// int xinc;
	// int yinc;
	// int i;

	// x = x1;
	// y = y1;
	// dx = x2 - x1;
	// dy = y2 - y1;
	// xinc = (dx > 0) ? 1 : -1;
	// yinc = (dy > 0) ? 1 : -1;
	// dx = abs(dx);
	// dy = abs(dy);

	// ft_putpixel(ram, y * width + x , 0xFFFFFF);

	// if (dx > dy)
	// {
	// 	cumul = dx / 2;
	// 	i = 1;
	// 	while (i < dx)
	// 	{
	// 		x += xinc;
	// 		cumul += dy;
	// 		if (cumul >= dx)
	// 		{
	// 			cumul -= dx;
	// 			y += yinc;
	// 		}
	// 		ft_putpixel(ram, y * width + x , 0xFFFFFF);
	// 		i++;
	// 	}
	// }
	// else
	// {
	// 	cumul = dy / 2;
	// 	i = 1;
	// 	while (i < dy)
	// 	{
	// 		y += yinc;
	// 		cumul += dx;
	// 		if (cumul >= dy)
	// 		{
	// 			cumul -= dy;
	// 			x += xinc;
	// 		}
	// 		ft_putpixel(ram, y * width + x , 0xFFFFFF);
	// 		i++;
	// 	}
	// }