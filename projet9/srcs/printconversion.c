/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printconversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 10:41:23 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/09 12:21:12 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_check_if_alias(t_conv *conv)
{
	if (ft_strchr("DOU", conv->type))
	{
		conv->modif = L;
		conv->type = ft_tolower(conv->type);
	}
	else if (conv->type == 'i')
		conv->type = 'd';
	else if (conv->type == 'p')
	{
		conv->modif = L;
		conv->flag->hash = 1;
	}
}

static void		ft_print_num_conv(t_conv *conv, va_list ap)
{
	intmax_t	num;

	ft_check_if_alias(conv);
	if (conv->type == 'd')
	{
		num = ft_get_conv_signed(conv, ap);
		if (num < 0 && (num *= -1))
			conv->sign = '-';
		else if (conv->flag->plus)
			conv->sign = '+';
		else if (conv->flag->space)
			conv->sign = ' ';
	}
	else
		num = ft_get_conv_unsigned(conv, ap);
	if (ft_strchr("du", conv->type))
		ft_print_u(conv, (uintmax_t)num);
	else if (conv->type == 'o')
		ft_print_o(conv, (uintmax_t)num);
	else if (ft_strchr("xp", conv->type))
		ft_print_x(conv, (uintmax_t)num);
	else if (conv->type == 'X')
		ft_print_x_caps(conv, (uintmax_t)num);
}

static void		ft_print_str_conv(t_conv *conv, va_list ap)
{
	if (ft_strchr("CS", conv->type))
	{
		conv->modif = L;
		conv->type = ft_tolower(conv->type);
	}
	if (conv->modif == L)
	{
		if (conv->type == 'c')
			ft_print_wchar(conv, va_arg(ap, wint_t));
		else if (conv->type == 's')
			ft_print_wstr(conv, va_arg(ap, wchar_t*));
		else
			ft_print_char(conv, conv->type);
	}
	else
	{
		if (conv->type == 'c')
			ft_print_char(conv, va_arg(ap, int));
		else if (conv->type == 's')
			ft_print_str(conv, va_arg(ap, char*));
		else
			ft_print_char(conv, conv->type);
	}
}

char			*ft_print_conversion(char *str, va_list ap)
{
	t_conv	*conv;

	conv = ft_new_conversion(str);
	str = ft_parse_conversion(str, conv);
	if (ft_strchr("idDoOuUxXp", conv->type))
		ft_print_num_conv(conv, ap);
	else if (ft_strchr("gefFGE", conv->type))
		ft_print_float_conv(conv, ap);
	else
		ft_print_str_conv(conv, ap);
	ft_del_conversion(conv);
	return (str);
}
