/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 10:33:01 by sfranc            #+#    #+#             */
/*   Updated: 2017/05/22 18:59:48 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_len_line(char *line)
{
	char **temp;
	int len;

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
			elem = ft_fdf_listnew(i, row, ft_atoi(temp[0]), 0);
		else
			elem = ft_fdf_listnew(i, row, ft_atoi(temp[0]), 0xFFFF); // faire un convbase de char base 16 a 10 (atoi_base ?)...
		ft_fdf_lstaddlast(&head, elem);
		ft_freetab(&temp);
		i++;
	}
	ft_freetab(&tab);
	return (head);
}

t_map	*ft_get_data(char *path)
{
	t_map *map;
	t_map *row;
	char *line;
	int fd;
	int	len;
	int nb_row;

	errno = 0;
	map = NULL;
	if ((fd = open(path, O_RDONLY)) == -1)
		ft_exit(ft_strjoin("No file ", path), 1);
	len = 0;
	nb_row = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (!len)
			len = ft_len_line(line);
		else if (len != ft_len_line(line))
			ft_exit("Found wrong line length. Exiting.", 1);
		row = ft_get_row(nb_row, line);
		ft_fdf_lstlinkdown(&map, row);
		nb_row++;
		ft_strdel(&line);
	}
	ft_fdf_display_matrix(map);
	if (!map)
		ft_exit("No data found.", 1);
	return (map);
}
