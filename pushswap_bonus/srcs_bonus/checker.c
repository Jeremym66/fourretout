/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:15:07 by kaly              #+#    #+#             */
/*   Updated: 2023/04/18 23:30:00 by kaly             ###   ########.fr       */
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
		ft_swap_a(a, 1);
	else if (ft_strcmp(line, "sb\n") == 0)
		ft_swap_b(a, 1);
	else if (ft_strcmp(line, "ss\n") == 0)
		ft_swap_ab(a, b);
	else if (ft_strcmp(line, "ra\n") == 0)
		ft_rotate_a(a, 1);
	else if (ft_strcmp(line, "rb\n") == 0)
		ft_rotate_b(b, 1);
	else if (ft_strcmp(line, "rr\n") == 0)
		ft_rotate_ab(a, b);
	else if (ft_strcmp(line, "rra\n") == 0)
		ft_rrotate_a(a, 1);
	else if (ft_strcmp(line, "rrb\n") == 0)
		ft_rrotate_b(a, 1);
	else if (ft_strcmp(line, "rrr\n") == 0)
		ft_rrotate_ab(a, b);
	else
		ft_errfree(a, b);
}

void	ft_read(char *line, t_pile *a, t_pile *b);
{
	while (line != NULL)
	{
		line = get_next_line(0);
		if (line != NULL)
			to_do(line, a, b);
	}
}

int	main(int argc, char **argv)
{
	char	*line;
	t_pile	*a;
	t_pile	*b;
	int		i;

	i = 0;
	if (argc > 1)
	{
		a = ft_init_list();
		b = ft_init_list();
		while (++i < argc)
			if (ft_check_arg(a, argv[i]) == 1)
				ft_stack(a, ft_atoi(argv[i]));
		ft_gps(a);
		ft_read(line, a, b);
		ft_check_sort(a, b);
		free(line);
		ft_free(a);
		ft_free(b);
		free(a);
		free(b);
	}
	return (0);
}
