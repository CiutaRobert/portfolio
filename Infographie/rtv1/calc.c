/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 21:20:05 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/02/15 00:46:03 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<math.h>
#include	<stdlib.h>
#include	"rtv1.h"

void		move_eye(t_xyz *eye, t_xyz *vector, t_obj *tmp, int invert)
{
	if (invert == 1)
	{
		all_rot(eye, &tmp->rot, invert);
		all_rot(vector, &tmp->rot, invert);
	}
	eye->x += invert * tmp->pos.x;
	eye->y += invert * tmp->pos.y;
	eye->z += invert * tmp->pos.z;
	vector->x += invert * tmp->pos.x;
	vector->y += invert * tmp->pos.y;
	vector->z += invert * tmp->pos.z;
	if (invert == -1)
	{
		all_rot(eye, &tmp->rot, invert);
		all_rot(vector, &tmp->rot, invert);
	}
}

void		calc_curobj(t_xyz *eye, t_xyz *vector, t_obj *obj, double *k)
{
	move_eye(eye, vector, obj, -1);
	if (obj->type == SPHERE)
		calc_sphere(eye, vector, k);
	else if (obj->type == CYLINDER)
		calc_cylinder(eye, vector, k);
	else if (obj->type == CONE)
		calc_cone(eye, vector, k);
	else if (obj->type == PLAN)
		calc_plan(eye, vector, k);
	move_eye(eye, vector, obj, 1);
}

static void	calc_inter(int x, int y, t_mlx *mlx)
{
	double	k[2];
	t_obj	*tmp;
	u_int	color;

	mlx->k = 0xFFFFFFFF;
	mlx->cur_obj = NULL;
	tmp = mlx->objs;
	while (tmp)
	{
		calc_curobj(&mlx->eye, &mlx->vector, tmp, k);
		if (k[0] >= 0 && mlx->k > k[0] && (mlx->cur_obj = tmp))
			mlx->k = k[0];
		if (k[1] >= 0 && mlx->k > k[1] && (mlx->cur_obj = tmp))
			mlx->k = k[1];
		tmp = tmp->next;
	}
	if (mlx->cur_obj != NULL)
	{
		color = calc_light(mlx, &mlx->spot);
		color = add_2color(color, calc_light(mlx, &mlx->spot2));
		color = mult_color(color, 0.7);
		color = shadow_cast(mlx, &mlx->spot, color);
		color = shadow_cast(mlx, &mlx->spot2, color);
		pxl_putimg(mlx, x, y, color);
	}
}

static void	calc_ray_xy(int x, int y, t_mlx *mlx)
{
	mlx->plan.x = mlx->focale;
	mlx->plan.y = (WIN_X / 2.0) - x;
	mlx->plan.z = (WIN_Y / 2.0) - y;
	mlx->vector.x = mlx->plan.x - mlx->eye.x;
	mlx->vector.y = mlx->plan.y - mlx->eye.z;
	mlx->vector.z = mlx->plan.z - mlx->eye.z;
	all_rot(&mlx->vector, &mlx->eyerot, 1);
	calc_inter(x, y, mlx);
}

void		calc_rtv1(t_mlx *mlx)
{
	int		x;
	int		y;
	int		prev_perc;

	prev_perc = -1;
	all_rot(&mlx->eye, &mlx->eyerot, 1);
	ft_putstr("LOADING... [");
	x = -1;
	while (++x < WIN_X)
	{
		y = -1;
		while (++y < WIN_Y)
		{
			calc_ray_xy(x, y, mlx);
			if (100 * (y + x * WIN_Y) / (WIN_X * WIN_Y) > prev_perc + 1)
			{
				prev_perc = 100 * (y + x * WIN_Y) / (WIN_X * WIN_Y);
				ft_putstr("=");
			}
		}
	}
	ft_putstr("]\n");
}
