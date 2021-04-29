/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:37:51 by alopes            #+#    #+#             */
/*   Updated: 2021/04/29 17:45:44 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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

	t_player	fonzz;
}               t_data;

typedef struct s_param{
	int		x;
	int		y;
	char	str[3];
}				t_param;


#endif
