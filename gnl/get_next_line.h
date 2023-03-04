/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:11:19 by jmetezea          #+#    #+#             */
/*   Updated: 2023/03/04 00:57:52 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//		libs		//

# include <stdlib.h> // lib for malloc free
# include <unistd.h> // lib for read

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

//		fct		//

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

#endif
