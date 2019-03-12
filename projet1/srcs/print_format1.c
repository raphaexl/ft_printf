/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 13:09:46 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/26 15:03:30 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_pformat(va_list ap, char *flag)
{
	int		n;
	char	*str;

	(void)flag;
	n = va_arg(ap, int);
	str = ft_strjoin("0x", ft_itoa_base(n, 16));
	ft_putstr(str);
	return (ft_strlen(str));
}

int		ft_print_octalformat(va_list ap, char *flag)
{
	int		n;
	char	*str;

	(void)flag;
	n = va_arg(ap, int);
	str = ft_itoa_base(n, 8);
	ft_putstr(str);
	return (ft_strlen(str));
}

int		ft_print_hexaformat(va_list ap, char *flag, int c)
{
	unsigned int	n;
	char			*str;

	(void)flag;
	n = va_arg(ap, unsigned int);
	str = ft_itoa_base(n, 16);
	if (c == 'X')
		str = ft_strjoin("0X", ft_strcapitalize(str));
	else
		str = ft_strjoin("0x", str);
	ft_putstr(str);
	return (ft_strlen(str));
}

int		ft_print_floatformat(va_list ap, char *flag)
{
	double 		n;
	char		*str;

	(void)flag;
	n = va_arg(ap, double);
	str = ft_ftoa(n, 6);
	ft_putstr(str);
	return (ft_strlen(str));
}

int		ft_print_doubleformat(va_list ap, char *flag)
{
	long double n;
	char		*str;

	(void)flag;
	n = va_arg(ap, long double);
	str = ft_ftoa(n, 6);
	ft_putstr(str);
	return (ft_strlen(str));
}
