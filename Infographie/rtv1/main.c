/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 21:20:17 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/02/15 00:45:38 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<mlx.h>
#include		<math.h>
#include		<stdlib.h>
#include		"rtv1.h"

static void		init_all(t_mlx *mlx)
{
	mlx->focale = WIN_X / (tan(0.7));
	mlx->eye = (t_xyz){-mlx->focale - 200, 0, 0};
	mlx->eyerot = (t_xyz){0, 0, 0};
	mlx->spot = (t_xyz){0, 200, 400};
	mlx->spot2 = (t_xyz){0, -200, 400};
	mlx->objs = NULL;
	obj_pushback(&mlx->objs, obj_new(SPHERE, (t_xyz){0, 100, 0},
									(t_xyz){0, 0, 0}, 0xFF0000));
	obj_pushback(&mlx->objs, obj_new(SPHERE, (t_xyz){0, -100, 0},
									(t_xyz){0, 0, 0}, 0x00FF00));
	obj_pushback(&mlx->objs, obj_new(CYLINDER, (t_xyz){0, 0, 0},
									(t_xyz){0, 0, 0}, 0xFF00FF));
	obj_pushback(&mlx->objs, obj_new(PLAN, (t_xyz){0, 0, -90},
									(t_xyz){0, -0.1, 0}, 0x0000FF));
}

int				main(void)
{
	t_mlx		mlx;

	if (!(mlx.ptr = mlx_init()))
		return (puterror("mlx_init"));
	mlx.screen.ptr = mlx_new_image(mlx.ptr, WIN_X, WIN_Y);
	mlx.screen.data = mlx_get_data_addr(mlx.screen.ptr, &mlx.screen.bpp,
										&mlx.screen.sline, &mlx.screen.endian);
	mlx.screen.bpp = mlx.screen.bpp >> 3;
	init_all(&mlx);
	calc_rtv1(&mlx);
	mlx.win = mlx_new_window(mlx.ptr, WIN_X, WIN_Y, "RTV1 yolo");
	mlx_expose_hook(mlx.win, &get_expose, &mlx);
	mlx_key_hook(mlx.win, &get_keypress, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
