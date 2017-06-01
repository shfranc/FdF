/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 17:47:18 by sfranc            #+#    #+#             */
/*   Updated: 2017/06/01 11:01:48 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# define PIX_BLUE 0xFF
# define PIX_GREEN 0xFF00
# define PIX_RED 0xFF0000
# define MARGIN 50
# define MAXWIDTH (2560 - MARGIN)
# define MAXHEIGHT (1315 - MARGIN)

typedef struct	s_map
{
	int				x;
	int				y;
	int				z;
	int				ori_x;
	int				ori_y;
	int				ori_z;
	int				color;
	int				res_color;
	int				iso_x;
	int				iso_y;
	int				res_x;
	int				res_y;
	struct s_map	*next;
	struct s_map	*down;
}				t_map;

typedef struct	s_draw
{
	int				nb_row;
	int				nb_col;
	int				scale;
	int				zoom;
	int				xmin;
	int				xmax;
	int				ymin;
	int				ymax;
	int				zmin;
	int				zmax;
	int				height;
	int				img_width;
	int				img_height;
	int				start_x;
	int				start_y;
	int				dx;
	int				dy;
	int				xinc;
	int				yinc;
}				t_draw;

typedef struct	s_holder
{
	void			*mlx;
	void			*win;
	void			*img;
	t_map			*map;
	t_draw			draw;
}				t_holder;

/*
** Parsing & initialization
*/
t_map			*ft_get_data(char *path, t_draw *draw);
void			ft_fetch_height(t_map *map, t_draw *draw);
void			ft_init_scale(t_draw *draw);
void			ft_fetch_dim(t_map *map, t_draw *draw);
void			ft_init_dim(t_draw *draw);

/*
** Projection and drawing
*/
void			ft_scale_up(t_map *map, int gap);
void			ft_isometric_projection(t_map *map, t_draw *draw);
void			ft_cavaliere_projection(t_map *map, t_draw *draw);
void			ft_center_origin(t_map *map, t_draw *draw);
void			*ft_fill_image(void *mlx, t_map *map, t_draw *draw);
void			ft_drawline(char *ram, t_draw *draw, t_map *pt_x, t_map *pt_y);

/*
** Events handler
*/
int				ft_events(int keycode, void *param);
void			ft_change_origin(int keycode, t_holder *hold);
void			ft_change_color(int keycode, t_holder *hold);
void			ft_zoom_in(t_holder *hold);
void			ft_zoom_out(t_holder *hold);

/*
** Display manual
*/
void			ft_win_display_menu(t_holder *hold);

/*
** fdf linked lists
*/
t_map			*ft_fdf_listnew(int x, int y, int z, int color);
void			ft_fdf_lstaddlast(t_map **head, t_map *new);
void			ft_fdf_lstlinkdown(t_map **head, t_map *row);
void			ft_fdf_lstdel(t_map **map);

#endif
