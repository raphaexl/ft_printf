/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 11:28:51 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/11 20:57:17 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_check_alias(t_conv *conv)
{
	if (ft_strchr("EFG", conv->type))
	{
		conv->modif = LF;
		conv->type = ft_tolower(conv->type);
	}
	if (!conv->prec_set)
		conv->precision = 6;
}

static char	*ft_process_float(t_conv *conv, char *buffer)
{
	buffer	=	ft_handle_precision(buffer, conv->precision);
	if (conv->flag->plus || conv->flag->space)
	{
		if (buffer[0] != '-')
		{
			if (conv->flag->space)
				buffer = ft_strjoin(" ", buffer);
			else
				buffer = ft_strjoin("+", buffer);
		}
	}
	if (!conv->flag->minus && conv->flag->zero)
		buffer = ft_strleftjoin("0", buffer, conv->min_width);
	if (conv->flag->minus)
		buffer = ft_strleftjoin(" ", buffer, conv->min_width);
	else if (conv->min_width)
		buffer = ft_strrightjoin(" ", buffer, conv->min_width);
	return (buffer);
}

void		ft_print_float_conv(t_conv *conv, va_list ap)
{
	char	*buffer;

	ft_check_alias(conv);
	buffer = ft_get_float_signed(conv, ap);
	if (buffer[0] == '-')
		conv->sign = '-';
	else if (conv->flag->plus)
		conv->sign = '+';
	else if (conv->flag->space)
		conv->sign = ' ';
	buffer = ft_process_float(conv, buffer);
	ft_tally_print(buffer, ft_strlen(buffer));
	free(buffer);
	buffer = NULL;
}
