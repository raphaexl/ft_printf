/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublecal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:23:24 by fel-hita          #+#    #+#             */
/*   Updated: 2019/03/13 00:07:24 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_frcln(int int_expo, char *str, int bias)
{
	int len;

	len = (int_expo > 0) ? ft_strlen(str) - 1 : ft_strlen(str);
	if (int_expo - bias < 0)
	{
		if (int_expo - bias == -D_BIAS)
			return (D_BIAS - 1 + len);
		return (-(int_expo - bias) + len);
	}
	return (len);
}

char	*ft_mvfrc(char *str, int frac_len)
{
	char	*new;
	int		str_len;
	int		i;

	i = -1;
	str_len = ft_strlen(str);
	if (str_len - frac_len == 0)
		new = ft_strjoin("0.", str);
	else if (str_len - frac_len < 0)
	{
		new = ft_strdup(str);
		new = ft_strjoin(ft_zeros(ABS((str_len - frac_len))), new);
	}
	else
	{
		new = ft_strjoin(".", str);
		while (++i < ABS((str_len - frac_len)))
		{	
			new[i] = new[i + 1];
			new[i + 1] = '.';
		}
	}
	return (new);
}

char	*ft_lk(char *old, char *cpy)
{
	char *p;

	p = old;
	old = ft_strdup(cpy);
	free(p);
	return (old);
}

long	ft_intex(long bin_expo, int bias)
{
	int		i;
	long	m;
	long	int_expo;

	int_expo = 0;
	if (bias == 1023)
	{
		i = 12;
		m = 1024;
	}
	else
	{
		i = 16;
		m = 16384;
	}
	while (i--)
	{
		if (bin_expo & m)
			int_expo += m;
		bin_expo -= m;
		m /= 2;
	}
	return (int_expo);
}

long	ft_intma(long bin_mant, int bias)
{
	int		i;
	long	m;
	long	int_mant;

	int_mant = 0;
	if (bias == 1023)
	{
		i = 53;
		m = 2251799813685248;
	}
	else
	{
		i = 64;
		m = 4611686018427387904;
	}
	while (i--)
	{
		if (bin_mant & m)
			int_mant += m;
		bin_mant -= m;
		m /= 2;
	}
	return (int_mant);
}

char	*ft_zeros(int len)
{
	char *new;

	new = (char*)malloc(len + 1);
	new = ft_memset(new, '0', len);
	new = ft_strjoin("0.", new);
	return (new);
}

char	*ft_get_exponent(long bin_expo, int bias)
{
	int int_expo;

	int_expo = ft_intex(bin_expo, bias);
	if (int_expo - bias > 0)
		return (ft_exposant(2, int_expo - bias));
	else if (int_expo - bias < 0)
	{
		if (int_expo - bias == -bias)
			return (ft_exposant(5 ,bias - 1));
		else
			return (ft_exposant(5, -(int_expo - bias)));
	}
	return (ft_strdup("1"));
}

size_t	ft_is_end(char *str)
{
	while (*str)
	{
		if (*str != '0')
			return (0);
		str++;
	}
	return (1);
}

size_t	ft_is_frac(char *str)
{
	while (*str)
	{
		if (*str == '.')
			return (1);
		str++;
	}
	return (0);
}

char	*ft_rmz(char *str, short flag_frac)
{
	size_t	i;

	i = 0;
	if (flag_frac)
	{
		while (str[i] != '.')
			i++;
	}
	if (ft_is_end(str + i + 1))
	{
		str[i] = 0;
		return (str);
	}
	while (str[i])
	{
		if (ft_is_end(str + i))
			str[i] = 0;
		i++;
	}
	return (str);
}

char	*ft_mantissa(long bin_mant, short flag, int bias)
{
	char	*res_mant;
	int		i;
	int		i_max;
	long	m;

	i = 1;
	if (bias == 1023)
	{
		m = 2251799813685248;
		i_max = 52;
	}
	else
	{
		m = 4611686018427387904;
		i_max = 63;
	}
	res_mant = ft_strdup("1");
	while (i++ <= i_max && bin_mant)
	{
		res_mant = ft_strmulti(res_mant, "10");
		if (bin_mant & m)
		{
			res_mant = ft_stradd(res_mant, ft_exposant(5, i - 1));
			bin_mant -= m;
		}
		m /= 2;
	}
	if (!flag)
	{
		res_mant[0] = '0';	
		while (*res_mant == '0')
		res_mant++;
	}
	return (res_mant);
}
