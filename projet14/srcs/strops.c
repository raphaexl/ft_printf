/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:58:18 by fel-hita          #+#    #+#             */
/*   Updated: 2019/03/12 17:51:58 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#define c2d(x) (x - '0')
#define d2c(x) (x + '0')

char* ft_strmulti(char* num1, char* num2) {

	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int *prod = (int *)calloc(len1 + len2 + 1, sizeof(int));
	int i, j, k = 0;

	if (num1 == NULL || num2 == NULL) return NULL;

	for (i = len1 - 1; i >= 0; i--) {
		k = len1 - 1 - i;
		for (j = len2 - 1; j >= 0; j--) {
			prod[k++] += (num1[i] - '0') * (num2[j] - '0');
		}
	}

	k++; /* the last carry digit */

	/* carry all */
	int c = 0;
	for (i = 0; i < k - 1; i++) {
		c = prod[i] / 10;
		prod[i] = prod[i] % 10;
		prod[i + 1] += c;
	}

	while (k > 1 && prod[k - 1] == 0) k--;

	char *ans = (char *)calloc(k + 1, sizeof(char));
	/* reverse */
	for (i = 0; i < k; i++) {
		ans[i] = prod[k - 1 - i] + '0';
	}
	ans[k] = '\0';

	free(prod);

	return (ans);
}

//MEMORY LEAKS!!
char	*ft_exposant(int a, int n)
{
	char	*y;
	char	*x;
	int		n2;

	x = ft_itoa(a);
	y = (n % 2) ? ft_itoa(a) : ft_itoa(1);
	n2 = n / 2;
	while (n2)
	{
		x = ft_strmulti(x, x);
		if (n2 % 2)
			y = (ft_strcmp(y, "1") == 0) ? x : ft_strmulti(y, x);
		n2 /= 2;
	}
	return (y);
}

char		*ft_stradd(char *nbr1, char *nbr2)
{
	t_sum	a;
	char	*res;

	a.sm = 0;
	a.i = ft_strlen(nbr1);
	a.j = ft_strlen(nbr2) - 1;
	res = ft_strnew(a.i);
	ft_memset(res, '0', a.i + 1);
	while (--a.i >= 0)
	{
		if (a.j >= 0)
			a.sm = I(nbr1[a.i]) + I(nbr2[a.j--]) + a.sm;
		else
			a.sm = I(nbr1[a.i]) + a.sm;
		res[a.i + 1] = C(a.sm);
		a.sm /= 10;
	}
	res[a.i + 1] = C(a.sm);
	a.i = ft_strlen(nbr1);
	if (res[0] == '0')
	{
		ft_memmove(res, res + 1, a.i);
		res[a.i] = '\0';
	}
	return (res);
}
/*
char  *ft_stradd(const char *a, const char *b, char *ans){
	int alen, blen;
	int i, carry;
	char *awk=strdup(a);
	char *bwk=strdup(b);

	i = -1;
	carry = 0;
	alen = ft_strlen(ft_strrev(awk));
	blen = ft_strlen(ft_strrev(bwk));
	if(alen<blen){
		ft_swap(&alen, &blen);
		ft_swapstr(&awk, &bwk);
	}
	ans[alen+1] = ans[alen] = '\0';
	while(++i <alen)
	{
		int sum = c2d(awk[i])+(i<blen ? c2d(bwk[i]): 0)+carry;
		ans[i] = d2c(sum % 10);
		carry = sum / 10;
	}
	if(carry)
		ans[i++]='1';
	free(awk);
	free(bwk);
	return ft_strrev(ans);
}*/
