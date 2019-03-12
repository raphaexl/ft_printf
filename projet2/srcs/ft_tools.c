/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 11:17:14 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/26 14:53:17 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"

char    *ft_ftoa(long double c, int preci)
{
	unsigned long long        i;
	char                    *nbr;

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
	if (preci < 15)
		nbr = ft_strjoin(nbr, ft_itoa(c));
	else
		nbr = ft_strjoin(nbr, ldouble_format(preci, c));
	return (nbr);
}

char    *ldouble_format(int preci, long double nb)
{
	int        i;
	int        nbr;
	char    *tmp;

	i = 0;
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
