/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:40:05 by kaly              #+#    #+#             */
/*   Updated: 2023/09/23 18:01:07 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


/*
1/		Determiner x et y sur le plan "pixeliser" 
	on determine une case = 100 pxl
	ex si mon perso debute en (3 1) a linitialisation on determine que le joueur est au milieu de la case donc
	player_x = 350;
	player_y = 150;

2/		Determiner lorientation du joueur
	A linitialisation le joueur est oriente sur un des point cardinaux
	on determine lest a 0 degres donc si :
	Est : player_orient = 0;
	Nord : player_orient = 90;
	Ouest : player_orient = 180;
	Sud : player_orient = 270; une idee me vient peut etre que de lest jusque louest en passant par le sud on mettrait des angle negatif de 0 a -179

3/		Determiner langle de vision (FOV) et le nombre de rayons envoyes
	on partira avec un angle de 60 degres (-30 +30 par rapport a lorientation du joueur)
	un nombre de rayon egal a WINDOW_W = 1920 (a voir si la valeur est doit etre diminue ou non)
	distance entre les rayon = 60/1920

4/		Pour afficher un mur on va checker a chaque intersection verticales puis horizontale et on comparera les 2 
	la plus petite valeur sera prise en compte;

	2 calculs a faire :
		a/	dabord de notre position exacte dans la case ou nous nous trouvons P(350, 150) nous voulons les coordonnes exactes de A (sur la ligne 300);
			on cheches lhypotenuse du triangle ci dessous;
			ya = 350 % 100		= 50
			first_xa = ya / tan(orientation du joueur)        50 / tan(60) = 28
			dist_check_xa = 150 + xa = 178
			le point a se trouvera au point suivant A(300, dist_check_xa)  = A(300, 178)
			yx = 300 / 100 - 1 = 2;
			yy = 178 / 100 = 1;
			verifier si A(300 / 100 - 1 ; 178 / 100) = A(2, 1) est un mur ou pas;
		b/	pour trouver le prochain point (dans notre cas sur la ligne 200)
			ya = 100
			last_xa = ya / tan(orientation du joueur) 100 / tan(60) = 57
			dist_check_xa += last_xa = 178 + 57 = 235
			yx--;
			yy = 235 / 100
			le point suivant se trouvera aux coordonnees B(1, 2);

			while(1)
			{
				if (map[data->xx][data->xy] == '1')
					dist_py_wall = (dist_check_xa - player_y) / cos(orient);
					break;
				else
					data->xx--;
					dist_check_xa += last_xa;
					data->xy = last_xa / 100; 
			}


		puis un decalage 


			  orientation du joueur
			A
		  /|
		 / |
		/  |
	   /   |  ya
	  /	   |
  P _______|
              B
		xa
*/


/*			a/	dabord de notre position exacte dans la case ou nous nous trouvons P(350, 150) nous voulons les coordonnes exactes de A (sur la ligne 300);
			on cheches lhypotenuse du triangle ci dessous;
			ya = 350 % 100		= 50
			first_xa = ya / tan(orientation du joueur)        50 / tan(60) = 28
			dist_check_xa = 150 + xa = 178
			le point a se trouvera au point suivant A(300, dist_check_xa)  = A(300, 178)
			yx = 300 / 100 - 1 = 2;
			yy = 178 / 100 = 1;
			verifier si A(300 / 100 - 1 ; 178 / 100) = A(2, 1) est un mur ou pas;	
*/

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == 65307)
		ft_quit(data);
	// if (keysym == 119 || keysym == 65362)
	// 	if (data->map[data->pl_y - 1][data->pl_x] != '1')
	// 		ft_move_up(data);
	// if (keysym == 115 || keysym == 65364)
	// 	if (data->map[data->pl_y + 1][data->pl_x] != '1')
	// 		ft_move_down(data);
	if (keysym == 97 || keysym == 65361)
	{
		data->player_orient += 3.00;
		if (data->player_orient >= 180)
			data->player_orient -= 360;
	}
	if (keysym == 100 || keysym == 65363)
	{
		data->player_orient -= 3.00;
		if (data->player_orient <= -180)
			data->player_orient += 360;
	}
	ft_fill_floor(data);
	return (0);
}

