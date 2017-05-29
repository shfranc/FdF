/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 17:49:43 by sfranc            #+#    #+#             */
/*   Updated: 2017/05/29 17:18:30 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putpixel(char *ram, int i, int color)
{
	*(ram + i * 4 + 0) = (color & PIX_BLUE);
	*(ram + i * 4 + 1) = (color & PIX_GREEN) >> 8;
	*(ram + i * 4 + 2) = (color & PIX_RED) >> 16;
	*(ram + i * 4 + 3) = 0;
}

// void	ft_putpixel(char *ram, int i, int code, int endian)
// {
// 	t_pix	*pix;
// 	char	*color;

// 	pix = (t_pix*)(ram + i * 4);
// 	color = (char*)&code;
// 	if (endian == 0)
// 	{
// 		pix->blue = color[0];
// 		pix->green = color[1];
// 		pix->red = color[2];
// 		pix->transp = 0;
// 	}
// 	else if (endian == 1)
// 	{
// 		pix->blue = color[3];
// 		pix->green = color[2];
// 		pix->red = color[1];
// 		pix->transp = 0;
// 	}
// }