/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 11:17:14 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/06 16:09:41 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <math.h>

#define maxlen(x,y) ((x >= y) ? x + 1 : y + 1)

void	ft_debug(void)
{
	write(2, "error before here !\n", 20);
	exit(0);
}

char    *ft_ldouble_format(int preci, long double nb)
{
	int        i;
	int        nbr;
	char    *tmp;

	i = 0;
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

char	*ft_strrev(char *str)
{
	int		i;
	int		length;
	char	buff;

	i = 0;
	length = ft_strlen(str);
	while (length - 1 > i)
	{
		buff = str[i];
		str[i] = str[length - 1];
		str[length - 1] = buff;
		length--;
		i++;
	}
	return (str);
}

void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_swapstr(char **a, char **b)
{
	char *c;

	c = *a;
	*a = *b;
	*b = c;
}

char	*ft_newstr(size_t size)
{
	char	*str;

	str = (char*)malloc(size + 1);
	ft_memset(str, 0, size + 1);
	return (str);
}
