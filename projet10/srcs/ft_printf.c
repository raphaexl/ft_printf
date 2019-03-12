/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 22:30:54 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/09 11:34:58 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_is_format(char c)
{
	static	char	*tab = "cspdiouexXbvgrkf%";
	int				i;

	i = -1;
	while (tab[++i])
		if (tab[i] == c)
			return (1);
	return (0);
}

int		ft_is_token(char c, char k)
{
	return (c == k);
}

int		ft_flags(char c, char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

static char	*ft_print_until(char *str, char c)
{
	while (*str != '\0' && *str != c)
		ft_tally_print(str++, 1);
	return (str);
}

int			ft_printf(const char *format, ...)
{
	va_list			ap;
	char			*str;

	va_start(ap, format);
	str = (char *)format;
	while (*str != '\0')
	{
		str = ft_print_until(str, '%');
		if (*str == '%')
			str++;
		if (*str != '\0')
			str = ft_print_conversion(str, ap);
	}
	va_end(ap);
	return (ft_tally_get(0, 0));
}

uintmax_t	ft_digitc(uintmax_t n)
{
	uintmax_t	count;

	count = 1;
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}
