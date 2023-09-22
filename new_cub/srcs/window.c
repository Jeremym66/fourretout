/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:40:05 by kaly              #+#    #+#             */
/*   Updated: 2023/09/22 15:41:45 by jmetezea         ###   ########.fr       */
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
		data->player_orient += 1.00;
		if (data->player_orient >= 180)	
			data->player_orient -= 360;
	}
	if (keysym == 100 || keysym == 65363)
	{
		data->player_orient -= 1.00;
		if (data->player_orient <= -180)
			data->player_orient += 360;
	}
	ft_fill_floor(data);
	
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_init_dist(t_data *data)
{
	if(data->orient > 0 && data->orient < 90 )
	{
		data->dist_x = data->first_x / cos(data->anglerad);
		data->dist_y = data->first_y / sin(data->anglerad);
	}
	else if(data->orient > -90 && data->orient < 0 )
	{
		data->dist_x = data->first_x / cos(data->anglerad);
		data->dist_y = data->first_y / sin(data->anglerad) * (-1);
	}
	else if (data->orient < -90)
	{
		data->dist_x = data->first_x / cos(data->anglerad) * (-1);
		data->dist_y = data->first_y / sin(data->anglerad) * (-1);
	}
	else
	{
		data->dist_x = data->first_x / cos(data->anglerad) * (-1);
		data->dist_y = data->first_y / sin(data->anglerad);
	}
	// printf("orient                    %lf\n", data->orient);
	// printf("delta x %lf\n", data->delta_x);
	// printf("delta y %lf\n", data->delta_y);
	// printf("first x %lf\n", data->first_x);
	// printf("first y %lf\n", data->first_y);
	// printf("dist x %lf\n", data->dist_x);
	// printf("dist y %lf\n", data->dist_y);
}

void	ft_init_first(t_data *data) // Decalage dans la premiere case selon la pos de depart
{
	data->first_x = data->delta_x * (data->player_y % PXL) / PXL;	
	data->first_y = data->delta_y * (data->player_x % PXL) / PXL;
	ft_init_dist(data);

}
void	ft_init_delta(t_data *data) // Decalage dune case complete a lautre
{
	data->anglerad = data->orient * (M_PI / 180.00);
	if(data->orient > 90 || (data->orient < 0 && data->orient > -90 ))
	{
		data->delta_x = 100 / tan(data->anglerad)* (-1);
		data->delta_y = 100 * tan(data->anglerad)* (-1);
	}
	else
	{
		data->delta_x = 100 / tan(data->anglerad);
		data->delta_y = 100 * tan(data->anglerad);		
	}
	ft_init_first(data);
}

