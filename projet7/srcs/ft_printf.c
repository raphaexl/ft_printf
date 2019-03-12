/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 22:30:54 by ebatchas          #+#    #+#             */
/*   Updated: 2019/01/27 21:34:07 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

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

int		ft_printf(char *str, ...)
{
	int		i;
	int		count;
	va_list	ap;
	char	*content;

	i = -1;
	count = 0;
	content = (char *)malloc(sizeof(char) * ft_strlen(str));
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			ft_memset(content, '\0', sizeof(char) * ft_strlen(str++));
			while (*str && !ft_is_format(*str))
				content[++i] = *str++;
			count = ft_get_format(ap, content, *str);
		}
		else
		{
			ft_putchar(*str);
			count++;
		}
		str++;
	}
	va_end(ap);
	return (count);
}
