/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:55:57 by sdestann          #+#    #+#             */
/*   Updated: 2023/07/06 09:48:48 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "libft.h"

// deja inclus dans libft : <unistd.h> et <stdlib.h>

typedef struct s_flags
{
	int	spec;
	int	width;
	int	left;
	int	zero;
	int	precision;
	int	hash;
	int	space;
	int	plus;
}		t_flags;

char			*ft_printf_itoa(long num);
char			*ft_printf_utoa(unsigned int num);
char			*ft_printf_xtoa(unsigned long int num, int is_upper);

int				ft_flag_precision(const char *str, int pos, t_flags *flags);
int				ft_hex_len(unsigned int n);
int				ft_isflag(int c);
int				ft_isspec(int c);
int				ft_istype(int c);
int				ft_pad_width(int total_width, int size, int zero);
int				ft_printf(const char *format, ...);
int				ft_print_arg(char type, va_list args, t_flags flags);
int				ft_print_c(char c);
int				ft_print_char(char c, t_flags flags);
int				ft_print_hex(unsigned int n, int is_upper, t_flags flags);
int				ft_print_hexadec(char *nbstr, int n, int is_upper,
					t_flags flags);
int				ft_print_i(char *nbstr, int n, t_flags flags);
int				ft_print_int(int n, t_flags flags);
int				ft_print_integer(char *nbstr, int n, t_flags flags);
int				ft_print_p(unsigned long int n);
int				ft_print_ptr(unsigned long int n, t_flags flags);
int				ft_print_s(const char *str);
int				ft_print_sign_pre(int n, t_flags *flags);
int				ft_print_str(const char *str, t_flags flags);
int				ft_print_s_pre(const char *str, int precision);
int				ft_print_u(char *nbstr, t_flags flags);
int				ft_print_unint(char *nbstr, t_flags flags);
int				ft_print_unsigned(unsigned n, t_flags flags);
int				ft_print_x(char *nbstr, int n, int is_upper, t_flags flags);
int				ft_print_x_prefix(int is_upper);
int				ft_ptr_len(unsigned long int n);
int				ft_unint_len(unsigned int n);

size_t			ft_putuint(unsigned int x, const char format);
size_t			ft_putint(int nb);
size_t			ft_putulong(unsigned long x);

t_flags			ft_flag_digit(char c, t_flags flags);
t_flags			ft_flag_left(t_flags flags);
t_flags			ft_flag_width(va_list args, t_flags flags);
t_flags			ft_flags_init(void);

void			ft_print_adr(unsigned long int n);

#endif
