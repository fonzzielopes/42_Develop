/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:12:01 by alopes            #+#    #+#             */
/*   Updated: 2021/04/22 12:45:24 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

typedef struct  s_vars {
        void    *mlx;
        void    *win;
}               t_vars;
/*
int             close(int keycode, t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
}
*/
int main(void)
{
    t_vars  vars;
    
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 500, 500, "Test Image");
    mlx_pixel_put(vars.mlx, vars.win, 250, 250, 0xFFFFFF);
   // mlx_hook(vars.win, 2, 1L<<0, close, &vars);

    mlx_loop(vars.mlx);
}