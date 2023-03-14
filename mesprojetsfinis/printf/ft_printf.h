/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:36:21 by jmetezea          #+#    #+#             */
/*   Updated: 2023/03/14 13:59:24 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define PTR_NULL "(nil)"

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>

int	ft_printnbrhexa(long unsigned int nbr, char *base, char conv);
int	ft_printnbrbase(long int nbr, char *base, char conv);
int	ft_printchar(char c);
int	ft_printstr(char *str);
int	ft_strlen(char *str);
int	ft_printnbr(int nbr);
int	ft_printf(const char *str, ...);
int	ft_detect_param(char conv, va_list args);

#endif
