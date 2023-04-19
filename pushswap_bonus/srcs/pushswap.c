/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:30:13 by kaly              #+#    #+#             */
/*   Updated: 2023/04/17 19:30:19 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_comp_arg(t_pile *pile, long int nb)
{
	t_elem	*checked;

	checked = pile->top;
	while (checked != NULL)
	{
		if (checked->nb == nb)
			return (1);
		checked = checked->next;
	}
	return (0);
}

int	ft_is_int(long int nb)
{
	if (nb >= INT_MIN && nb <= INT_MAX)
		return (1);
	return (0);
}

int	ft_arg_is_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_check_arg(t_pile *pile, char *str)
{
	if (ft_arg_is_digit(str) == 0 || ft_is_int(ft_atoi(str)) == 0)
	{
		ft_free(pile);
		ft_error();
	}
	if (ft_comp_arg(pile, ft_atoi(str)) == 1)
	{
		ft_free(pile);
		ft_error();
	}
	return (1);
}

/*void	ft_show_pile(t_pile *pile)//affiche la liste 
{
	int	i;
	t_elem	*show_pile;

	if (!pile)
		return ;
	show_pile = pile->top;
	i = 1;
	while (show_pile != NULL)
	{
		printf("nb %d : %d\n", i, (int)show_pile->nb);
		show_pile = show_pile->next;
		i++;
	}
}

void    ft_show_gps(t_pile *pile)//affiche la liste 
{
        int     i;
        t_elem *show_pile;

        if (!pile)
                return ;
        show_pile = pile->top;
        i = 1;
        while (show_pile != NULL)
        {
                printf("nb %d : %d\n", i, (int)show_pile->gps);
                show_pile = show_pile->next;
                i++;
        }
}*/

int	main(int argc, char **argv)
{
	t_pile	*a;
	t_pile	*b;
	int		i;

	i = 0;
	if (argc > 1)
	{
		a = ft_init_list();
		b = ft_init_list();
		while (++i < argc)
		{
			if (ft_check_arg(a, argv[i]) == 1)
				ft_stack(a, ft_atoi(argv[i]));
		}
		ft_gps(a);
		ft_sort(a, b);
		ft_free(a);
		ft_free(b);
		free(a);
		free(b);
	}
	return (0);
}
