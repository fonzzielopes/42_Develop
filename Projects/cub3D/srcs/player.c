/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:23:21 by alopes            #+#    #+#             */
/*   Updated: 2021/05/07 17:02:40 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ready_game_player(t_game *game)
{
	int		i;
	int		j;

	i = TILE_SIZE / 10;
	j = TILE_SIZE / 10;

	game->img.data[i * WIDTH + j] = 0x008A1F;

}




/*void	ready_game_player(t_game *game)
{
	game->player.walk_direction = 0;
	game->player.move_speed = 0.15;
	game->player.turn_direction = 0;
	game->player.rotation_speed = deg_to_rad(4);
	get_starting_position(&game->player, game->scene.map.grid, &game);
}

double	deg_to_rad(double deg)
{
	return (deg * M_PI / 180.0);
}

double	get_starting_orientation(char orientation)
{
	double	radian;

	radian = 0;
	if (orientation == 'N')
		radian = deg_to_rad(270);
	else if (orientation == 'S')
		radian = deg_to_rad(90);
	else if (orientation == 'E')
		radian = deg_to_rad(360);
	else if (orientation == 'W')
		radian = deg_to_rad(180);
	return (radian);
}

void	get_starting_position(t_player *player, char **map, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("NSEW", map[i][j]))
			{
				player->x = j + 0.5;
				player->y = i + 0.5;
				game->img.data[(i) * WIDTH + j] = 0x008A1F;
				player->rotation_angle = get_starting_orientation(map[i][j]);
				map[i][j] = '0';
			}
		}
	}
}
*/
