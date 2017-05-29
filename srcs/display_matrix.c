/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:59:16 by sfranc            #+#    #+#             */
/*   Updated: 2017/05/29 11:59:59 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fdf_display_matrix(t_map *map)
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

void	ft_fdf_display_matrix_down(t_map *map)
{
	t_map *temp_col;
	t_map *temp_row;

	temp_col = map;
	while (temp_col)
	{
		temp_row = temp_col;
		while (temp_row)
		{
			ft_putnbr(temp_row->z);
			if (temp_row->down)
				write(1, " ", 1);
			else
				write(1, "\n", 1);
			temp_row = temp_row->down;
		}
		temp_col = temp_col->next;
	}
}
