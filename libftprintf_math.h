/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_math.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 13:44:32 by matvivan          #+#    #+#             */
/*   Updated: 2020/10/05 01:49:07 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_MATH_H
# define LIBFTPRINTF_MATH_H

char		*ft_nan_inf(uint64_t val);
int			ft_trail(double f, int prec);
long double	ft_round(double e, int prec);
int			ft_exp(long double f, int prec);
int64_t		max(long long a, long long b);
uint64_t	absl(long long n);
double		ft_pow(double n, int p);
int			ft_numlen(uint64_t n, int base);
char		*ft_itoa_base(char *sign, uint64_t num, int base, int prec);

#endif
