/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 11:21:41 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/26 14:53:33 by ebatchas         ###   ########.fr       */
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

char	*ft_ftoa(long double n, int precision)
{
	unsigned long long 		i;
	char					*nb;

	nb = (char *)malloc(sizeof(char) * UINT_MAX);
	if ((n < 0) && (n = -n))
		nb = ft_strjoin(nb, "-");
	i = (unsigned long long int)n;
	if (precision < 15)
		n = (n - i) * ft_pow(10, precision) + 0.5;
	else
		n = (n - i);
	nb = ft_strjoin(nb, ft_itoa(i));
	nb = ft_strjoin(nb, ".");
	if (precision < 15)
		nb = ft_strjoin(nb, ft_itoa(n));
	else
		nb = ft_strjoin(nb, ft_ldouble(n, precision));
	return (nb);
}

char	*ft_ldouble(long double n, int precision)
{
	int		i;
	int		nbr;
	char	*nb;

	i = 0;
	nb = (char *)malloc(sizeof(char) * UINT_MAX);
	while (precision)
	{
		n *= 10;
		nbr = n;
		n = n - nbr;
		nb[i] = (nbr % 10) + '0';
		precision--;
		i++;
	}
	nb[i] = '\0';
	return (nb);
}
