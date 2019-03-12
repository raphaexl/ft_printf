/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 14:08:56 by ebatchas          #+#    #+#             */
/*   Updated: 2018/12/26 14:50:02 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_charformat(va_list ap, char *flag)
{
	int		n;

	(void)flag;
	n = va_arg(ap, int);
	write(1, &n, 1);
	return (1);
}

int		ft_print_strformat(va_list ap, char *flag)
{
	char			*str;

	(void)flag;
	str = va_arg(ap, char *);
	ft_putstr(str);
	return (ft_strlen(str));
}

int		ft_print_percentformat(va_list ap, char *flag)
{
	unsigned int	n;
	char			*str;

	(void)flag;
	n = va_arg(ap, unsigned int);
	str = ft_itoa(n);
	ft_putstr(str);
	return (ft_strlen(str));
}

int		ft_print_intformat(va_list ap, char *flag)
{
	int		n;
	char	*str;

	(void)flag;
	n = va_arg(ap, int);
	str = ft_itoa(n);
	ft_putstr(str);
	return (ft_strlen(str));
}

int		ft_print_uintformat(va_list ap, char *flag)
{
	unsigned int	n;
	char			*str;

	(void)flag;
	n = va_arg(ap, unsigned int);
	str = ft_itoa(n);
	ft_putstr(str);
	return (ft_strlen(str));
}
