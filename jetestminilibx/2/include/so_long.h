/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:06:32 by kaly              #+#    #+#             */
/*   Updated: 2023/05/06 13:21:22 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#  include <X11/X.h>
#  include <X11/keysym.h>
#  include <stdlib.h>
#  include <stdio.h>
#  include <mlx.h>

# define WINDOW_LARGE 1000
# define WINDOW_HEIGHT 500

# define MLX_ERROR 1

# define RED_PIXEL 0xFF0000

typedef struct s_data {
        void    *mlx_ptr;
        void    *win_ptr;
        void    *file;
	char	**map;
        int     pxl;
        int     map_x;
        int     map_y;
        int     x;
        int     y;
	int	release;
}       t_data;

#endif
