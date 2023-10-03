/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:06:32 by kaly              #+#    #+#             */
/*   Updated: 2023/09/29 11:11:57 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

# include <X11/Xlib.h>
# include <X11/X.h>
# include <X11/keysym.h>

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# include "../libmlx/mlx.h"

# include <sys/types.h>
# include <sys/stat.h>

# define MLX_ERROR 1

# define PXL 500
# define M_PI 3.14159265358979323846

# define WINDOW_H 780
# define WINDOW_W 1440

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	int		no_texture_index;
	int		so_texture_index;
	int		we_texture_index;
	int		ea_texture_index;
	int		index_floor;
	int		index_ceiling;
	int		line_floor;
	int		line_ceiling;
	char	*floor_hex_color;
	int		floor_first_color;
	int		floor_second_color;
	int		floor_third_color;
	char	*ceiling_hex_color;
	int		ceiling_first_color;
	int		ceiling_second_color;
	int		ceiling_third_color;
	char	**split_color_f;
	char	**split_color_c;
	int		map_last_line;
	int		map_first_line;
	int		line;
	int		index;
	int		first_index;
	size_t	size_max;
	void	*file;
	int		error;

	void	*wall_n;
	char	*wall_n_addr;
	int		wall_n_bpp;
	int		wall_n_endian;
	int		wall_n_size_line;
	int		wall_n_line_l;
	int		wall_n_w;
	int		wall_n_height;

	void	*wall_e;
	char	*wall_e_addr;
	int		wall_e_bpp;
	int		wall_e_endian;
	int		wall_e_size_line;
	int		wall_e_line_l;
	int		wall_e_w;
	int		wall_e_height;

	void	*wall_s;
	char	*wall_s_addr;
	int		wall_s_bpp;
	int		wall_s_endian;
	int		wall_s_size_line;
	int		wall_s_line_l;
	int		wall_s_w;
	int		wall_s_height;

	void	*wall_w;
	char	*wall_w_addr;
	int		wall_w_bpp;
	int		wall_w_endian;
	int		wall_w_size_line;
	int		wall_w_line_l;
	int		wall_w_w;
	int		wall_w_height;

	int		origin_x;
	int		origin_y;
	int		draw_x;
	int		draw_y;
	int		pixel_x;
	int		pixel_y;

	char	*addr;
	int		bpp;
	int		endian;
	int		size_line;
	int		line_l;
	int		color_r;
	int		color_g;
	int		color_b;
	int		color_map_hex_c;
	int		color_map_hex_f;
	int		pl_x;
	int		pl_y;
	double	player_orient;
	double	beta;
	double	scale;
	double	rad_beta;
	int		x;
	int		y;
	int		horizon;
	double	anglerad;
	double	delta_x;
	double	delta_y;
	double	xa;
	double	ya;
	double	first_x;
	double	first_xa;
	double	first_y;
	double	first_ya;
	double	dist_x;
	double	dist_y;
	int		check_x;
	int		check_y;
	int		i;
	int		o;
	double	dist;
	double	orient;
	int		exit;
}	t_data;

//		break_prog		//

void	ft_clean_map_and_inside(t_data *data);
void	ft_clean_textures(t_data *data, int i);
void	ft_clean_fc_color(t_data *data, int i);
void	ft_clean_split_color(t_data *data, int i, int j);

// 		break_prog2		//

void	ft_clean(t_data *data, int i);
void	ft_exit_failure(t_data *data, int i, char *s_err, char *t_err);
int		ft_quit(t_data *data);

//		check_arg		//

int		ft_comp_cub(char *arg, char *str);
void	ft_check_arg(int argc, char **argv);

//		main			//

void	init_data(t_data *data);
void	ft_check(char **argv, t_data *data);
int		main(int argc, char **argv);

//		map			//

int		ft_create_map(t_data *data, char **argv);
int		ft_test_map(t_data *data);
void	ft_restore_map(t_data *data);

// 		maps_get_colors.c	//

void	fill_fc_color(t_data *data);
char	*get_map_color(char *s, int l, t_data *data);
char	*make_color_hex(int n);
char	*ft_create_res(char *res);
void	complete_res(char *res, int j, char *s);

// 		maps_go_around_the_walls.c	//

int		go_around_the_walls(t_data *data);
void	first_step(t_data *data);
int		go_around_the_walls2(t_data *data, int i);

// 		maps_utils.c		//

void	resize_map(t_data *data);
void	add_spaces(t_data *data);
void	*ft_realloc_space(void *ptr, size_t original_size, size_t new_size);
void	*ft_memset2(void *b, int c, size_t len);

// 		maps_verif_fc.c		//

int		floor_ceiling_validation(t_data *data);
int		floor_ceiling_found(t_data *data);
int		search_floor_or_ceiling(t_data *data, char *c);
int		floor_format_validation(t_data *data);
int		ceiling_format_validation(t_data *data);

//		maps_verif_moove		//

int		test_map_ok(t_data *data, int i);
int		verif_sides(t_data *data, int i, int j);
int		verif_up_or_down(t_data *data, int i, int j);
void	go_sides(t_data *data, int i, int j);
void	go_up_or_down(t_data *data, int i, int j);

// 		maps_verif_textures.c		//

int		texture_validation(t_data *data);
void	error_textures(t_data *data);
int		search_textures(t_data *data, char *texture);
int		search_xpm(char *s);
char	*texture_file(char *s);

//		maps_verif		//

int		find_start_end_of_map(t_data *data);
int		begin_by_one(char *s);
int		ends_by_one(char *s);
int		ft_test_map_is_at_end(t_data *data, int i);

//		verif_player	//

int		ft_test_perso(t_data *data);
void	player_coordonate(t_data *data, int i, int j);
int		only_one_player(t_data *data);

//		print_error			//

int		err(char *str);
int		err_map(char *str);

//		print			//

void	print_titre(int i, int j, char *str);
void	titre(char *str);
int		titre_err(char *str);
void	line_up(int i);
void	line(int i);

//		utils			//

void	print_map(char **map, int i);
int		empty_line(char *c);
int		get_k(int i);

//		window			//

void	my_mlx_pixel(t_data *data, int x, int y, int color);
int		pix_text(t_data *data, char *addr, int line_lenght, int bpp);
int		render(t_data *data);
void	ft_create_window(t_data *data);
void	ft_fill_floor(t_data *data);

// 		windows_calcul_distances.c		//

void	calcul_distance(t_data *data);
void	calcul_distance_part_one(t_data *data);
void	calcul_distance_part_two(t_data *data);
void	calcul_distance_part_three(t_data *data);
void	calcul_distance_part_four(t_data *data);

// 		windows_check_wall.c	//

void	ft_check_wall_sw(t_data *data);
void	ft_check_wall_se(t_data *data);
void	ft_check_wall_nw(t_data *data);
void	ft_check_wall_ne(t_data *data);
void	ft_init_wall_img(t_data *data);

//		windows_init.c			//

void	ft_init_part_one(t_data *data, int i, int j);
void	ft_init_part_two(t_data *data, int i, int j);
void	ft_turn_orient(t_data *data);
void	ft_init_first(t_data *data);
void	ft_init_delta(t_data *data);

// 		windows_mooves.c		//

void	ft_move_back(t_data *data);
void	ft_move_up(t_data *data);
int		handle_keypress(int keysym, t_data *data);

// 		windows_mooves2.c		//

void	ft_strafe_right(t_data *data);
void	ft_strafe_left(t_data *data);
void	ft_turn_right(t_data *data);
void	ft_turn_left(t_data *data);

#endif
