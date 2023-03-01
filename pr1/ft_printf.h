/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhony <rhony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:50:57 by rhony             #+#    #+#             */
/*   Updated: 2023/02/28 15:05:15 by rhony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>

# include "libft/libft.h"

// From ft_printf.c
int			ft_printf(const char *s, ...);

// From ft_printf_utils_1.c
int			is_conv(char c);
int			is_int(char c, va_list vl);
int			is_char(char c, va_list vl);
int			is_string(char c, va_list vl);
int			is_pointer(char c, va_list vl);
void		convert_hex(uintptr_t i, int maj, int *len);

// From ft_printf_utils_2.c
int			is_conv(char c);

// From ft_printf_unsigned
int			is_unsigned(char c, va_list vl);
char		*ft_uitoa(unsigned int n);
int			get_ulen(unsigned int n);
int			is_hex(char c, va_list vl);

#endif
