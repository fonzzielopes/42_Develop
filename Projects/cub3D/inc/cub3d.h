/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:24:56 by alopes            #+#    #+#             */
/*   Updated: 2021/05/07 17:03:03 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <math.h>
# include <string.h>
# include "../libft/libft.h"
# include "../inc/key_macos.h"
# include "../inc/structs.h"
# include "../libft/get_next_line.h"
# include "../minilibx/mlx.h"

#define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_EXIT		17 //Exit program key code

#define KEY_ESC			53

# define TO_COORD(X, Y) ((int)floor(Y) * WIDTH + (int)floor(X))


int			main(void);
void		ready_game_player(t_game *game);
double		deg_to_rad(double deg);
void	draw_line(t_game *game, double x1, double y1, double x2, double y2);
void 	draw_lines(t_game *game);
void	draw_rectangle(t_game *game, int x, int y);
void	draw_rectangles(t_game *game);
void	game_init(t_game *game);
void	*ft_memcpy(void *dst, const void *src, size_t n);

void	get_starting_position(t_player *player, char **map, t_game *game);
double	get_starting_orientation(char orientation);
double	deg_to_rad(double deg);


#endif
