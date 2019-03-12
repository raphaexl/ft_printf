/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 18:29:58 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/12 18:30:35 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
