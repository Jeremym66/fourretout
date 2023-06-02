/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:45:37 by jmetezea          #+#    #+#             */
/*   Updated: 2023/06/02 15:50:53 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int	ft_list_size(t_list *begin_list)
{
	int	i;
	t_list	*data;

	i = 1;
	data = begin_list;
	while (data->next != NULL)
	{
		data = data->next;
		i++;
	}
	return (i);
}
