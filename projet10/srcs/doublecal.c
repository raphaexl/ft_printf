/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublecal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:23:24 by fel-hita          #+#    #+#             */
/*   Updated: 2019/03/10 18:10:52 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#define F_BIAS 127
#define D_BIAS 1023
#define LD_BIAS 16383
#define MAXLEN(x,y) ((x >= y) ? x + 1 : y + 1)

char	*ft_get_exponent(long bin_expo, int bias);
char	*ft_mantissa(long mantissa, short flag, int bias);
char	*ft_rmz(char *str, short flag);
int		ft_frcln(int a, char *b, int c);
long	ft_intex(long bin_expo, int bias);
long	ft_intma(long bin_mant, int bias);
char	*ft_mvfrc(char *str, int frac_len);
char	*ft_lk(char *str1, char* str2);
size_t	ft_is_frac(char *str);
char	*ft_zeros(int len);

char	*ft_double_cal(t_double *d)
{
	char	*new_exponent;
	char	*new_mantissa;
	char	*final;
	int		frac_len;

	// calculate exponent
	new_exponent = ft_get_exponent(d->data.exponent, D_BIAS);
	//ft_putstr("\nbin exponent : ");
	//ft_print_exposant(d->data.exponent);
	//printf("new exponent : %s\n", new_exponent);
	// calculate mantissa
	if (ft_intex(d->data.exponent, D_BIAS) > 0)
	{
		//ft_putstr("exponent exist\n");
		new_mantissa = ft_mantissa(d->data.mantissa, 1, D_BIAS);
		//printf("new mantissa : %s\n", new_mantissa);
	}
	else
	{
		//ft_putstr("exponent is null\n");
		new_mantissa = ft_mantissa(d->data.mantissa, 0, D_BIAS);
		//printf("new mantissa : %s\n", new_mantissa);
	}
	//ft_putstr("\nmantissa : ");
	// remove zeroes after fraction
	//new_mantissa = ft_rmz(new_mantissa, 0);
	//ft_putstr(new_mantissa);
	//ft_putstr("\nbin mantissa : ");
	//ft_print_mantissa(d->data.mantissa);
	// multiply exponent by mantissa
	//printf("multiplying m : %s * %s\n",new_mantissa, new_exponent);
	final = (ft_strmulti(new_mantissa, new_exponent));
	//ft_putstr("\nbefore frac : ");
	//ft_putstr(final);
	// calculate fraction
	//ft_putstr("\nwe move fraction with : ");
	frac_len = ft_frcln(ft_intex(d->data.exponent, D_BIAS), new_mantissa, D_BIAS);
	//ft_putnbr(frac_len);
	if (frac_len)
		final = ft_mvfrc(final, frac_len);
	//ft_putstr("\nfinal fraction : ");
	if (d->data.sign)
		final = ft_strjoin("-", final);
	//printf("i will return : %s\n",final);
	return (final);
}

char	*ft_l_double_cal(t_l_double *d)
{
	char	*new_exponent;
	char	*new_mantissa;
	char	*final;
	int		frac_len;

	// calculate exponent
	new_exponent = ft_get_exponent(d->data.exponent, LD_BIAS);
	//ft_putstr("\nbin exponent : ");
	//ft_print_l_exposant(d->data.exponent);
	//printf("new exponent : %s\n", new_exponent);
	// calculate mantissa
	if (ft_intex(d->data.exponent, LD_BIAS) > 0)
	{
		//ft_putstr("exponent exist\n");
		new_mantissa = ft_mantissa(d->data.mantissa, 1, LD_BIAS);
		//printf("new mantissa : %s\n", new_mantissa);
	}
	else
	{
		//ft_putstr("exponent is null\n");
		new_mantissa = ft_mantissa(d->data.mantissa, 0, LD_BIAS);
		//printf("new mantissa : %s\n", new_mantissa);
	}
	//ft_putstr("\nmantissa : ");
	// remove zeroes after fraction
	//new_mantissa = ft_rmz(new_mantissa, 0);
	//ft_putstr(new_mantissa);
	//ft_putstr("\nbin mantissa : ");
	//ft_print_l_mantissa(d->data.mantissa);
	// multiply exponent by mantissa
	//printf("multiplying m : %s * %s\n",new_mantissa, new_exponent);
	final = (ft_strmulti(new_mantissa, new_exponent));
	//ft_putstr("\nbefore frac : ");
	//ft_putstr(final);
	// calculate fraction
	//ft_putstr("\nwe move fraction with : ");
	frac_len = ft_frcln(ft_intex(d->data.exponent, LD_BIAS), new_mantissa, LD_BIAS);
	//ft_putnbr(frac_len);
	if (frac_len)
		final = ft_mvfrc(final, frac_len);
	//ft_putstr("\nfinal fraction : ");
	if (d->data.sign)
		final = ft_strjoin("-", final);
	//printf("i will return : %s\n",final);
	return (final);
}

char	*ft_pre_cal(t_double *d)
{
	if (!d->data.mantissa)
	{
		if (!d->data.exponent)
		{
			if (d->data.sign)
				return (ft_strdup("-0"));
			else
				return (ft_strdup("0"));
		}
		else if (ft_intex(d->data.exponent, D_BIAS) == (D_BIAS * 2 + 1))
		{
			if (d->data.sign)
				return (ft_strdup("-inf"));
			else
				return (ft_strdup("+inf"));
		}
	}
	else if (ft_intex(d->data.exponent, D_BIAS) == 2047)
	{
		if (ft_intma(d->data.mantissa, D_BIAS))
			return (ft_strdup("nan"));
		/*else if (ft_intma(d->data.mantissa, D_BIAS) == 4503599627370495)
			return (ft_strdup("nan"));
		else if (ft_intma(d->data.mantissa, D_BIAS) == 2251799813685248)
			return (ft_strdup("nan"));
		else if (ft_intma(d->data.mantissa, D_BIAS) == 2251799813685249)
			return (ft_strdup("nan"));*/
	}
	return (ft_double_cal(d));
}

