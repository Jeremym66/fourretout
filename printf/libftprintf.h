/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:46:03 by jmetezea          #+#    #+#             */
/*   Updated: 2023/03/07 15:21:22 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# if defined (__APPLE__)
#  define PTR_NULL "0x0"
# else
#  define PTR_NULL "(nil)"
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>

int	ft_printnbrbase(long long int nbr, char *base, char conv);
int	ft_printchar(char c);
int	ft_printstr(char *str);
int	ft_strlen(char *str);
int	ft_printnbr(int nbr);
int	ft_printf(const char *str, ...);
int	ft_detect_param(char conv, va_list args);

#endif
