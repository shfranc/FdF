/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 11:58:44 by sfranc            #+#    #+#             */
/*   Updated: 2017/05/22 18:51:24 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*ft_fdf_listnew(int x, int y, int z, int color)
{
	t_map *elem;

	if (!(elem = (t_map*)malloc(sizeof(t_map))))
		ft_exit("Unable to malloc", 1);
	elem->x = x;
	elem->y = y;
	elem->z = z;
	elem->color = color;
	elem->next = NULL;
	elem->down = NULL;
	return (elem);
}

void	ft_fdf_lstaddlast(t_map **head, t_map *new)
{
	t_map *temp;

	if (!head)
		return ;
	if (*head == NULL)
		*head = new;
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

void	ft_fdf_lstlinkdown(t_map **head, t_map *row)
{
	t_map *temp;
	t_map *under;

	if (!head)
		return ;
	if (*head == NULL)
		*head = row;
	else
	{
		temp = *head;
		while (temp->down)
			temp = temp->down;
		temp->down = row;
		
		temp = temp->next;
		under = row->next;
		while (temp)
		{
			temp->down = under;
			temp = temp->next;
			under = under->next;
		}
	}
}

void	ft_fdf_lstdel(t_map **head)
{
	t_map	*temp_row;
	t_map	*temp_col;
	t_map	*suppr;

	if (!head && !*head)
		return ;
	temp_row = *head;
	while (temp_row)
	{
		temp_col = temp_row->next;
		while (temp_col)
		{
			suppr = temp_col;
			temp_col = temp_col->next;
			free(suppr);
		}
		suppr = temp_row;
		temp_row = temp_row->down;
		free(suppr);
	}
	*head = NULL;
}

void	ft_fdf_display_matrix(t_map *map) // debug mais a conserver
{
	t_map *temp_row;
	t_map *temp_col;

	temp_row = map;
	while (temp_row)
	{
		temp_col = temp_row;
		while (temp_col)
		{
			ft_putnbr(temp_col->x);
			if (temp_col->next)
				write(1, " ", 1);
			else
				write(1, "\n", 1);
			temp_col = temp_col->next;
		}
		temp_row = temp_row->down;
	}
}

void	ft_fdf_display_matrix_down(t_map *map) // debug mais a conserver
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
