/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:02:48 by kaly              #+#    #+#             */
/*   Updated: 2023/04/10 19:20:42 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct Element Element;
struct Element
{
	int	nb;
	Element	*next;
};

typedef struct File File;
struct File
{
	Element *first;
	int	nb_element;
	double	average;
};

int	ft_atoi(const char *str);
#endif
