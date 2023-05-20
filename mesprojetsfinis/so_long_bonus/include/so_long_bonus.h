/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:03:30 by jmetezea          #+#    #+#             */
/*   Updated: 2023/05/20 17:37:59 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include "../minilibx/mlx.h"
# include "../printf/ft_printf.h"

# define MLX_ERROR 1
# define PXL 50

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*file;
	char	**map;
	char	**p;
	int		alive;
	int		pxl;
	int		map_x;
	int		map_y;
	int		x;
	int		y;
	int		pl_move;
	int		pl_x;
	int		pl_y;
	int		player;
	int		check_collect;
	int		collect;
	int		check_exit;
	int		exit;
	int		exit_x;
	int		exit_y;
	int		exit_is_open;
}	t_data;

//		ft_itoa			//
char	*ft_itoa(int nbr);
//		ft_split		//
char	**ft_split(char const *s, char c);
//		check_map		//
void	ft_check_map(char **argv, t_data *data);
void	ft_free_map(t_data *data);
char	*ft_get_map(int fd);
int		ft_check(char *line);
char	*ft_join(char *line, char c);
//		break_prog			//
int		ft_quit(t_data *data);
int		ft_quit2(t_data *data);
//		check_arg		//
void	ft_check_arg(int argc, char **argv);
int		ft_comp_ber(char *arg, char *str);
void	check_c_e(t_data *data, int y, int x);
void	ft_path(t_data *data, int y, int x);
//		check_limit		//
int		ft_check_limits(t_data *data);
int		check_mid(char *line, t_data *data);
int		check_up(char *line, t_data *data);
int		ft_rect(t_data *data);
int		ft_configuration(t_data *data);
//		player_gps		//
void	init_player(t_data *data);
void	ft_move_up(t_data *game);
void	ft_move_down(t_data *data);
void	ft_move_left(t_data *data);
void	ft_move_right(t_data *data);
//		check_move		//
int		ft_check_move(t_data *data, char dest, int y, int x);
void	ft_dead(t_data *data, int y, int x);
void	ft_move_display(t_data *data);
//		window			//
void	ft_create_window(t_data *data);
void	ft_fill_floor(t_data *data);
int		handle_keypress(int keysym, t_data *data);
int		render(t_data *data);
void	ft_complete_img(t_data *data);
//		put_windows		//
void	ft_put_limits(t_data *data);
void	ft_put_collect(t_data *data);
void	ft_put_player(t_data *data);
void	ft_put_exit(t_data *data);
void	ft_put_ennemy(t_data *data);
#endif
