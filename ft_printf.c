/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 13:49:02 by matvivan          #+#    #+#             */
/*   Updated: 2020/10/05 01:48:47 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			arg_val(va_list ap, char *mod, char type, t_val *val)
{
	if (ft_strchr("cspdiuoxXn", type))
	{
		if (ft_strnequ(mod, "ll", 2) || ft_strchr("spn", type))
			val->d = va_arg(ap, long long);
		else if (*mod == 'l' && ft_strchr("di", type))
			val->d = va_arg(ap, long);
		else if (*mod == 'l' && ft_strchr("ouxX", type))
			val->d = va_arg(ap, unsigned long);
		else if (ft_strnequ(mod, "hh", 2) && ft_strchr("di", type))
			val->d = (char)va_arg(ap, int);
		else if (ft_strnequ(mod, "hh", 2) && ft_strchr("ouxX", type))
			val->d = (unsigned char)va_arg(ap, int);
		else if (*mod == 'h' && ft_strchr("di", type))
			val->d = (short)va_arg(ap, int);
		else if (*mod == 'h' && ft_strchr("ouxX", type))
			val->d = (unsigned short)va_arg(ap, int);
		else if (ft_strchr("di", type))
			val->d = va_arg(ap, int);
		else if (ft_strchr("couxX", type))
			val->d = va_arg(ap, unsigned int);
	}
	else if (ft_strchr("fge", type))
		val->f = va_arg(ap, double);
	else
		val->d = type;
}

t_printf		arg_fields(va_list ap, const char **fmt)
{
	t_printf	a;

	a.flg = ft_strnew(6);
	a.width = 0;
	a.prec = -1;
	a.mod = (char *)*fmt;
	*a.flg = '%';
	while (is_not_type(*fmt))
	{
		if (is_flag(*fmt) && ft_strchr(a.flg, **fmt) == 0)
			ft_strncat(a.flg, *fmt, 1);
		else if (is_width(*fmt))
			a.width = (**fmt == '*' ? va_arg(ap, int) : ft_atoi(*fmt));
		else if (**fmt == '.')
			a.prec = (fmt[0][1] == '*' ? va_arg(ap, int) : ft_atoi(*fmt + 1));
		else if (is_mod(*fmt))
			a.mod = (char *)*fmt;
		++(*fmt);
	}
	if (ft_strchr(a.flg, '-'))
		a.width = -absl(a.width);
	a.flg[0] = *(*fmt)++;
	arg_val(ap, a.mod, *a.flg, &a.val);
	return (a);
}

int				ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			len;
	t_printf	arg;

	len = 0;
	va_start(ap, fmt);
	while (*fmt)
		if (*fmt++ != '%')
			len += write(1, fmt - 1, 1);
		else if (valid_field(&fmt))
		{
			arg = arg_fields(ap, &fmt);
			if (*arg.flg == 'n')
				*(arg.val.ptr) = len;
			else if (ft_strchr("pdiuoxX", *arg.flg))
				len += print_num(arg.flg, arg.width, arg.prec, arg.val.d);
			else if (ft_strchr("fge", *arg.flg))
				len += print_float(arg.flg, arg.width, arg.prec, arg.val.f);
			else
				len += print_str(arg.flg, arg.width, arg.prec, arg.val.d);
			free(arg.flg);
		}
	va_end(ap);
	return (len);
}