char	*ft_l_pre_cal(t_l_double *d)
{
	if (!d->data.mantissa)
	{
		if (!d->data.exponent)
		{
			if (d->data.sign)
				return (ft_strdup("-0"));
			else
				return (ft_strdup("0"));
		}
		else if (ft_intex(d->data.exponent, LD_BIAS) == (LD_BIAS * 2 + 1))
		{
			if (d->data.sign)
				return (ft_strdup("-inf"));
			else
				return (ft_strdup("+inf"));
		}
	}
	else if (ft_intex(d->data.exponent, LD_BIAS) == (LD_BIAS * 2 + 1))
	{
		if (ft_intma(d->data.mantissa, LD_BIAS))
			return (ft_strdup("nan"));
		/*else if (ft_intma(d->data.mantissa, D_BIAS) == 4503599627370495)
			return (ft_strdup("nan"));
		else if (ft_intma(d->data.mantissa, D_BIAS) == 2251799813685248)
			return (ft_strdup("nan"));
		else if (ft_intma(d->data.mantissa, D_BIAS) == 2251799813685249)
			return (ft_strdup("nan"));*/
	}
	return (ft_l_double_cal(d));
}

int		ft_frcln(int int_expo, char *str, int bias)
{
	// LOGIC PROBLEM
	int len;

	len = (int_expo > 0) ? ft_strlen(str) - 1 : ft_strlen(str);
	//printf("\nmantissa len is : %d int expo : %d bias : %dsub : %d\n",len,int_expo,bias,int_expo - bias);
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
	//printf("\nloop goes from 0 to %d\n",ABS((str_len - frac_len)));
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
			//printf("\nnew : %s\n",new);
			new[i] = new[i + 1];
			new[i + 1] = '.';
		}
	}
	//ft_putstr("\nori new : ");
	//ft_putstr(new);
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
	//printf("\ni made this %s\n",new);
	return (new);
}

char	*ft_get_exponent(long bin_expo, int bias)
{
	int int_expo;

	int_expo = ft_intex(bin_expo, bias);
	//printf("\nexpo  %d - bias %d = %d",int_expo, bias, int_expo - bias);
	//ft_putnbr(int_expo);
	if (int_expo - bias > 0)
	{
		//printf("\nexponent is positive : %s\n",ft_exposant(2, int_expo - bias));
		return (ft_exposant(2, int_expo - bias));
	}
	else if (int_expo - bias < 0)
	{
		if (int_expo - bias == -bias)
			return (ft_exposant(5 ,bias - 1));
		else
		{
			//printf("\nexponent is negative : %s\n",ft_exposant(5, -(int_expo - bias)));
			return (ft_exposant(5, -(int_expo - bias)));
		}
	}
	//printf("\nexponent is 0\n");
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

//MEMORY LEAKs
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
		//ft_putstr("res : ");
		//ft_putstr(res_mant);
		//ft_putchar('\n');
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
