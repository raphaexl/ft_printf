/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublecal1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 18:47:08 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/13 00:07:00 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_l_double_cal(t_l_double *d)
{
	char	*new_exponent;
	char	*new_mantissa;
	char	*final;
	int		frac_len;

	new_exponent = ft_get_exponent(d->data.exponent, LD_BIAS);
	if (ft_intex(d->data.exponent, LD_BIAS) > 0)
		new_mantissa = ft_mantissa(d->data.mantissa, 1, LD_BIAS);
	else
		new_mantissa = ft_mantissa(d->data.mantissa, 0, LD_BIAS);
	final = (ft_strmulti(new_mantissa, new_exponent));
	frac_len = ft_frcln(ft_intex(d->data.exponent, LD_BIAS), new_mantissa, LD_BIAS);
	if (frac_len)
		final = ft_mvfrc(final, frac_len);
	if (d->data.sign)
		final = ft_strjoin("-", final);
	return (final);
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
		}
	return (ft_l_double_cal(d));
}

char	*ft_double_cal(t_double *d)
{
	char	*new_exponent;
	char	*new_mantissa;
	char	*final;
	int		frac_len;

	new_exponent = ft_get_exponent(d->data.exponent, D_BIAS);
	if (ft_intex(d->data.exponent, D_BIAS) > 0)
		new_mantissa = ft_mantissa(d->data.mantissa, 1, D_BIAS);
	else
		new_mantissa = ft_mantissa(d->data.mantissa, 0, D_BIAS);
	final = (ft_strmulti(new_mantissa, new_exponent));
	frac_len = ft_frcln(ft_intex(d->data.exponent, D_BIAS), new_mantissa, D_BIAS);
	if (frac_len)
		final = ft_mvfrc(final, frac_len);
	if (d->data.sign)
		final = ft_strjoin("-", final);
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
			}
	return (ft_double_cal(d));
}
