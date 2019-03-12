/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:16:57 by ebatchas          #+#    #+#             */
/*   Updated: 2019/02/05 18:43:28 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>
#include <math.h>

char	*ft_double_char(char *str, long n, long m, int i)
{
	char *str_b;

	while (i)
	{
		str_b = str;
		if (n & m)
			str = ft_strjoin(str, "1");
		else
			str = ft_strjoin(str, "0");
		//if (*str_b != NULL)
			free(str_b);
		n <<= 1;
		i--;
	}
	str_b = NULL;
	return (str);
}

char	*ft_double_array(t_double *d)
{
	char *str;

	str = ft_strdup("");
	str = ft_double_char(str, d->data.sign, 1, 1);
	str = ft_double_char(str, d->data.exponent, 1024, 11);
	str = ft_double_char(str, d->data.mantissa, 2251799813685248, 52);
	return (str);
}
