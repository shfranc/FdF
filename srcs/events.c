/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 17:49:29 by sfranc            #+#    #+#             */
/*   Updated: 2017/05/22 18:24:57 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_escape(int keycode, void *param)
{
	(void)param;
	ft_putstr("Keycode :");
	ft_putnbr_endl(keycode);
	if (keycode != 53)
		return (0);
	exit(0);
	return (0);
}
