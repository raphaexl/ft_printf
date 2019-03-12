/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:57:58 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/09 11:03:29 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_process_formati(t_flag *f, char *buffer)
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
	len = ft_strlen(buffer);
	write(1, buffer, len);
	free(buffer);
	buffer = NULL;
	return (len);
}

int		ft_process_formatuox(t_flag *f, char *buffer)
{
	int		len = 0;

	if (!f->minus && f->zero)
		buffer = ft_strleftjoin("0", buffer, f->width);
	if (f->minus)
		buffer = ft_strleftjoin(" ", buffer, f->width);
	else if (f->width)
		buffer = ft_strrightjoin(" ", buffer, f->width);
	len = ft_strlen(buffer);
	write(1, buffer, len);
	free(buffer);
	buffer = NULL;
	return (len);
}

int		ft_process_formatc(t_flag *f, char *buffer)
{
	int		len = 0;

	(void)f;
	len = ft_strlen(buffer);
	write(1, buffer, len);
	free(buffer);
	buffer = NULL;
	return (len);
}

int		ft_process_formatp(t_flag *f, char *buffer)
{
	int		len = 0;

	(void)f;
	len = ft_strlen(buffer);
	write(1, buffer, len);
	free(buffer);
	buffer = NULL;
	return (len);
}
