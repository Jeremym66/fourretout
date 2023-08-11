/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:48:12 by sdestann          #+#    #+#             */
/*   Updated: 2023/08/10 16:39:55 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"

// deja inclus dans libft ou ft_printf.h 
//
// <unistd.h>
//
// to access, chdir, close, dup, dup2, execve, fork, getcwd, isatty, pipe,
// read, ttyname, ttyslot, unlink, write
//
// <stdlib.h>
//
// to exit, free, getenv, malloc
//
// <stdio.h>
//
// to perror, printf

// to add_history :

# include <readline/history.h>

// to closedir, opendir :

# include <sys/types.h>

// to readdir :

# include <dirent.h>

// to fstat, lstat, stat :

# include <sys/stat.h>

// to ioctl :

# include <sys/ioctl.h>

// to kill, sigaction, sigaddset, signal, sigemptyset :

# include <signal.h>

// to open :

# include <fcntl.h>

// to readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay

# include <readline/readline.h>
# include <readline/history.h>

// to strerror :

# include <string.h>

// to tcsetattr, tcgetattr :

# include <termios.h>

// to tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs :

# include <curses.h>
# include <term.h>

// to wait, wait3, wait4, waitpid :

# include <sys/wait.h>

// to errno

# include <errno.h>

// command stocke sert au parsing des commandes.

typedef struct s_var
{
	int		quote_type;
	char	*str;
	char	*word;
	char	*commands[100];
	size_t	num_words;
	size_t	i;
}				t_var;

// liste chainee pour envp

typedef struct s_envp
{
	struct s_envp	*next;
	char			*str;
}				t_envp;

// structure pour args et path

typedef struct s_args
{
	char		**cmd_paths;
	char		**cmd_args;
}				t_args;

typedef struct s_pipe
{
	int			infile;
	int			outfile;
	int			pipe_fd[2];
	int			cmd_nbrs;
	int			nbr_of_pipe;
	int			idx;
}				t_pipe;

// data contient les elements structurels, les regles principales.

typedef struct s_data
{
	char		**fr;
	char		*original_prompt;
	char		*cmd_prompt;
	int			redirected;
	int			fd_redirect_in;
	int			fd_redirect_out;
	int			next_part;
	int			args_start;
	int			*args_end;
	int			args_max;
	int			end;
	int			boucle;
	int			error_number;
	pid_t		pid_pipe;
	pid_t		pid_last;
	t_args		*args;
	t_var		*var;
	t_envp		*envp;
	t_pipe		*pipe;
}				t_data;

// dobble_and

void	dobble_and(t_data *data, char **envp);
void	ft_dolls_and(t_data *data, char **envp);

// execute.c

void	execute_cmd(t_data *data, char **envp);
void	exec_last2(t_data *d, char **envp);
void	exec_last(t_data *data, char **envp);

// find_builtin.c

int		find_builtin_outside(t_data *data);
void	find_builtin_inside(t_data *data);

// free_args.c

void	ft_free_paths(t_data *data);
void	ft_free_cmd_args(t_data *data);
void	free_and_clear_args(t_data *data);

// free_envp.c

void	ft_free_envp(t_data *data);

// free_pipe.c

void	free_and_clear_pipe(t_data *data);

// free_var.c

void	free_and_clear_var(t_data *data);

// free.c

void	ft_free_original_prompt(int i, t_data *data);
void	ft_free_all(int i, t_data *data);

// ft_cd.c

char	*get_oldpwd(t_envp *envp);
void	update_oldpwd(t_envp *envp, int a);
void	update_pwd(t_data *data);
void	ft_cd(t_data *data);

// ft_echo.c

void	ft_echo(t_data *data);
void	ft_echo2(t_data *data, int i, int n);

// ft_env

void	ft_print_envp(t_data *data);

// ft_exit.c

void	check_exit(t_data *data);
void	ft_exit(t_data *data);

// ft_export.c

void	ft_add_new_arg_envp(t_data *data, char *args);
char	*ft_before_and_equal(char *s);
void	ft_export(t_data *data, char *args);

// ft_pwd.c

void	ft_pwd(void);

// ft_unset.c

void	ft_delete_arg_envp(t_data *data, char *arg);
void	ft_unset(t_data *data, char *args);
void	update_path(t_data *data);
void	check_unset(t_data *data);

// init.c

void	init_args(t_data *data);
void	init_envp(t_data *data, char **envp);
void	init_parse(t_data *data);
void	init_pipe(t_data *data);
void	init_var(t_data *data);

// init2.c

void	init_first(t_data *data, char **envp);
void	init_first_2(t_data *data);

// main.c

char	*get_cmd(char **paths, char *cmd);
void	get_readline(t_data *data);
void	shell_loop(t_data *data, char **envp);
int		main(int argc, char **argv, char **envp);
void	control_d(t_data *data);
void	init_envp_in_i(t_data *data);

// parse.c

void	parse(t_data *data, char **envp);
void	tokening(t_data *d);
size_t	ft_find_char(char *s, int start, char c);
void	ft_quote(t_data *data);

// pipe.c

void	how_many_pipe(t_data *data);
void	execute_pipes(t_data *data, char **envp);
void	execute_pipe2(t_data *d, char **envp);

// print.c

void	ft_print_pipe_args(t_data *data);
void	ft_print_args(t_data *data);
void	ft_print_args_with_start_and_end(t_data *data);
void	msg_error(char *err);
void	print_intstar(int *i);
void	print_all(t_data *data);

// ptd.c

int		find_dollar(char *s);
void	check_in_envp(t_data *d, int i, int j, int index_of_dollar);
void	ft_init_fr(t_data *data, int i, int j, int index_of_dollar);
void	find_and_replace(t_data *data, int i, int index_of_dollar);
void	give_me_the_money(t_data *data);

// redirect.c

void	redirect_simple_left(t_data *data, int i);
void	redirect_dobble_left(t_data *data, int i);
void	redirect_simple_right(t_data *data, int i);
void	redirect_dobble_right(t_data *data, int i);

// signals.c

void	ft_signal(struct sigaction *act, t_data *data);
void	handle_signal(int signal);

// token.c

void	check_redirect(t_data *data);

// utils.c

int		ft_only_space(char *str);
char	*delete_last_char(char *str);
char	*find_path(char *s, t_envp *envp);
void	add_str_endlst(t_envp *envp, char *str);

// utils2.c

int		ft_cmp_paths(char *s1, char *s2);
char	*get_cmd(char **paths, char *cmd);

/*echo et l’option -n
◦ cd uniquement avec un chemin relatif ou absolu
◦ pwd sans aucune option
◦ export sans aucune option
◦ unset sans aucune option
◦ env sans aucune option ni argument
◦ exit sans aucune option*/

#endif