void		calcul_distance(t_data *data)
{
	data->beta = 30.00;
	data->orient = data->player_orient + data->beta;
	// ft_init_delta(data);
	data->x = 0;
	while (data->x < WINDOW_W)
	{
		if (data->orient >= 180)	
			data->orient -= 360.00;
		if (data->orient <= -180)
			data->orient += 360.00;
		data->rad_beta = cos(data->beta * (M_PI / 180.00));
		ft_init_delta(data);
		if (data->dist_x < data->dist_y)
			data->dist = data->dist_x * data->rad_beta;
		else
			data->dist = data->dist_y * data->rad_beta;
		data->y = (WINDOW_H / 2) - (50 / data->dist * 250);
		while ((data->y) < WINDOW_H / 2 + (50 / data->dist * 250))
		{
			if (data->y >= 0 && data->y < WINDOW_H)
				my_mlx_pixel_put(data, data->x, data->y, 0xFF0000);
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
				my_mlx_pixel_put(data, data->x, data->y, data->color_map_hex_C);
			else
				my_mlx_pixel_put(data, data->x, data->y, data->color_map_hex_F);
			data->x++;
		}
		data->y++;
	}
	calcul_distance(data);
	mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->file, 
								0, 0);
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
// void calcul_first_xa(t_data	*data)
// {
// 	printf("data->orient : %lf\n", data->orient);
// 	if (data->orient >= 0 && data->orient <= 90)
// 	{
// 		data->ya = data->player_x % PXL;
// 		data->first_xa = data->ya / tan(data->anglerad);
// 		data->check_xa = data->player_y + data->first_xa;
// 		data->dist_xa = data->first_xa / cos(data->anglerad);
// 		// printf("data->ya : %lf\n", data->ya);
// 		// printf("data->first_xa : %lf\n", data->first_xa);
// 		// printf("data->check_xa : %lf\n", data->check_xa);
// 		// printf("data->dist_xa : %lf\n", data->dist_xa);
// 		data->xa = PXL - (data->player_y % PXL);
// 		data->first_ya = data->xa * tan(data->anglerad);
// 		data->check_ya = data->player_x - data->first_ya;
// 		data->dist_ya = data->xa / cos(data->anglerad);
// 		// printf("data->xa : %lf\n", data->xa);
// 		// printf("data->first_ya : %lf\n", data->first_ya);
// 		// printf("data->check_ya : %lf\n", data->check_ya);
// 		// printf("data->dist_ya : %lf\n", data->dist_ya);
// 	}
// 	if (data->orient > 90 && data->orient <= 180)
// 	{
// 		data->ya = PXL - data->player_x % PXL;
// 		data->first_xa = data->ya / tan(data->anglerad);
// 		data->check_xa = data->player_y - data->first_xa;
// 		data->dist_xa = data->first_xa / cos(data->anglerad);
// 		printf("data->ya : %lf\n", data->ya);
// 		printf("data->first_xa : %lf\n", data->first_xa);
// 		printf("data->check_xa : %lf\n", data->check_xa);
// 		printf("data->dist_xa : %lf\n", data->dist_xa);
// 		data->xa = PXL - (data->player_y % PXL);
// 		data->first_ya = (data->xa * tan(data->anglerad));
// 		data->check_ya = data->player_x - data->first_ya;
// 		data->dist_ya = data->xa / cos(data->anglerad) * (-1);
// 		printf("data->xa : %lf\n", data->xa);
// 		printf("data->first_ya : %lf\n", data->first_ya);
// 		printf("data->check_ya : %lf\n", data->check_ya);
// 		printf("data->dist_ya : %lf\n", data->dist_ya);
// 	}
// 	if (data->orient > 180 && data->orient <= 270)
// 	{
// 		data->ya = PXL - data->player_x % PXL;
// 		data->first_xa = data->ya / tan(data->anglerad);
// 		data->check_xa = data->player_y - data->first_xa;
// 		data->dist_xa = data->first_xa / cos(data->anglerad - 180) * (-1);
// 		printf("data->ya : %lf\n", data->ya);
// 		printf("data->first_xa : %lf\n", data->first_xa);
// 		printf("data->check_xa : %lf\n", data->check_xa);
// 		printf("data->dist_xa : %lf\n", data->dist_xa);
// 		data->xa = data->player_y % PXL;
// 		data->first_ya = (data->xa * tan(data->anglerad));
// 		data->check_ya = data->player_x + data->first_ya;
// 		data->dist_ya = data->xa / cos(data->anglerad - 180);
// 		printf("data->xa : %lf\n", data->xa);
// 		printf("data->first_ya : %lf\n", data->first_ya);
// 		printf("data->check_ya : %lf\n", data->check_ya);
// 		printf("data->dist_ya : %lf\n", data->dist_ya);
// 	}
// 	return ;
// }


// void		calcul_distance(t_data *data)
// {
// 	double	beta;
// 	double	data->rad_beta;
// 	double	temp;

// 	beta = 30.00;
// 	data->player_orient = 250.00;
// 	data->orient = data->player_orient + beta;
// 	// if (data->orient > 180.00)
// 	// 	data->orient -= 180.00;
// 	temp = data->orient - 60.00;
// 	data->x = 0;
// 	while (data->orient > temp)
// 	{
// 		// ft_printf("test\n");
// 		data->rad_beta = cos(beta * (M_PI / 180.00));
// 		data->orient = data->player_orient + beta;
// 		data->anglerad = data->orient * (M_PI / 180.00);
// 		calcul_first_xa(data);
// 		if (data->dist_xa < data->dist_ya)
// 			data->dist = data->dist_xa * data->rad_beta;
// 		else
// 			data->dist = data->dist_ya * data->rad_beta;
// 		data->y = (WINDOW_H / 2) - (PXL / data->dist * 250);
// 			while ((data->y) < WINDOW_H / 2 + (PXL / data->dist * 250))
// 			{
// 				if (data->y >= 0 && data->y < WINDOW_H)
// 					my_mlx_pixel_put(data, data->x, data->y, 0xFF0000);
// 				data->y++;
// 			}
// 		data->x++;
// 		beta -= 1;
// 		// beta -= 0.03125;
// 	}
// 	return;
// }
// void		calcul_distance(t_data *data)
// {
// 	double	beta;
// 	double	data->rad_beta;
// 	double	temp;

