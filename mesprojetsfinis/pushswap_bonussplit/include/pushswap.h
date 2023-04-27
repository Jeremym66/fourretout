/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:11:55 by kaly              #+#    #+#             */
/*   Updated: 2023/04/28 00:00:58 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_element {
	struct s_element	*next;
	long				nb;
	int					gps;
}	t_elem;

typedef struct s_pile {
	t_elem	*base;
	t_elem	*top;
	int		nb_element;
	int		gps_max;
}	t_pile;

/*typedef struct pile	pile;
struct pile
{
	element		*base;
	element		*top;
	int	nb_element;
	int	gps_max;
};*/
	//pushswap//
int		ft_check_arg(t_pile *pile, char *str);
int		ft_arg_is_digit(char *str);
int		ft_is_int(long int nb);
int		ft_comp_arg(t_pile *pile, long int nb);
//void	ft_show_pile(pile *pile);
//void	ft_show_gps(pile *pile);
	//pushswap_utils//	
t_pile	*ft_init_list(void);
void	ft_stack(t_pile *pile, long int new_nb);
void	ft_unstack(t_pile *pile);
void	ft_free(t_pile *pile);
void	ft_error(void);
	//check_sort//
int		ft_check_sort(t_pile *a);
	//gps//
void	ft_gps(t_pile *pile);
	//sort//
void	ft_sort(t_pile *a, t_pile *b);
	//sort_bis//
void	ft_div(t_pile *a, t_pile *b, int div, int rest);
void	ft_check_near(t_pile *a, t_pile *b);
void	ft_sort10(t_pile *a, t_pile *b);
void	ft_sort100(t_pile *a, t_pile *b);
void	ft_sort_max(t_pile *a, t_pile *b);
	//sort3//
void	ft_sort3(t_pile *pile);
	//rules//
void	ft_swap_a(t_pile *pile, int print);
void	ft_swap_b(t_pile *pile, int print);
void	ft_swap_ab(t_pile *a, t_pile *b);
void	ft_push_a(t_pile *a, t_pile *b);
void	ft_push_b(t_pile *a, t_pile *b);
void	ft_rotate_a(t_pile *a, int print);
void	ft_rotate_b(t_pile *b, int print);
void	ft_rotate_ab(t_pile *a, t_pile *b);
void	ft_rrotate_a(t_pile *a, int print);
void	ft_rrotate_b(t_pile *b, int print);
void	ft_rrotate_ab(t_pile *a, t_pile *b);
	//ft_atoi//
long	ft_atoi(const char *str);
	//ft_split//
char	**ft_split(char const *s, char c);
	//ft_justonearg//
void	ft_justonearg(t_pile *a, char **argv, int argc);
void	ft_free_split(char **argv);
#endif
