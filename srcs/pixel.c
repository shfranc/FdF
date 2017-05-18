/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 17:49:43 by sfranc            #+#    #+#             */
/*   Updated: 2017/05/18 18:28:18 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putpixel(char *ram, int i, int code) // inclure un mode pour l'endian
{
	t_pix	*pix;
	char *color;

	pix = (t_pix*)(ram + i * 4);
	color = (char*)&code;
	pix->blue = color[0];
	pix->green = color[1];
	pix->red = color[2];
	pix->transp = color[3];
}