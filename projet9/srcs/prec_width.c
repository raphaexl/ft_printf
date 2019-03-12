/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 12:35:53 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/11 19:17:51 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


char	*ft_strleftjoin(char *str, char *buffer, int width)
{
	int		len;
	int		i;
	char	sign;
	char	*temp;

	len = ft_strlen(buffer);
	sign = buffer[0];
	i = width - len;
	/*if (sign == '-' || sign == '+')
	  i--;*/
	if (i <= 0)
		return (buffer);
	if (str[0] == ' ')
		while (--i >= 0)
			buffer = ft_strjoin(buffer, str);
	else
	{
		temp = (char *)malloc(sizeof(char) * (i + 1));
		if (sign == '-' || sign == '+')
			temp[0] = buffer[0];
		while (--i >= 0)
			temp = ft_strjoin(temp, str);
		if (sign == '-'|| sign == '+')
			buffer = ft_strjoin(temp, ft_strchr(buffer, sign) + 1);
		else
			buffer = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
	}
	return (buffer);
}

char	*ft_strrightjoin(char *str, char *buffer, int width)
{
	int		len;
	int		i;
	char	sign;
	char	*temp;

	len = ft_strlen(buffer);
	sign = buffer[0];
	i = width - len;
	/*if (sign == '-' || sign == '+')
	  i--;*/
	if (i <= 0)
		return (buffer);
	if (str[0] == ' ')
		while (--i >= 0)
			buffer = ft_strjoin(str, buffer);
	else
	{
		temp = (char *)malloc(sizeof(char) * (i + 1));
		if (sign == '-' || sign == '+')
			temp[0] = buffer[0];
		while (--i >= 0)
			temp = ft_strjoin(temp, str);
		if (sign == '-'|| sign == '+')
			buffer = ft_strjoin(temp, ft_strchr(buffer, sign) + 1);
		else
			buffer = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
	}
	return (buffer);
}

char	*ft_handle_precision(char *buffer, int prec)
{
	int		len;
	int		i;
	char	*temp;
	char	*p;

	if (!(p = ft_strchr(buffer, '.')))
		return (buffer);
	//ft_putstr(buffer);
	//ft_putchar('\n');
	//ft_putstr(p);
	len = ft_strlen(p + 1);
	i = prec - len;
	//ft_putnbr(i);
	//exit(0);
	if (i <= 0)
	{
		len = ft_strlen(buffer) - ft_strlen(p);
		temp = ft_strsub(buffer, 0, len);
		/*ft_putstr(buffer);
		ft_putchar('\n');
		ft_putstr(temp);
		exit(0);*/
		return (ft_strjoin(temp, ft_strsub(p, 0, 6)));
	}
	temp = (char *)malloc(sizeof(char) * (i + 1));
	while (--i >= 0)
		temp = ft_strjoin(temp, "0");
	buffer = ft_strjoin(buffer, temp);
	free(temp);
	temp = NULL;
	return (buffer);
}
