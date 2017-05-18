/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 17:49:29 by sfranc            #+#    #+#             */
/*   Updated: 2017/05/18 17:50:46 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_exit(int keycode, void *param)
{
	(void)param;
	printf("Keycode :%d\n", keycode);
	if (keycode != 53)
		return (0);
	exit(0);
	return (0);
}
