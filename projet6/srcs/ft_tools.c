/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 11:17:14 by ebatchas          #+#    #+#             */
/*   Updated: 2019/01/29 15:15:20 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <math.h>
/*
char    *ft_ftoa(long double c, int preci)
{
	unsigned long long        i;
	char                    *nbr;

	write(1, "Called\n", 6);
	ft_putnbr(preci);
	nbr = (char *)malloc(sizeof(char) + 4294967295);
	if (c < 0)
	{
		nbr = ft_strjoin(nbr, "-");
		c = -c;
	}
	i = (unsigned long long int)c;
	if (preci < 15)
		c = (c - i) * pow(10, preci) + 0.5;
	else
		c = c - i;
	nbr = ft_strjoin(nbr, ft_itoa(i));
	nbr = ft_strjoin(nbr, ".");
	if (preci < 1)
		nbr = ft_strjoin(nbr, ft_itoa(c));
	else
		nbr = ft_strjoin(nbr, ft_ldouble_format(preci, c));
	return (nbr);
}
*/
char    *ft_ldouble_format(int preci, long double nb)
{
	int        i;
	int        nbr;
	char    *tmp;

	i = 0;
	write(1, "Called", 6);
	ft_putnbr(preci);
	tmp = (char *)malloc(sizeof(char)* 4294967295);
	while (preci)
	{
		nb *= 10;
		nbr = nb;
		nb = nb - nbr;
		tmp[i] = (nbr % 10) + '0';
		preci--;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
