/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:06:32 by kaly              #+#    #+#             */
/*   Updated: 2023/09/16 19:06:08 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include <X11/Xlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include "../libmlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define MLX_ERROR 1

# define PXL 50

# define WINDOW_H 1080
# define WINDOW_W 1920

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	
	char	**map;
	int		index_first_lane;
	int		index_last_lane;

	void	*file;
	char	*addr;
	int		bits_per_pixel;
	int		endian;
	int		size_line;
	int		line_length;

	int			color_r;
	int			color_g;
	int			color_b;

	int		color_map_hex_C;
	int		color_map_hex_F;

	int		player_x;
	int		player_y;
	int		player_orient;
	int		x;
	int		y;

	int		exit;

	// int		pxl;
	// int		map_x;
	// int		map_y;

	// int		pl_move;
	// int		pl_x;
	// int		pl_y;
	// int		player;
	// int		check_collect;
	// int		collect;
	// int		check_exit;

	// int		exit_x;
	// int		exit_y;
	// int		exit_is_open;
}	t_data;

//		break_prog		//

void	ft_clean_when_verif_map_ko(t_data *data);
int		ft_quit(t_data *data);

//		check_arg		//

int	ft_comp_cub(char *arg, char *str);
void	ft_check_arg(int argc, char **argv);

//		error			//

int	err(char *str);
int	err_map(char *str);

//		main			//

void	init_data(t_data *data);
int	main(int argc, char **argv);

//		maps			//

int	color_verif(char *s);
int	fc_validation(char *s, int i);
int	cub_validation(t_data *data);
int	ft_check(int argc, char **argv, t_data *data);


//		print			//

void	titre(char *str);
int	titre_err(char *str);
void	line_up(int i);
void	line(int i);

//		utils			//

char	*make_color_hex(int n);
int	ft_htoi(char *s);
char	*get_map_color(char *s, int l, t_data *data);

//		verif_map		//

int	is_valid_line(char *s);
int	begin_by_one(char *s);
int	ends_by_one(char *s);
int map_validation(t_data *data);

//		verif_player	//

void	player_coordonate(t_data *data);
int	only_one_player(t_data *data);

//		window			//

void	ft_create_window(t_data *data);
void	ft_fill_floor(t_data *data);
int		handle_keypress(int keysym, t_data *data);
int		render(t_data *data);
void	ft_complete_img(t_data *data);

#endif
