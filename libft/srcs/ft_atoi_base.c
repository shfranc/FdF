/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 17:21:28 by sfranc            #+#    #+#             */
/*   Updated: 2017/05/25 21:38:18 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_base(char *str, int base)
{
	static char	tab[16] = "0123456789ABCDEF";
	char	*check;
	long int	nb;
	int			sign;

	if (base < 2 || base > 16)
		return (0);

	nb = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;

	while (*str && (check = ft_strchr(tab, *str)) && *check && check - tab < base)
	{
		nb = nb * base + check - tab;
		str++;
	}
	return ((int)(nb * sign));
}
