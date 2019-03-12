/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 14:18:10 by ebatchas          #+#    #+#             */
/*   Updated: 2019/01/28 11:29:27 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_get_format(va_list ap, char *flags, char c)
{
	int		i;

	i = ft_strlen(flags);
	if (c == 'd' || c == 'i')
	{
		if (flags[i - 1] == 'h' || flags[i - 1] == 'l')
			return (ft_print_uintformat(ap, flags));
		return (ft_print_intformat(ap, flags));
	}
	if (c == 'c')
		return (ft_print_charformat(ap, flags));
	if (c == 's')
		return (ft_print_strformat(ap, flags));
	if (c == 'u')
		return (ft_print_uintformat(ap, flags));
	if (c == 'o')
		return (ft_print_octalformat(ap, flags));
	if (c == 'p')
		return (ft_print_pformat(ap, flags));
	if (c == '%')
		return (ft_print_percentformat(ap, flags));
	if (c == 'x' || c == 'X')
		return (ft_print_hexaformat(ap, flags, c));
	if (c == 'f')
	{
		if (flags[i - 1] == 'l')
			return (ft_print_doubleformat(ap, flags));
		return (ft_print_floatformat(ap, flags));
	}
	return (0);
}
