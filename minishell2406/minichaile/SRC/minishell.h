/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:28:19 by aperrein          #+#    #+#             */
/*   Updated: 2023/07/04 14:31:34 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_lst
{
	char			*content;
	struct s_lst	*first;
	struct s_lst	*next;
}			t_lst;

typedef struct s_msh
{
	char	*l;
	char	*lvl;
	char	**c_env;
	char	**cmd;
	int		gnl;
	int		status;
	int		piped;
	int		redirected_out;
	int		redirected_in;
	int		std_in;
	int		std_out;
	t_lst	*parsed;
}	t_msh;

void	free_double_char(char **s);
void	ft_seek(char *str);
void	cmd_pwd(t_msh *msh);
void	cmd_cd(t_msh *msh);
void	cmd_env(t_msh *msh);
void	cmd_echo(t_msh *msh);
void	cmd_exit(t_msh *msh, int status);
void	cmd_unset(t_msh *msh);
void	cmd_export(t_msh *msh);
void	export_error(t_msh *msh, int j, int *r);
void	msh_executer(t_msh *msh);
void	minishell(t_msh *msh);
void	cmd_exec(t_msh *msh);
void	fork_to_pipe(t_msh *msh);
void	ft_cmd(t_msh *msh, t_lst *parsed);
void	ft_signal(struct sigaction *act, t_msh *msh);
void	update_pwd(t_msh *msh);
char	*find_path(t_msh *msh);
char	*find_exec_path(t_msh *msh);

int		is_str_in_tab(char *s, char **tab);
int		ft_is_in(char *str, char c);
int		al_before_egal(char *s);
int		max(int a, int b);
void	export_arg(t_msh *msh);
void	new_cmd(t_msh *msh, int f, int i);
int		pos_egal(char *s);
int		l_egal(char *s);
int		builtin(t_msh *msh);
int		redirect_sort(t_msh *msh);
int		check_redirect(t_msh *msh);

int		ft_iswhitespace(char c);
int		ft_length_lst(t_lst *lst);
int		ft_is_in(char *str, char c);
int		ft_im_in(char *str, char *src, int i);
char	*ft_get_cat_2(char **strr, char *str);
char	*ft_get_cat(char **strr, char *str, int i, int n);
void	ft_append(char *s1, char *s2, int *i, int *j);
void	ft_dquotes(t_msh *msh, t_lst *lst);
void	ft_rm_mid(t_lst *lst);
void	ft_free_lst(t_lst *lst);
void	ft_rm_spaces(t_lst *lst);
void	ft_print_chain(t_lst *lst);
void	ft_space_parse(t_lst *lst);
void	ft_split_parse(t_lst *lst);
t_lst	*ft_parse(char *str, t_msh *msh);
t_lst	*ft_init_lst(char *str, t_lst *first, t_lst *nextof);

#endif
