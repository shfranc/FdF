/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 17:47:18 by sfranc            #+#    #+#             */
/*   Updated: 2017/05/23 15:25:05 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include <fcntl.h> // open
# include <math.h>

# include <stdlib.h> // pour exit, abs

# include <stdio.h> // pour printf

# define	MARGIN 75
# define	MAXWIDTH 2560 - MARGIN
# define	MAXHEIGHT 1315 -  MARGIN


typedef struct	s_pix
{
	unsigned char	blue;
	unsigned char	green;
	unsigned char	red;
	unsigned char	transp;
}				t_pix;

typedef struct s_map
{
	int				x;
	int				y;
	int				z;
	int				color;
	struct s_map	*next;
	struct s_map	*down;
}				t_map;

typedef struct	s_draw
{
	int			nb_row;
	int			nb_col;
	int			gap;
	int			img_width;
	int			img_height;
	int			win_width;
	int			win_height;
}				t_draw;

t_map	*ft_get_data(char *path, t_draw *draw);

void	*ft_fill_image(void *mlx, t_map *map, t_draw *draw);

void	ft_putpixel(char *ram, int i, int code);

void	ft_drawline(char *ram, int width, int x1, int y1, int x2, int y2, int color);

int		ft_escape(int keycode, void *param);

/*
** fdf linked lists
*/
t_map	*ft_fdf_listnew(int x, int y, int z, int color);
void	ft_fdf_lstaddlast(t_map **head, t_map *new);
void	ft_fdf_lstlinkdown(t_map **head, t_map *row);
void	ft_fdf_lstdel(t_map **map);
void	ft_fdf_display_matrix(t_map *map);
void	ft_fdf_display_matrix_down(t_map *map);

#endif