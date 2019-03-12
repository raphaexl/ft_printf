/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 22:30:54 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/12 17:26:56 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_process_color(char *str)
{
	char	*p;
	char	*temp;
	int		len;

	p = ft_strchr(str, '}');
	temp = ft_strcapitalize(ft_strsub(str + 1, 0, p - str - 1));
	len = ft_strlen(temp);
	if (temp)
	{

		if (!ft_strstr(temp, "B_") && !ft_strstr(temp, "F_"))
			temp = ft_strjoin("F_", temp);
		if (!ft_print_color(temp))
			ft_tally_print(str, len + 2);
		free(temp);
		temp = NULL;
		return (str + len + 2);
	}
	return (str);
}

static char	*ft_print_until(char *str, char c)
{
	static int i =0;

	i++;
	while (*str != '\0' && *str != c && *str != '{')
		ft_tally_print(str++, 1);
	if (*str == '{' && ft_strchr(str, '}'))
		str = ft_process_color(str);
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
		{
			str++;
		if (*str != '\0')
			str = ft_print_conversion(str, ap);
		}
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
