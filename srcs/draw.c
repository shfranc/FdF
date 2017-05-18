/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 18:02:23 by sfranc            #+#    #+#             */
/*   Updated: 2017/05/18 19:24:02 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drawline(char *ram, int width, int x1, int y1, int x2, int y2)
{
	int x;
	int y;
	double a;
	double b;
	int	dx;
	int	dy;
	int px;
	int	py;


	dx = x2 - x1;
	dy = y2 - y1;
	
	px = x2 - x1 > 0 ? 1 : -1;
	py = x2 - x1 > 0 ? 1 : -1;
	
	a = (double)(dy / dx);
	b =	y1 - (a * x1);
	
	x = x1;
	while (x1 <= x2)
	{
		y = (int)(a * x + b);
		ft_putpixel(ram, y * width + x , 0xFFFFFF);
		x++;
	}
}
