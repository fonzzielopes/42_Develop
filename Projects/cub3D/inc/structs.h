/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:37:51 by alopes            #+#    #+#             */
/*   Updated: 2021/05/07 16:56:55 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../inc/cub3d.h"

# define TILE_SIZE 50
# define ROWS 11
# define COLS 15
# define WIDTH COLS * TILE_SIZE
# define HEIGHT ROWS * TILE_SIZE

typedef struct  s_vars {
        void    *mlx;
        void    *win;
}               t_vars;

typedef struct	s_player
{
	double		x;
	double		y;
	double		radius;
	char		walk_direction;
	double		move_speed;
	int			turn_direction;
	double		rotation_angle;
	double		rotation_speed;
}				t_player;

typedef struct	s_map
{
	char		**grid;
	int			width;
	int			height;
}				t_map;

typedef struct	s_scene
{
	t_map		map;
}				t_scene;

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;

	t_player	player;
}               t_data;

typedef struct s_param{
	int		x;
	int		y;
	char	str[3];
}				t_param;


typedef struct	s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	char	**grid;
	int		map[ROWS][COLS];
	t_player	player;
	t_scene		scene;

}				t_game;

#endif