// 	beta = 30.00;
// 	data->player_orient = 30.00;
// 	data->orient = data->player_orient + beta;
// 	// if (data->orient > 180.00)
// 	// 	data->orient -= 180.00;
// 	temp = data->orient - 60.00;
// 	data->x = 0;
// 	while (data->orient > temp)
// 	{
// 		// ft_printf("test\n");
// 		data->rad_beta = cos(beta * (M_PI / 180.00));
// 		data->orient = data->player_orient + beta;
// 		// if (data->orient > 90)
// 		// 	data->anglerad = (data->orient - 90) * (M_PI / 180.00);
// 		// else if (data->orient < -90)
// 		// 	data->anglerad = (data->orient + 90) * (M_PI / 180.00);
// 		// else
// 		data->anglerad = data->orient * (M_PI / 180.00);
// 		calcul_first_xa(data);
// 		if (data->dist_xa < data->dist_ya)
// 			data->dist = data->dist_xa * data->rad_beta;
// 		else
// 			data->dist = data->dist_ya * data->rad_beta;
// 		data->y = (WINDOW_H / 2) - (PXL / data->dist * 250);
// 			while ((data->y) < WINDOW_H / 2 + (PXL / data->dist * 250))
// 			{
// 				if (data->y >= 0 && data->y < WINDOW_H)
// 					my_mlx_pixel_put(data, data->x, data->y, 0xFF0000);
// 				data->y++;
// 			}
// 		data->x++;
// 		// beta -= 1;
// 		beta -= 0.03125;
// 	}
// 	return;
// }

// int		calcul_distance(t_data *data)
// {
// 	int	index;
// 	int	i;

// 	data->orient = 60.00;
// 	data->anglerad = data->orient * (M_PI / 180.00);
// 	calcul_first_xa(data);
// 	printf("test du clacul : \ndata x : %d\n", data->player_x);
// 	printf("data y : %d\n", data->player_y);
// 	i = 0;
// 	while ((data->player_x - i) % 100 != 0)
// 		i++;
// 	printf("1er intersection data x : %d\n", data->player_x - i);
// 	index = ((data->player_x - i) / 100) - 1;
// 	printf("1er intersection data x : %d\n", index);
// 	while (1)
// 	{
// 		printf("test avex %c\n", data->map[index][data->player_y / 100]);
// 		if (data->map[index][data->player_y / 100] == '1')
// 		{
// 			data->x = WINDOW_W / 2 - 300;
// 			while ((data->x) < WINDOW_W / 2 + 300)
// 			{
// 				data->y = (WINDOW_H / 2) - (200 / (i / 100));
// 				while ((data->y) < WINDOW_H / 2 + (200 / (i / 100)))
// 				{
// 					my_mlx_pixel_put(data, data->x, data->y, 0xFF0000);
// 					data->y++;
// 				}
// 			data->x++;
// 			}
// 			printf("je renvoie : %d", i);
// 			return (i);
// 		}
// 		index--;
// 		i += 100;
// 	}
// 	return (i);	
// }

// void	affiche_un_mur(t_data *data)
// {
// 	data->x = WINDOW_W / 2 - 300;
// 	while ((data->x) < WINDOW_W / 2 + 300)
// 	{
// 		data->y = WINDOW_H / 2 - 200;

// 		while ((data->y) < WINDOW_H / 2 + 200)
// 		{
// 			my_mlx_pixel_put(data, data->x, data->y, 0xFF0000);
// 			data->y++;
// 		}
// 		data->x++;
// 	}
// }

