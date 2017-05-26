/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 17:47:18 by sfranc            #+#    #+#             */
/*   Updated: 2017/05/26 18:00:25 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include <fcntl.h> // open
# include <math.h>

# include <stdlib.h> // pour exit, abs

# define	MARGIN 50
# define	MAXWIDTH (2560 - MARGIN)
# define	MAXHEIGHT (1315 -  MARGIN)


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
	float			iso_x;
	float			iso_y;
	// int 			new_x;
	// int 			new_y;
	struct s_map	*next;
	struct s_map	*down;
}				t_map;

typedef struct	s_draw
{
	int				nb_row;
	int				nb_col;
	int				scale;
	int				xmin;
	int				xmax;
	int				ymin;
	int				ymax;
	int				height;
	int				img_width;
	int				img_height;
}				t_draw;

typedef struct s_holder
{
	void			*mlx;
	void			*win;
	void			*img;
	t_map 			*map;
	t_draw 			draw;
}				t_holder;

void	ft_init_draw(t_draw *draw);
void	ft_init_scale(t_draw *draw);

void	ft_fetch_dim(t_map *map, t_draw *draw);
void	ft_init_dim(t_draw *draw);

t_map	*ft_get_data(char *path, t_draw *draw);


void	ft_scale_up(t_map *map, int gap);
void	ft_isometric_projection(t_map *map, t_draw *draw);
void	ft_center_origin(t_map *map, t_draw *draw);

void	*ft_fill_image(void *mlx, t_map *map, t_draw *draw);

void	ft_putpixel(char *ram, int i, int code);

// void	ft_drawline(char *ram, int width, int x1, int y1, int x2, int y2, int color);
void	ft_drawline(char *ram, t_draw *draw, t_map *pt_x, t_map *pt_y);

int		ft_events(int keycode, void *param);

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