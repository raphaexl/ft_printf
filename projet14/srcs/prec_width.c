/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 18:09:03 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/13 00:37:58 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*ft_newstr(char c, int size)
{
	char	*str;

	if ((str = (char *)malloc(size + 1)))
	{
		str[size] = '\0';
		while (--size >= 0)
			str[size] = c;
	}
	return (str);
}

char			*ft_strleftjoin(char *str, char *buffer, int width)
{
	int		i;
	char	sign;
	char	*temp;

	sign = buffer[0];
	i = width - ft_strlen(buffer);
	if (i <= 0)
		return (buffer);
	if (str[0] == ' ')
		buffer = ft_strjoin(buffer, ft_newstr(*str, i));
	else
	{
		temp = (char *)malloc(sizeof(char) * (i + 1));
		temp = ft_newstr(*str, i);
		if (sign == '-' || sign == '+')
			temp[0] = buffer[0];
		if (sign == '-' || sign == '+')
			buffer = ft_strjoin(temp, ft_strchr(buffer, sign) + 1);
		else
			buffer = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
	}
	return (buffer);
}

char			*ft_strrightjoin(char *str, char *buffer, int width)
{
	int		i;
	char	sign;
	char	*temp;

	sign = buffer[0];
	i = width - ft_strlen(buffer);
	if (i <= 0)
		return (buffer);
	if (str[0] == ' ')
		buffer = ft_strjoin(ft_newstr(*str, i), buffer);
	else
	{
		temp = (char *)malloc(sizeof(char) * (i + 1));
		if (sign == '-' || sign == '+')
			temp[0] = buffer[0];
		temp = ft_strjoin(temp, ft_newstr(*str, i));
		temp = ft_strjoin(temp, str);
		if (sign == '-' || sign == '+')
			buffer = ft_strjoin(temp, ft_strchr(buffer, sign) + 1);
		else
			buffer = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
	}
	return (buffer);
}

char			*ft_precision_algo(char *str, int prec)
{
	size_t		i;
	size_t		len;

	i = prec + 2;
	len = ft_strlen(str);
	if (i < len)
	{
		if (str[i] != '5')
		{
			while (str[i - 1] == '9')
				str[i--] = '0';
			str[i - 1] = str[i - 1] + (str[i] > '5');
			str[i] = str[i] == '9' ? '0' : str[i];
		}
		else
		{
			while (str[++i])
			{
				if (str[i] == '0')
					continue;
				else
					break ;
			}
			if (i < len && str[i] > '5')
				str[prec + 1] = str[prec + 1] + 1;
			else
				str[prec + 1] = !(str[prec] % 2);
		}
	}
	return (str);
}

char			*ft_handle_precision(char *buffer, int prec)
{
	int		len;
	char	*temp;
	char	*p;

	ft_putendl(buffer);
	exit(0);
	if (!(p = ft_strchr(buffer, '.')))
		return (buffer);
	buffer = ft_precision_algo(buffer, prec);
	len = prec - ft_strlen(p + 1);
	if (len <= 0)
	{
		len = ft_strlen(buffer) - ft_strlen(p);
		temp = ft_strsub(buffer, 0, len);
		return (ft_strjoin(temp, prec ? ft_strsub(p, 0, prec + 1) : NULL));
	}
	buffer = ft_strjoin(buffer, ft_newstr('0', len));
	return (buffer);
}