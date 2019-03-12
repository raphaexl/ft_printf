/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   bitop.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:03:41 by ebatchas          #+#    #+#             */
/*   Updated: 2019/01/29 16:13:17 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_mantissa(long n)
{
	int i = 52;
	long m = 2251799813685248;
	while (i)
	{
		if (n & m)
			write (1, "1", 1);
		else
			write (1, "0", 1);
		n <<= 1;
		i--;
	}
	write (1, "\n", 1);
}

void	ft_print_exposant(long n)
{
	int i;
	long m;

	i = 11;
	m = 1024;
	while (i)
	{
		if (n & m)
			write (1, "1", 1);
		else
			write (1, "0", 1);
		n <<= 1;
		i--;
	}
	write (1, "\n", 1);
}

void	ft_print_signe(long n)
{
	if (n & 1)
		write (1, "1", 1);
	else
		write (1, "0", 1);
	write (1, "\n", 1);
}

void	print_double(t_double *d)
{
	ft_print_signe(d->data.sign);
	ft_print_exposant(d->data.exponent);
	ft_print_mantissa(d->data.mantissa);
	return ;
}