void	my_mlx_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_check_wall_sw(t_data *data)
{
	data->i = 0;
	data->o = 0;
	while (1)
	{
		if (data->dist_x <= data->dist_y)
		{
			data->check_y = (data->player_y - (int)data->first_xa
					- (int)data->xa * data->i) / PXL;
			data->check_x = (data->player_x / PXL) + (1 + data->i);
			if (data->map[data->check_x][data->check_y] == '1')
				break ;
			data->dist_x += data->delta_x;
			data->i++;
		}
		else
		{
			data->check_x = (data->player_x + (int)data->first_ya
					+ ((int)data->ya * data->o)) / PXL;
			data->check_y = (data->player_y / PXL) - (1 + data->o);
			if (data->map[data->check_x][data->check_y] == '1')
				break ;
			data->dist_y += data->delta_y;
			data->o++;
		}
	}
}

void	ft_check_wall_se(t_data *data)
{
	data->i = 0;
	data->o = 0;
	while (1)
	{
		if (data->dist_x <= data->dist_y)
		{
			data->check_y = (data->player_y + (int)data->first_xa
					+ (int)data->xa * data->i) / PXL;
			data->check_x = (data->player_x / PXL) + (1 + data->i);
			if (data->map[data->check_x][(int)data->check_y] == '1')
				break ;
			data->dist_x += data->delta_x;
			data->i++;
		}
		else
		{
			data->check_x = (data->player_x + (int)data->first_ya
					+ ((int)data->ya * data->o)) / PXL;
			data->check_y = (data->player_y / PXL) + (1 + data->o);
			if (data->map[data->check_x][data->check_y] == '1')
				break ;
			data->dist_y += data->delta_y;
			data->o++;
		}
	}
}

void	ft_check_wall_nw(t_data *data)
{
	data->i = 0;
	data->o = 0;
	while (1)
	{
		if (data->dist_x <= data->dist_y)
		{
			data->check_y = (data->player_y - (int)data->first_xa
					- (int)data->xa * data->i) / PXL;
			data->check_x = (data->player_x / PXL) - (1 + data->i);
			if (data->map[data->check_x][(int)data->check_y] == '1')
				break ;
			data->dist_x += data->delta_x;
			data->i++;
		}
		else
		{
			data->check_x = (data->player_x - (int)data->first_ya
					- ((int)data->ya * data->o)) / PXL;
			data->check_y = (data->player_y / PXL) - (1 + data->o);
			if (data->map[data->check_x][data->check_y] == '1')
				break ;
			data->dist_y += data->delta_y;
			data->o++;
		}
	}
}

void	ft_check_wall_ne(t_data *data)
{
	data->i = 0;
	data->o = 0;
	while (1)
	{
		if (data->dist_x <= data->dist_y)
		{
			data->check_y = (data->player_y + (int)data->first_xa
					+ (int)data->xa * data->i) / PXL;
			data->check_x = (data->player_x / PXL) - (1 + data->i);
			if (data->map[data->check_x][(int)data->check_y] == '1')
				break ;
			data->dist_x += data->delta_x;
			data->i++;
		}
		else
		{
			data->check_x = (data->player_x - (int)data->first_ya
					- ((int)data->ya * data->o)) / PXL;
			data->check_y = (data->player_y / PXL) + (1 + data->o);
			if (data->map[data->check_x][data->check_y] == '1')
				break ;
			data->dist_y += data->delta_y;
			data->o++;
		}
	}
}

