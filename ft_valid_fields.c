/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_fields.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 01:23:47 by matvivan          #+#    #+#             */
/*   Updated: 2020/10/05 01:46:13 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				is_flag(const char *fmt)
{
	char		zeropad;

	zeropad = (*fmt == '0' && ft_strchr("%# -+hl", *(fmt - 1)));
	return (ft_strchr("# +-", *fmt) || zeropad);
}

int				is_width(const char *fmt)
{
	char		prefix;

	prefix = is_flag(fmt - 1) || ft_strchr("%*", *(fmt - 1));
	return (prefix && ft_strchr("*123456789", *fmt));
}

int				is_not_type(const char *fmt)
{
	return (ft_isdigit(*fmt) || ft_strchr("# -+*.hl", *fmt));
}

int				is_mod(const char *fmt)
{
	return ((*fmt == 'l' || *fmt == 'h') && *(fmt - 1) != *fmt);
}

int				valid_field(const char **fmt)
{
	const char	*str;

	str = *fmt;
	while (*str && is_not_type(str))
		++str;
	if (*str == 0)
	{
		*fmt = str;
		return (0);
	}
	return (1);
}
