/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:58:44 by matvivan          #+#    #+#             */
/*   Updated: 2020/10/05 01:56:00 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*buff_dec(char *flg, int width, int prec, double dec)
{
	char		*sign;

	sign = ft_strchr(flg, ' ') ? " " : "";
	sign = ft_strchr(flg, '+') ? "+" : sign;
	sign = *(long long *)&dec < 0 ? "-" : sign;
	dec = absl(dec);
	if (ft_strchr(flg, '0') && width - ft_strlen(sign))
		prec = width - ft_strlen(sign);
	return (ft_itoa_base(sign, dec, 10, prec));
}

char			*buff_float(char *flg, int width, int prec, long double f)
{
	uint64_t	frac;
	char		*decim;
	char		*fract;
	char		*buff;

	frac = absl((f - (int64_t)f) * ft_pow(10, prec));
	if (ft_strchr(flg, '#') || prec)
		fract = ft_itoa_base(".", frac, 10, prec);
	else
		fract = ft_itoa_base("", frac, 10, prec);
	decim = buff_dec(flg, width - ft_strlen(fract), 1, f);
	buff = ft_strjoin(decim, fract);
	free(decim);
	free(fract);
	return (buff);
}

char			*buff_exp(char *flg, int width, int prec, long double f)
{
	int			e;
	char		*exp;
	char		*flt;
	char		*buff;

	e = ft_exp(f, prec);
	if (e > 0)
		f /= ft_pow(10, e);
	else if (e < 0)
		f *= ft_pow(10, -e);
	exp = ft_itoa_base("e ", absl(e), 10, 2);
	exp[1] = (e < 0 ? '-' : '+');
	f = ft_round(f, prec);
	flt = buff_float(flg, width - ft_strlen(exp), prec, f);
	buff = ft_strjoin(flt, exp);
	free(flt);
	free(exp);
	return (buff);
}

char			*buff_g(char *flg, int width, int sig_digit, long double f)
{
	int			e;
	int			prec;

	sig_digit = (sig_digit == 0 ? 1 : sig_digit);
	prec = sig_digit - 1;
	e = ft_exp(f, prec);
	if (e >= sig_digit || e < -4)
	{
		if (ft_strchr(flg, '#') == 0)
			prec = ft_trail(f * ft_pow(10, -e), prec);
		return (buff_exp(flg, width, prec, f));
	}
	else
	{
		if (ft_numlen(absl(f), 10))
			prec = sig_digit - ft_numlen(absl(f), 10);
		else
			prec = (-e) + prec;
		f = ft_round(f, prec);
		if (ft_strchr(flg, '#') == 0)
			prec = ft_trail(f, prec);
		return (buff_float(flg, width, prec, f));
	}
}

int				print_float(char *flg, int width, int prec, double f)
{
	char		*buff;

	prec = (prec < 0 ? 6 : prec);
	if (ft_nan_inf(*(uint64_t *)&f))
		buff = ft_strdup(ft_nan_inf(*(uint64_t *)&f));
	else if (*flg == 'f')
		buff = buff_float(flg, width, prec, ft_round(f, prec));
	else if (*flg == 'e')
		buff = buff_exp(flg, width, prec, f);
	else
		buff = buff_g(flg, width, prec, f);
	width = print(' ', width, ft_strlen(buff), buff);
	free(buff);
	return (width);
}
