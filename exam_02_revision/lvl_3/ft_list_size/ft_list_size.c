/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:53:05 by jmetezea          #+#    #+#             */
/*   Updated: 2023/05/30 16:17:33 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

typedef struct	s_list
{
    struct s_list *next;
    void          *data;
}		t_list;

int	ft_list_size(t_list *begin_list)
{
	t_list	*test;
	int	i;

	test = begin_list;
	i = 1;
	while (test->next != NULL)
	{
		i++;
		test = test->next;
	}
	return (i);
}
