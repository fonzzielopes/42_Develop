/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:12:01 by alopes            #+#    #+#             */
/*   Updated: 2021/04/29 13:10:49 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int				key_press(int keycode, t_param *param)
{
	(void) param;

	if (keycode == KEY_ESC || keycode == K_X) //Quit the program when ESC or X key pressed
		exit(0);
	return (0);
}

int main(void)
{
    t_vars  vars;
	t_data	img;
	t_param	param;

    //param_init(&param);
	vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 720, 480, "Test Image");
	img.img = mlx_new_image(vars.mlx, 720, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 360, 240, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0 , 0);

	mlx_hook(vars.win, X_EVENT_KEY_PRESS, 0, &key_press, &param);

    mlx_loop(vars.mlx);
}
