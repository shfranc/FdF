/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 17:21:28 by sfranc            #+#    #+#             */
/*   Updated: 2017/05/26 16:46:43 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_base(char *str, int base)
{
	static char	tab[16] = "0123456789ABCDEF";
	char 	*copy;
	char	*tmp;
	long	nb;
	int		sign;

	if (base < 2 || base > 16)
		return (0);
	copy = ft_strmap(str, &ft_upcase);
	nb = 0;
	sign = 1;
	tmp = copy;
	while (*tmp == ' ' || (*tmp >= 9 && *tmp <= 13))
		tmp++;
	if (*tmp == '-')
		sign = -1;
	if (*tmp == '+' || *tmp == '-')
		tmp++;
	while (*tmp && ft_strchr(tab, *tmp) && ft_strchr(tab, *tmp) - tab < base)
	{
		nb = nb * base + ft_strchr(tab, *tmp) - tab;
		tmp++;
	}
	free(copy);
	return ((int)(nb * sign));
}
