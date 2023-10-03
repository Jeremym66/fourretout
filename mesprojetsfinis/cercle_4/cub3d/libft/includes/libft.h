/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:17:48 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/26 11:37:32 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdbool.h>
# include "ft_printf.h"

// BUFFER_SIZE

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

// bool
bool		ft_error(const char *s);

// char
char		**ft_split(char const *s, char c);
char		**ft_qsplit(char *s);
char		*ft_get_next_line(int fd);
char		*ft_itoa(int n);
char		*ft_strcat(char *dest, char *src);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strncat(char *s1, const char *s2, size_t n);
char		*ft_strncpy(char *dest, char *src, unsigned int n);
char		*ft_strndup(const char *s, size_t i);
char		*ft_strnstr(const char *s1, const char *s2, size_t len);
char		*ft_strquote(char *s, int index, char c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strstr(char *str, char *to_find);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);

// int
int			ft_atoi(const char *nptr);
int			ft_htoi(char *s, int i, int n, int c);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_isspace(char *c);
int			ft_isspaces(char c);
int			ft_iterative_factorial(int nb);
int			ft_lstsize(t_list *lst);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_strcmp(char *s1, char *s2);
int			ft_strnchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_tolower(int c);
int			ft_toupper(int c);

//long long
long long	ft_abs(long long n);
long long	ft_atol(const char	*str);

// size_t
size_t		ft_strlcat(char *dest, const char *src, size_t size);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlen(const char *str);
size_t		ft_strqlen(const char *str, int n, char c);
size_t		ft_strnlen(const char *str, size_t i);

// t_list
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
t_list		*ft_lstsort(t_list *lst, int (*cmp)(void*, void*));

// void
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t len);
void		*ft_memset(void *b, int c, size_t len);
void		ft_print_double(double i);
void		ft_bzero(void *s, size_t n);
void		ft_free_ints(int *i);
void		ft_free_chars(char **str);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_lstadd(t_list **last, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_end(t_list **lats, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		ft_putchar(char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl(const char *s);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr(int nb);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr(char *str);
void		ft_putstr_fd(char *s, int fd);
void		ft_rev_int_tab(int *tab, size_t size);

#endif
