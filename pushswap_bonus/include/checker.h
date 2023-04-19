/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:11:19 by jmetezea          #+#    #+#             */
/*   Updated: 2023/04/18 23:42:00 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

//		libs		//

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

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

//		pushswap		//
int		ft_check_arg(t_pile *pile, char *str);
int		ft_arg_is_digit(char *str);
int		ft_is_int(long int nb);
int		ft_comp_arg(t_pile *pile, long int nb);
//		pushswap_utils		//
t_pile	*ft_init_list(void);
void	ft_stack(t_pile *pile, long int new_nb);
void	ft_unstack(t_pile *pile);
void	ft_free(t_pile *pile);
void	ft_error(void);
//		check_sort		//
void	ft_check_sort(t_pile *a, t_pile *b);
//		gps			//
void	ft_gps(t_pile *pile);
//		rules			//
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
//		fct			//
char	*get_next_line(int fd);
char	*ft_join(char *stash, char *buf);
char	*ft_read(int fd, char *stash);
char	*ft_extract(char *stash);
char	*ft_clear(char *stash);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_isnewline(char *str);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
long	ft_atoi(const char *str);

#endif
