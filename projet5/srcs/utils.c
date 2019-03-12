/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 11:21:41 by ebatchas          #+#    #+#             */
/*   Updated: 2019/01/31 15:58:56 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <math.h>

long double		ft_fabs(long double base)
{
	return (base < 0.0 ? -(base) : base);
}

double	 ft_floor(double x)
{
	if (x == 0.0)
		return (0.0);
	union 
	{
		double input;
		int output;
	}data;

	data.input = x;

	int exp = data.output & (255 << 23);
	exp = exp >> 23;

	int man = data.output & ((1 << 23) - 1);
	int pow = exp - 127;
	int mult_factor = 1;

	int i = abs(pow);
	while (i--)
		mult_factor *= 2;

	unsigned long long denominator = 1 << 23;
	unsigned long long numerator = man + denominator;

	int negative = (data.output >> 31) != 0;
	if (pow < 0)
		denominator *= mult_factor;
	else
		numerator *= mult_factor;
	double res = 0.0;
	while (numerator >= denominator)
	{
		++res;
		numerator -= denominator;
	}
	if (negative)
	{
		res = -res;
		if (numerator != 0)
			res -= 1.0;
	}
	return (res);
}

double	ft_fmod(double a, double b)
{
	return ((a - b * floor(a / b)));
}

double 	ft_modf(long double nb, double *n)
{
	*n = floor(nb);
	return (nb - *n);
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

char  	*ft_itoa2(long double nb)
{
	char conversion[1076];
	char  temp[311];
	int 	 i = 0;
	int 	n = 0;

	i = 0;
	n = 0;
	if (nb < 0)
		conversion[i++] = '-';
	while (nb > 0)
	{
		temp[n++] = '0' + (int)fmod(nb, 10);
		nb = floor(nb/10);
	}
	i -= 1;
	while (++i < n)
		conversion[i] = temp[n-i-1];
	conversion[i] = '\0';
	return (ft_strdup(conversion));
}

char	*ft_ftoa(long double nb, int precision)
{
	char 	*temp;
	int  	i;
	double 	n;

	i = 0;
	nb = ft_modf(nb, &n);
	temp = ft_itoa2(n);
	temp = ft_strjoin(temp , ".");
	while (nb < 0.1 && nb > -0.1 && i < precision - 1)
	{
		nb *= 10;
		temp = ft_strjoin(temp, "0");
		i++;
	}	
	if (precision < 15)
	{
		n = nb * ft_pow(10, precision - i);
		n = (nb * ft_pow(10, precision - i) - n > 0.01) ? n + 1 : n;
		temp = ft_strjoin(temp, ft_itoa(n));
	}
	else
		temp = ft_strjoin(temp, ft_ldouble(n, precision));
	return (temp);
}

char	*ft_ldouble(long double n, int precision)
{
	int		i;
	double	nbr;
	char	*nb;

	i = 0;
	nb = (char *)malloc(sizeof(char) * UINT_MAX);
	while (precision)
	{
		n *= 10;
		n = ft_modf(n, &nbr);
		nb[i] =  (int)nbr + '0';
		precision--;
		i++;
	}
	nb[i] = '\0';
	return (nb);
}
