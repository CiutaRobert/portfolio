/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 10:17:30 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/01/17 10:17:31 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<mlx.h>
#include		"wolf3d.h"

int				main(void)
{
	t_mlx		mlx;

	if (!(mlx.ptr = mlx_init()))
		return (puterror("mlx_init"));
	mlx.win = mlx_new_window(mlx.ptr, WIN_X, WIN_Y, "Wolf3D FTW!");
	init_all(&mlx);
	draw_wolf3d(&mlx);
	mlx_expose_hook(mlx.win, &get_expose, &mlx);
	mlx_hook(mlx.win, 2, 1, &get_keypress, &mlx);
	mlx_hook(mlx.win, 3, 2, &get_keyrelease, &mlx);
	mlx_loop_hook(mlx.ptr, &get_loop, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
