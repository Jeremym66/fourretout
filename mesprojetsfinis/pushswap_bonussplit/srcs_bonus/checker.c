/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:15:07 by kaly              #+#    #+#             */
/*   Updated: 2023/04/28 00:40:10 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_errfree(t_pile *a, t_pile *b)
{
	ft_free(a);
	ft_free(b);
	ft_error();
}

void	to_do(char *line, t_pile *a, t_pile *b)
{
	if (ft_strcmp(line, "pa\n") == 0)
		ft_push_a(a, b);
	else if (ft_strcmp(line, "pb\n") == 0)
		ft_push_b(a, b);
	else if (ft_strcmp(line, "sa\n") == 0)
		ft_swap_a(a);
	else if (ft_strcmp(line, "sb\n") == 0)
		ft_swap_b(b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ft_swap_ab(a, b);
	else if (ft_strcmp(line, "ra\n") == 0)
		ft_rotate_a(a);
	else if (ft_strcmp(line, "rb\n") == 0)
		ft_rotate_b(b);
	else if (ft_strcmp(line, "rr\n") == 0)
		ft_rotate_ab(a, b);
	else if (ft_strcmp(line, "rra\n") == 0)
		ft_rrotate_a(a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		ft_rrotate_b(b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		ft_rrotate_ab(a, b);
	else
		ft_errfree(a, b);
}

void	ft_read_arg(t_pile *a, t_pile *b)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (line != NULL)
			to_do(line, a, b);
		free(line);
		line = get_next_line(0);
	}
	free(line);
}

int	main(int argc, char **argv)
{
	t_pile	*a;
	t_pile	*b;

	if (argc > 1)
	{
		a = ft_init_list();
		b = ft_init_list();
		ft_justonearg(a, argv, argc);
		ft_gps(a);
		ft_read_arg(a, b);
		ft_check_sort(a, b);
		ft_free(a);
		ft_free(b);
		free(a);
		free(b);
	}
	return (0);
}