// void calcul_first_xa(t_data	*data)
// {
// 	printf("data->orient : %lf\n", data->orient);
// 	if (data->orient >= -90 && data->orient <= 90)
// 	{
// 		data->ya = data->player_x % PXL;
// 		if (data->orient >= 0)
// 			data->first_xa = data->ya / tan(data->anglerad);
// 		else
// 			data->first_xa = data->ya / tan(data->anglerad) * (-1);
// 		data->check_xa = data->player_y + data->first_xa;
// 		data->dist_xa = data->first_xa / cos(data->anglerad);
// 		printf("data->ya : %lf\n", data->ya);
// 		printf("data->first_xa : %lf\n", data->first_xa);
// 		printf("data->check_xa : %lf\n", data->check_xa);
// 		printf("data->dist_xa : %lf\n", data->dist_xa);

// 		data->xa = PXL - (data->player_y % PXL);
// 		if (data->orient >= 0)
// 		{
// 			data->first_ya = data->xa * tan(data->anglerad);
// 			data->check_ya = data->player_x - data->first_ya;
// 		}
// 		else
// 		{
// 			data->first_ya = data->xa * tan(data->anglerad) * (-1);
// 			data->check_ya = data->player_x + data->first_ya;
// 		}
// 			data->dist_ya = data->xa / cos(data->anglerad);
// 			printf("data->xa : %lf\n", data->xa);
// 			printf("data->first_ya : %lf\n", data->first_ya);
// 			printf("data->check_ya : %lf\n", data->check_ya);
// 			printf("data->dist_ya : %lf\n", data->dist_ya);
// 	}
// 		if (data->orient > 90)
// 	{
// 		data->ya = PXL - data->player_x % PXL;
// 		data->first_xa = data->ya / tan(data->anglerad);
// 		data->check_xa = data->player_y - data->first_xa;
// 		data->dist_xa = data->first_xa / cos(data->anglerad);
// 		printf("data->ya : %lf\n", data->ya);
// 		printf("data->first_xa : %lf\n", data->first_xa);
// 		printf("data->check_xa : %lf\n", data->check_xa);
// 		printf("data->dist_xa : %lf\n", data->dist_xa);
// 		data->xa = PXL - (data->player_y % PXL);
// 		data->first_ya = (data->xa * tan(data->anglerad));
// 		data->check_ya = data->player_x - data->first_ya;
// 		data->dist_ya = data->xa / cos(data->anglerad) * (-1);
// 		printf("data->xa : %lf\n", data->xa);
// 		printf("data->first_ya : %lf\n", data->first_ya);
// 		printf("data->check_ya : %lf\n", data->check_ya);
// 		printf("data->dist_ya : %lf\n", data->dist_ya);
// 	}
	// if (data->orient > 90 && data->orient < -90)
	// {
		
	// 	data->ya = PXL - data->player_x % PXL;
	// 	if (data->orient > 0)
	// 		data->first_xa = data->ya / tan(data->anglerad - data->anglerad90);
	// 	else
	// 		data->first_xa = data->ya / tan(data->anglerad) * (-1);
	// 	data->check_xa = data->player_y - data->first_xa;
	// 	data->dist_xa = data->first_xa / cos(data->anglerad) * (-1);
	// 	printf("data->ya : %lf\n", data->ya);
	// 	printf("data->first_xa : %lf\n", data->first_xa);
	// 	printf("data->check_xa : %lf\n", data->check_xa);
	// 	printf("data->dist_xa : %lf\n", data->dist_xa);

	// 	data->xa = PXL - (data->player_y % PXL);
	// 	if (data->orient > 0)
	// 	{
	// 		data->first_ya = data->xa * tan(data->anglerad - data->anglerad90);
	// 		data->check_ya = data->player_x - data->first_ya;
	// 	}
	// 	else
	// 	{
	// 		data->first_ya = (data->xa * tan(data->anglerad)) * (-1);
	// 		data->check_ya = data->player_x + data->first_ya;
	// 	}
	// 	data->dist_ya = data->xa / cos(data->anglerad) * (-1);
	// 	printf("data->xa : %lf\n", data->xa);
	// 	printf("data->first_ya : %lf\n", data->first_ya);
	// 	printf("data->check_ya : %lf\n", data->check_ya);
	// 	printf("data->dist_ya : %lf\n", data->dist_ya);
	// }
// 	return ;
// }