/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:20:05 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/02 15:41:58 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list {

    int nbr;
    struct s_list *next;

}   t_list;

#endif