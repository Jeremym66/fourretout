/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:52:31 by maserrie          #+#    #+#             */
/*   Updated: 2023/02/07 17:11:26 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define HEXA "0123456789abcdef"
# define HEXA_MAJ "0123456789ABCDEF"

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include "libft.h"

typedef struct s_opt
{
	int		size_max;
	int		size_min;
	int		way;
	char	fill_char;
	int		is_zero;
	int		prefix;
	int		is_space;
	int		is_sign;
}	t_opt;

int		ft_putnchar_option(int count, t_opt opt, int expected);
int		ft_atoi_printf(const char *str, int *i);
int		ft_printf(char const *s, ...);
int		ft_putchar_printf_aff(char str, int aff);
int		ft_putstr_printf_aff(char const *str, int aff, int size);
int		ft_putnbr_printf_aff(int n, int aff, int opt, t_opt optl);
void	ft_putendl(char const *str);
int		ft_putnchar(int n, char c);
int		ft_putchar_printf(char n, t_opt c);
int		ft_putstr_printf(const char *n, t_opt c);
int		ft_putnbr_printf(int n, t_opt c);
int		ft_putunsigned_printf_aff(unsigned int c, int aff, int opt, t_opt optl);
int		ft_putunsigned_printf(unsigned int c, t_opt opt);
int		ft_puthexa_printf_aff(unsigned long long c, int maj, int aff, int p);
int		ft_puthexa_printf(unsigned long long c, int maj, t_opt opt);
int		ft_putadr_printf_aff(void *adr, int aff);
int		ft_putadr_printf(void *adr, t_opt opt);
int		ft_max(int a, int b);
int		ft_min(int a, int b);

#endif
