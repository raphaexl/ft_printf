/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 14:08:56 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/06 15:07:37 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_print_charformat(va_list ap, char *flag)
{
	char	*n;

	(void)flag;
	n = NULL;
	n[0] = va_arg(ap, int);
	return  (n);
}

char	*ft_print_strformat(va_list ap, char *flag)
{

	(void)flag;
	return (va_arg(ap, char *));
}

char	*ft_print_percentformat(va_list ap, char *flag)
{
	unsigned int	n;

	(void)flag;
	n = va_arg(ap, unsigned int);
	return (ft_itoa(n));
}

char	*ft_print_intformat(va_list ap, char *flag)
{
	int		n;

	(void)flag;
	n = va_arg(ap, int);
	return (ft_itoa(n));
}

char	*ft_print_uintformat(va_list ap, char *flag)
{
	unsigned int	n;

	(void)flag;
	n = va_arg(ap, unsigned int);
	return (ft_itoa(n));
}