void	ft_init_first(t_data *data)
{
	data->first_x = (data->delta_x * (data->player_y % PXL)) / PXL;
	data->first_xa = sqrt((data->first_x * data->first_x) - ((data->player_y
					% PXL) * (data->player_y % PXL)));
	data->first_y = data->delta_y * (data->player_x % PXL) / PXL;
	data->first_ya = sqrt((data->first_y * data->first_y) - ((data->player_x
					% PXL) * (data->player_x % PXL)));
	data->dist_x = data->first_x;
	data->dist_y = data->first_y;
	if (data->orient > 0 && data->orient < 90)
		ft_check_wall_ne(data);
	else if (data->orient > -90 && data->orient < 0)
		ft_check_wall_se(data);
	else if (data->orient < -90)
		ft_check_wall_sw(data);
	else
		ft_check_wall_nw(data);
	data->rad_beta = cos(data->beta * (M_PI / 180.00));
	if (data->dist_x < data->dist_y)
		data->dist = data->dist_x * data->rad_beta;
	else
		data->dist = data->dist_y * data->rad_beta;
}

void	ft_init_delta(t_data *data)
{
	data->anglerad = data->orient * (M_PI / 180.00);
	if ((data->orient < 90 && data->orient > 0) || data->orient < -90)
	{
		data->xa = 100 / tan(data->anglerad);
		data->ya = 100 * tan(data->anglerad);
	}
	else
	{
		data->xa = 100 / tan(data->anglerad) * (-1);
		data->ya = 100 * tan(data->anglerad) * (-1);
	}
	data->delta_x = sqrt((data->xa * data->xa) + 100 * 100);
	data->delta_y = sqrt((data->ya * data->ya) + 100 * 100);
	ft_init_first(data);
}

void	calcul_distance(t_data *data)
{
	data->beta = 30.00;
	data->orient = data->player_orient + data->beta;
	data->x = 0;
	// while (data->x < 60)
	while (data->x < WINDOW_W)
	{
		if (data->orient >= 180)
			data->orient -= 360.00;
		if (data->orient <= -180)
			data->orient += 360.00;
		ft_init_delta(data);
		data->y = (WINDOW_H / 2) - (100 / data->dist * 900);
		while ((data->y) < WINDOW_H / 2 + (100 / data->dist * 900))
		{
			if (data->y >= 0 && data->y < WINDOW_H)
				my_mlx_pixel(data, data->x, data->y, 0xFF0000);
			data->y++;
		}
		data->x++;
		data->beta -= 0.03125;
		data->orient -= 0.03125;
		// data->beta -= 1;
		// data->orient -= 1;
	}
	return;
}

void	ft_fill_floor(t_data *data)
{
	data->x = WINDOW_W;
	data->y = WINDOW_H;
	data->file = mlx_new_image(data->mlx_ptr, data->x, data->y);
	data->addr = mlx_get_data_addr(data->file, &data->bits_per_pixel,
							&data->line_length, &data->endian);
	data->y = 0;
	while ((data->y) < WINDOW_H)
	{
		data->x = 0;
		while ((data->x) < WINDOW_W)
		{
			if (data->y < WINDOW_H / 2)
				my_mlx_pixel(data, data->x, data->y, data->color_map_hex_C);
			else
				my_mlx_pixel(data, data->x, data->y, data->color_map_hex_F);
			data->x++;
		}
		data->y++;
	}
	calcul_distance(data);
	mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->file, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->file);
}

int	render(t_data *data)
{
	if (data->win_ptr != NULL)
	{
		if (data->exit == 0)
		{
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
			data->win_ptr = NULL;
		}
	}
	return (0);
}

void	ft_create_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return ;
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_W,
			WINDOW_H, "Zelda");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return ;
	}
	mlx_hook(data->win_ptr, 2, 1L << 0, &handle_keypress, data);
	mlx_hook(data->win_ptr, 17, 1L << 0, &ft_quit, data);
	mlx_loop_hook(data->mlx_ptr, &render, data);
	ft_fill_floor(data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
}
