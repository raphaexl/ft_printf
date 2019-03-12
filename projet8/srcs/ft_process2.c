/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:01:54 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/09 13:02:58 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_process_formatf(t_flag *f, char *buffer)
{
	int		len = 0;

	if (f->plus || f->space)
	{
		if (buffer[0] != '-')
		{
			if (f->space)
				buffer = ft_strjoin(" ", buffer);
			else
				buffer = ft_strjoin("+", buffer);
		}
	}
	if (!f->minus && f->zero)
		buffer = ft_strleftjoin("0", buffer, f->width);
	if (f->minus)
		buffer = ft_strleftjoin(" ", buffer, f->width);
	else if (f->width)
		buffer = ft_strrightjoin(" ", buffer, f->width);
	buffer	=	ft_handle_precision(buffer, f->prec);
	len = ft_strlen(buffer);
	write(1, buffer, len);
	free(buffer);
	buffer = NULL;
	return (len);
}

int		ft_process_formate(t_flag *f, char *buffer)
{
	int		len = 0;

	if (f->plus || f->space)
	{
		if (buffer[0] != '-')
		{
			if (f->space)
				buffer = ft_strjoin(" ", buffer);
			else
				buffer = ft_strjoin("+", buffer);
		}
	}
	if (!f->minus && f->zero)
		buffer = ft_strleftjoin("0", buffer, f->width);
	if (f->minus)
		buffer = ft_strleftjoin(" ", buffer, f->width);
	else if (f->width)
		buffer = ft_strrightjoin(" ", buffer, f->width);
	buffer	=	ft_handle_precision(buffer, f->prec);
	len = ft_strlen(buffer);
	write(1, buffer, len);
	free(buffer);
	buffer = NULL;
	return (len);
}

int		ft_process_formatg(t_flag *f, char *buffer)
{
	int		len = 0;

	if (f->plus || f->space)
	{
		if (buffer[0] != '-')
		{
			if (f->space)
				buffer = ft_strjoin(" ", buffer);
			else
				buffer = ft_strjoin("+", buffer);
		}
	}
	if (!f->minus && f->zero)
		buffer = ft_strleftjoin("0", buffer, f->width);
	if (f->minus)
		buffer = ft_strleftjoin(" ", buffer, f->width);
	else if (f->width)
		buffer = ft_strrightjoin(" ", buffer, f->width);
	buffer	=	ft_handle_precision(buffer, f->prec);
	len = ft_strlen(buffer);
	write(1, buffer, len);
	free(buffer);
	buffer = NULL;
	return (len);
}

int		ft_process_formats(t_flag *f, char *buffer)
{
	int		len = 0;

	if (f->prec)
	{
		len  = ft_strlen(buffer);
		if (f->prec <= len)
			buffer = ft_strsub(buffer, 0, f->prec);
	}
	if (f->minus)
		buffer = ft_strleftjoin(" ", buffer, f->width);
	else if (f->width)
	{
		len = f->width - ft_strlen(buffer);
		while (--len >= 0)
			buffer = ft_strjoin(" ", buffer);
	}
	len = ft_strlen(buffer);
	write(1, buffer, len);
	//free(buffer);
	buffer = NULL;
	return (len);
}

int		ft_process_format1(t_flag *f, char *buffer)
{
	int		len = 0;

	if (f->plus || f->space)
	{
		if (buffer[0] != '-')
		{
			if (f->space)
				buffer = ft_strjoin(" ", buffer);
			else
				buffer = ft_strjoin("+", buffer);
		}
	}
	if (!f->minus && f->zero)
		buffer = ft_strleftjoin("0", buffer, f->width);
	if (f->minus)
		buffer = ft_strleftjoin(" ", buffer, f->width);
	else if (f->width)
		buffer = ft_strrightjoin(" ", buffer, f->width);
	buffer	=	ft_handle_precision(buffer, f->prec);
	len = ft_strlen(buffer);
	write(1, buffer, len);
	free(buffer);
	buffer = NULL;
	return (len);
}
