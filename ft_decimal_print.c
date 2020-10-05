/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 21:04:38 by matvivan          #+#    #+#             */
/*   Updated: 2020/10/05 01:45:50 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_upper(char *c)
{
	*c = ft_toupper(*c);
}

char			*buff_hex(char *flg, int width, int prec, uint64_t val)
{
	char		*sign;
	char		*buff;

	if (ft_strchr(flg, '#') && val)
		sign = (*flg == 'X' ? "0X" : "0x");
	else
		sign = "";
	if (ft_strchr(flg, '0') && prec < 0 && width - ft_strlen(sign))
		prec = width - ft_strlen(sign);
	buff = ft_itoa_base(sign, val, 16, prec);
	if (*flg == 'X')
		ft_striter(buff, &ft_upper);
	return (buff);
}

char			*buff_num(char *flg, int width, int prec, uint64_t val)
{
	char	*sign;

	sign = "";
	if (ft_strchr("di", *flg))
	{
		sign = ft_strchr(flg, ' ') ? " " : sign;
		sign = ft_strchr(flg, '+') ? "+" : sign;
		sign = (long long)val < 0 ? "-" : sign;
		val = absl(val);
	}
	if (ft_strchr(flg, '0') && prec < 0 && width - ft_strlen(sign))
		prec = width - ft_strlen(sign);
	return (ft_itoa_base(sign, val, 10, prec));
}

int				print_num(char *flg, int width, int prec, uint64_t val)
{
	char	*buff;

	if (ft_strchr("diu", *flg))
		buff = buff_num(flg, width, prec, val);
	else if (ft_strchr("xX", *flg))
		buff = buff_hex(flg, width, prec, val);
	else if (*flg == 'p')
		buff = ft_itoa_base("0x", val, 16, prec);
	else
		buff = ft_itoa_base("", val, 8, prec);
	width = print(' ', width, ft_strlen(buff), buff);
	free(buff);
	return (width);
}
