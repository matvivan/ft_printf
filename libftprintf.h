/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 15:08:50 by matvivan          #+#    #+#             */
/*   Updated: 2020/10/05 01:55:10 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"
# include "libftprintf_math.h"
# include "ft_valid_fields.h"

typedef union	u_val
{
	int			*ptr;
	double		f;
	uint64_t	d;
}				t_val;

typedef struct	s_printf
{
	char		*flg;
	int			width;
	int			prec;
	char		*mod;
	t_val		val;
}				t_printf;

int				print_float(char *flg, int width, int prec, double f);
int				print_num(char *flg, int width, int prec, uint64_t val);
int				print_str(char *flg, int width, int prec, uint64_t val);
int				print(char c, int width, int arglen, char *arg);
int				ft_printf(const char *fmt, ...);

#endif
