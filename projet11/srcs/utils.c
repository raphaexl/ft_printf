/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 11:21:41 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/09 11:54:38 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <math.h>

long double		ft_fabs(long double base)
{
	return (base < 0.0 ? -(base) : base);
}

long double		ft_pow(long double base, int puiss)
{
	long double		res;

	res = 1.0;
	if (puiss < 0)
	{
		base = 1.0 / base;
		puiss = -puiss;
	}
	while (puiss)
	{
		if (puiss & 1)
			res *= base;
		puiss >>= 1;
		base *= base;
	}
	return (res);
}


