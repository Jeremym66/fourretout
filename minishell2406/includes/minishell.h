 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:48:12 by sdestann          #+#    #+#             */
/*   Updated: 2023/07/11 11:54:47 by nours42          ###   ########.fr       */
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

typedef struct s_command
{
	char	*quote;
	char	*str;
	char	*word;
	char	*commands[100];
	size_t	num_words;
	size_t	i;
	int		brk;
}				t_command;

// liste chainee pour envp

typedef struct s_envp
{
	struct s_envp	*next;
	char			*str;
}				t_envp;

// structure pour args et path

typedef struct s_args
{
	char			**cmd_paths;
	char			**cmd_args;
}				t_args;

// data contient les elements structurels, les regles principales.

typedef struct s_data
{
	char		*str_temp;
	char		*str_temp2;
	int			piped;
	int			redirected;
	int			redirected2;
	int			std_in;
	int			std_out;
	int			fd_redirect_in;
	int			fd_redirect_out;
	int			next_pipe;
	pid_t		pid;
	t_command	*var;
	t_envp		*envp;
	t_args		*args;
}				t_data;

// cd.c

char	*get_oldpwd(t_envp *envp);
void	update_oldpwd(t_envp *envp, int a);
void	update_pwd(t_data *data);
void	ft_cd(t_data *data);

// dobble_and

void    dobble_and(t_data *data, char **envp);
void    ft_dolls_and(t_data *data, char **envp);
void    ft_pipe(t_data *data, char **envp);

// execute.c

void	execute_command(t_data *data, char **envp);

// exit.c

void    ft_exit(t_data *data);

// export.c

void	ft_add_new_arg_envp(t_data *data, char *args);
char	*ft_before_and_equal(char *s);
void	ft_export(t_data *data, char *args);

// free.c

void	ft_free_cmd_args(t_data *data);
void	ft_free_args(t_data *data);
void	ft_free_paths(t_data *data);
void	ft_free_str_temp(int i, t_data *data);
void	ft_free_envp(t_data *data);
void	ft_free_command_var(t_data *data);
void	ft_free_all(int i, t_data *data);

// init.c

void	init_envp(t_data *data, char **envp);
void	reinit_minishell(t_data *data);
void	init_minishell(t_data *data, char **envp);

// main.c

char	*get_cmd(char **paths, char *cmd);
void	get_readline(t_data *data);
void	shell_loop(t_data *data, char **envp);
int		find_builtin(t_data *data, char **envp);
int		main(int argc, char **argv, char **envp);

// parse.c

void	ft_quote(t_data *data);
void	ft_space(t_data *data);
void	parse(t_data *data);

// print.c

void	ft_show_envp(t_data *data);
void	ft_print_args(t_data *data);
void	ft_echo(t_data *data);
void	msg_error(char *err);

// ptd.c

void	tokening(t_data *data);
int		find_dollar(char *s);
void	find_and_replace(t_data *data, int i, int index_of_dollar);
void	give_me_the_money(t_data *data);

// pwd.c

void	ft_pwd();

// redirect.c

void	redirect_simple_left(t_data *data, char **envp, int i);
void	redirect_dobble_left(t_data *data, char **envp, int i);
void	redirect_simple_right(t_data *data, char **envp, int i);
void	redirect_dobble_right(t_data *data, char **envp, int i);

// signals.c

void	ft_signal(struct sigaction *act, t_data *data);
void	handle_signal(int signal);

// token.c

void	check_redirect(t_data *data, char **envp);

// unset.c

void	ft_delete_arg_envp(t_data *data, char *arg);
void	ft_unset(t_data *data, char *args);

// utils.c

int		ft_cmp_paths(char *s1, char *s2);
char	*delete_last_char(char *str);
char	*find_path(char *s, t_envp *envp);
void	add_str_endlst(t_envp *envp, char *str);

/*echo et l’option -n
◦ cd uniquement avec un chemin relatif ou absolu
◦ pwd sans aucune option
◦ export sans aucune option
◦ unset sans aucune option
◦ env sans aucune option ni argument
◦ exit sans aucune option*/

#endif
