/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_fields.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 01:25:15 by matvivan          #+#    #+#             */
/*   Updated: 2020/10/05 01:49:44 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VALID_FIELDS_H
# define FT_VALID_FIELDS_H

int				is_flag(const char *fmt);
int				is_width(const char *fmt);
int				is_not_type(const char *fmt);
int				is_mod(const char *fmt);
int				valid_field(const char **fmt);

#endif
