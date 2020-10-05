/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_math.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 21:00:36 by matvivan          #+#    #+#             */
/*   Updated: 2020/10/05 01:45:53 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_exp(long double f, int prec)
{
	int			e;

	e = 0;
	if (f != 0)
		while (absl(f) < 1)
		{
			f *= 10;
			--e;
		}
	while (absl(ft_round(f, prec)) >= 10)
	{
		f /= 10;
		++e;
	}
	return (e);
}

double			ft_floor(double f)
{
	uint64_t	mantissa;
	uint64_t	fraction;
	uint64_t	floor;

	mantissa = (*(uint64_t *)&f & 0xFFF0000000000000) >> 52;
	fraction = (*(uint64_t *)&f & 0x000FFFFFFFFFFFFF);
	mantissa -= 1023;
	floor = ~(0x000FFFFFFFFFFFFF >> mantissa);
	*(uint64_t *)&f &= floor;
	return (f);
}

long double		ft_round(double e, int prec)
{
	short		sign;
	double		floor;
	double		diff;

	sign = (*(int64_t *)&e < 0 ? -1 : 1);
	floor = sign * ft_floor(e * ft_pow(10, prec));
	diff = (sign * e - floor / ft_pow(10, prec)) * ft_pow(10, prec);
	if ((int64_t)floor & 1)
		floor += (diff > 0.499 ? 1.1 : 0.1);
	else
		floor += (diff > 0.5 ? 1.1 : 0.1);
	return (sign * (long double)floor / ft_pow(10, prec));
}

char			*ft_nan_inf(uint64_t val)
{
	uint64_t	sig_mant;
	uint64_t	fraction;

	sig_mant = (val & 0xFFF0000000000000) >> 52;
	fraction = (val & 0x000FFFFFFFFFFFFF);
	if (sig_mant == 0xFFF)
		return (fraction == 0 ? "-inf" : "-nan");
	if (sig_mant == 0x7FF)
		return (fraction == 0 ? "inf" : "nan");
	return (NULL);
}

int				ft_trail(double f, int prec)
{
	f = ft_round(f, prec);
	while (prec && absl(f * ft_pow(10, prec)) % 10 == 0)
		--prec;
	return (prec);
}
