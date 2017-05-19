/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 17:47:18 by sfranc            #+#    #+#             */
/*   Updated: 2017/05/19 12:44:51 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"

# include <stdlib.h> // pour exit, abs

# include <stdio.h> // pour printf

typedef struct	s_pix
{
	unsigned char	blue;
	unsigned char	green;
	unsigned char	red;
	unsigned char	transp;
}				t_pix;

void	ft_putpixel(char *ram, int i, int code);

void	ft_drawline(char *ram, int width, int x1, int y1, int x2, int y2, int color);

int		ft_exit(int keycode, void *param);

#endif