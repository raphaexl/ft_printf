/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 13:09:46 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/06 21:01:36 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_print_pformat(va_list ap, char *flag)
{
	long int		n;

	(void)flag;
	n = va_arg(ap, long long int);
	return (ft_strjoin("0x", ft_itoa_base(n, 16)));
}

char	*ft_print_octalformat(va_list ap, char *flag)
{
	int		n;

	(void)flag;
	n = va_arg(ap, int);
	return (ft_itoa_base(n, 8));
}

char	*ft_print_hexaformat(va_list ap, char *flag, int c)
{
	unsigned int	n;
	char			*str;

	(void)flag;
	n = va_arg(ap, unsigned int);
	str = ft_itoa_base(n, 16);
	if (c == 'X')
		str = ft_strcapitalize(str);
	return (str);
}

char	*ft_print_floatformat(va_list ap, char *flag)
{
	float	n;

	(void)flag;
	n = (float)va_arg(ap, double);
	return (ft_double(n, 6));
}

char	*ft_print_doubleformat(va_list ap, char *flag)
{
	double n;

	(void)flag;
	n = va_arg(ap,  double);
	return (ft_double(n, 6));
}

char	*ft_print_ldoubleformat(va_list ap, char *flag)
{
	long double n;

	(void)flag;
	n = va_arg(ap, long double);
	return (ft_ldouble(n, 6));
}
