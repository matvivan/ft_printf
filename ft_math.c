/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 16:40:51 by matvivan          #+#    #+#             */
/*   Updated: 2020/10/05 01:46:00 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int64_t		max(int64_t a, int64_t b)
{
	return (a > b ? a : b);
}

uint64_t	absl(int64_t n)
{
	return (n < 0 ? -n : n);
}

double		ft_pow(double n, int p)
{
	if (p < 0)
		return (1 / ft_pow(n, -p));
	else
		return (p ? n * ft_pow(n, p - 1) : 1);
}

int			ft_numlen(uint64_t n, int base)
{
	return (n ? 1 + ft_numlen(n / base, base) : 0);
}

char		*ft_itoa_base(char *sign, uint64_t num, int base, int prec)
{
	char	*buff;
	int		s;

	s = ft_strlen(sign);
	prec = max(ft_numlen(num, base), prec < 0 ? 1 : prec);
	buff = ft_strcpy(ft_strnew(s + prec), sign);
	while (prec--)
	{
		buff[s + prec] = "0123456789abcdef"[num % base];
		num /= base;
	}
	return (buff);
}
