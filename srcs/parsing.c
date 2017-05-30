/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 10:33:01 by sfranc            #+#    #+#             */
/*   Updated: 2017/05/30 11:57:35 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_len_line(char *line)
{
	char	**temp;
	int		len;

	temp = ft_strsplit(line, ' ');
	len = ft_tablen(temp);
	ft_freetab(&temp);
	return (len);
}

static t_map	*ft_get_row(int row, char *line)
{
	t_map	*elem;
	t_map	*head;
	char	**tab;
	char	**temp;
	int		i;

	tab = ft_strsplit(line, ' ');
	head = NULL;
	i = 0;
	while (tab[i])
	{
		temp = ft_strsplit(tab[i], ',');
		if (ft_tablen(temp) == 1)
			elem = ft_fdf_listnew(i, -1 * row, -1 * ft_atoi(temp[0]), 0xFFFFFF);
		else
		{
			elem = ft_fdf_listnew(i, -1 * row, -1 * ft_atoi(temp[0]),\
				ft_atoi_base((*(temp + 1) + 2), 16));
		}
		ft_fdf_lstaddlast(&head, elem);
		ft_freetab(&temp);
		i++;
	}
	ft_freetab(&tab);
	return (head);
}

void			ft_fdf_display_matrix(t_map *map)
{
	t_map *temp_row;
	t_map *temp_col;

	temp_row = map;
	while (temp_row)
	{
		temp_col = temp_row;
		while (temp_col)
		{
			ft_putnbr(temp_col->z);
			if (temp_col->next)
				write(1, " ", 1);
			else
				write(1, "\n", 1);
			temp_col = temp_col->next;
		}
		temp_row = temp_row->down;
	}
}

t_map			*ft_get_data(char *path, t_draw *draw)
{
	t_map	*map;
	t_map	*row;
	char	*line;
	int		fd;

	map = NULL;
	if ((fd = open(path, O_RDONLY)) == -1)
		ft_exit(ft_strjoin("No file ", path), 1);
	while (get_next_line(fd, &line) == 1)
	{
		if (!draw->nb_col)
			draw->nb_col = ft_len_line(line);
		else if (draw->nb_col != ft_len_line(line))
			ft_exit("Found wrong line length. Exiting.", 1);
		row = ft_get_row(draw->nb_row, line);
		ft_fdf_lstlinkdown(&map, row);
		draw->nb_row++;
		ft_strdel(&line);
	}
	if (!map)
		ft_exit("No data found.", 1);
	return (map);
}
