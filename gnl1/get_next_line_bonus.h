/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavaness <bavaness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:43:19 by bavaness          #+#    #+#             */
/*   Updated: 2023/02/27 22:55:35 by bavaness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		gnl_have_nl(char *str);
char	*gnl_rm_output(char *str);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *s);

#endif
