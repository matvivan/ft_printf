/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 16:25:23 by matvivan          #+#    #+#             */
/*   Updated: 2020/10/05 01:46:09 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				print(char c, int width, int arglen, char *arg)
{
	char		*buff;
	int			buff_size;

	buff_size = max(absl(width), arglen);
	buff = ft_memset(ft_strnew(buff_size), c, buff_size);
	if (width > arglen)
		ft_strcpy(buff + width - arglen, arg);
	else
		ft_strncpy(buff, arg, arglen);
	write(1, buff, buff_size);
	free(buff);
	return (buff_size);
}

int				print_str(char *flg, int width, int prec, uint64_t val)
{
	char		*str;
	char		c;

	c = (ft_strchr(flg, '0') && width > 0 ? '0' : ' ');
	if (*flg == 's')
	{
		str = (val ? (char *)val : "(null)");
		if ((uint64_t)prec > ft_strlen(str))
			prec = ft_strlen(str);
		return (print(c, width, prec, str));
	}
	return (print(c, width, 1, (char *)&val));
}
