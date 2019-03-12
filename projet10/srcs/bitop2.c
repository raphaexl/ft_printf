/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   bitop2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:03:41 by ebatchas          #+#    #+#             */
/*   Updated: 2019/01/29 16:13:17 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_l_test(long n)
{
	int i;
	long m;

	i = 48;
	m = 140737488355328;
	while (i)
	{
		if (n & m)
			write (1, "1", 1);
		else
			write (1, "0", 1);
		n <<= 1;
		i--;
	}
}

void	ft_print_l_sign(long n)
{
	if (n & 1)
		write (1, "1", 1);
	else
		write (1, "0", 1);
	//write (1, "\n", 1);
}

void	ft_print_l_mantissa(long n)
{
	int i;
	long m;

	i = 63;
	m = 4611686018427387904;
	while (i)
	{
		//printf("\nn : %ld\n", n);
		if (n & m)
			write (1, "1", 1);
		else
			write (1, "0", 1);
		n <<= 1;
		i--;
	}
	write (1, "\n", 1);
}

void	ft_print_l_exposant(long n)
{
	int i;
	long m;

	i = 15;
	m = 16384;
	while (i)
	{
		//printf("\nn : %ld\n", n);
		if (n & m)
			write (1, "1", 1);
		else
			write (1, "0", 1);
		n <<= 1;
		i--;
	}
	//write (1, "\n", 1);
}

void	print_l_double(t_l_double *d)
{
	ft_print_l_sign(d->data.sign);
	ft_print_l_exposant(d->data.exponent);
	ft_print_l_mantissa(d->data.mantissa);
	return ;
}
