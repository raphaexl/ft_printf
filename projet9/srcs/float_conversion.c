/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 12:05:39 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/09 13:03:07 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_double(double n)
{
	t_double	d;
	
	d.d = n;
	return (ft_pre_cal(&d));
}

static char	*ft_ldouble(long double n)
{
	t_l_double	d;

	d.d = n;
	return (ft_l_pre_cal(&d));
}

char	*ft_get_float_signed(t_conv *conv, va_list ap)
{
	if (conv->type == 'f')
	{
		if (conv->modif == L)
			return (ft_double(va_arg(ap, double)));
		else
			return (ft_double((float)va_arg(ap, double)));
	}
	else
		return (ft_ldouble(va_arg(ap, long double)));
}
