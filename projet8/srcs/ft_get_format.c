/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 14:18:10 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/07 21:16:09 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_init_flags(t_flag *g)
{
	g->minus = 0;
	g->plus = 0;
	g->zero = 0;
	g->space = 0;
	g->zero = 0;
	g->width = 0;
	g->size = 0;
	g->prec = 6;
}

int		ft_process_flags(t_flag *f, char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '-')
			f->minus = 1;
		if (str[i] == '+')
			f->plus = 1;
		if (str[i] == '0')
			f->zero = 1;
		if (str[i] == ' ')
			f->space = 1;
		if (i > 0 && str[i - 1] == '.' && str[i] >= '0' && str[i] <= '9')
		{
			f->prec = ft_atoi(str + i);
			i += ft_size_base(f->width, 10);
		}
		if (!f->width && str[i] >= '1' && str[i] <= '9')
		{
			f->width = ft_atoi(str + i);
			i += ft_size_base(f->width, 10);
		}
		if (str[i] == 'l' || str[i] == 'L')
		{
			if (str[i + 1] == 'l')
				f->size = 2;
			else
				f->size = 1;
		}
		if (str[i] == 'z')
			f->size = 1;
	}
	return (i);
}


int		ft_apply_format(t_flag *f, char	*buffer, char c)
{
	if (c == 'd' || c == 'i')
		return (ft_process_formati(f, buffer));
	else if (c == 'f')
		return (ft_process_formatf(f, buffer));
	else if (c == 'e' || c == 'E')
		return (ft_process_formate(f, buffer));
	else if (c == 'g' || c == 'G')
		return (ft_process_formatg(f, buffer));
	else if (c == 'c')
		return (ft_process_formatc(f, buffer));
	else if (c == 'x' || c == 'X' || c == 'o' || c == 'u')
		return (ft_process_formatuox(f, buffer));
	else if (c == 's')
		return (ft_process_formats(f, buffer));
	else if (c == 'p')
		return (ft_process_formatp(f, buffer));
	else if (c == '%')
		return (ft_process_format1(f, buffer));
	else
		return (0);
}

int		ft_get_format(va_list ap, char *flags, char c)
{
	t_flag	f;

	ft_init_flags(&f);
	ft_process_flags(&f, flags);
	int		i;

	i = ft_strlen(flags);
	if (c == 'd' || c == 'i')
	{
		if (flags[i - 1] == 'h' || flags[i - 1] == 'l')
			flags = ft_print_uintformat(ap, flags);
		flags = ft_print_intformat(ap, flags);
	}
	else if (c == 'c')
		flags = ft_print_charformat(ap, flags);
	else if (c == 's')
		flags = ft_print_strformat(ap, flags);
	else if (c == 'u')
		flags = ft_print_uintformat(ap, flags);
	else if (c == 'o')
		flags = ft_print_octalformat(ap, flags);
	else if (c == 'p')
		flags = ft_print_pformat(ap, flags);
	else if (c == '%')
		flags = ft_print_percentformat(ap, flags);
	else if (c == 'x' || c == 'X')
		flags = ft_print_hexaformat(ap, flags, c);
	else if (c == 'f')
	{
		if (flags[i - 1] == 'l')
			flags = ft_print_doubleformat(ap, flags);
		else if (flags[i - 1] == 'L')
			flags = ft_print_ldoubleformat(ap, flags);
		else
			flags = ft_print_floatformat(ap, flags);
	}
	return (ft_apply_format(&f, flags, c));
}

