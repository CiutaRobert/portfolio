/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 00:45:45 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/02/15 00:45:45 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<math.h>
#include	"rtv1.h"

double		norme_vector(t_xyz *xyz)
{
	double	res;

	res = sqrt(pow(xyz->x, 2) + pow(xyz->y, 2) + pow(xyz->z, 2));
	return (res);
}

void		get_normal(t_xyz *normal, t_xyz *p, t_obj *obj)
{
	if (obj->type == SPHERE)
		*normal = (t_xyz){p->x, p->y, p->z};
	else if (obj->type == CYLINDER)
		*normal = (t_xyz){p->x, p->y, 0};
	else if (obj->type == CONE)
		*normal = (t_xyz){p->x, p->y, -0.7 * p->z};
	else if (obj->type == PLAN)
		*normal = (t_xyz){0, 0, 100};
}

u_int		calc_light(t_mlx *mlx, t_xyz *spot)
{
	t_xyz	p;
	t_xyz	light;
	t_xyz	normal;
	double	cos_a;
	u_int	new_color;

	p = (t_xyz){mlx->eye.x + mlx->k * mlx->vector.x,
				mlx->eye.y + mlx->k * mlx->vector.y,
				mlx->eye.z + mlx->k * mlx->vector.z};
	light = (t_xyz){spot->x - p.x, spot->y - p.y, spot->z - p.z};
	new_color = mlx->cur_obj->color;
	get_normal(&normal, &p, mlx->cur_obj);
	cos_a = (normal.x * light.x + normal.y * light.y + normal.z * light.z)
		/ (norme_vector(&normal) * norme_vector(&light));
	new_color = (cos_a >= 0 && cos_a <= 1)
		? mult_color(mlx->cur_obj->color, cos_a) : 0;
	return (new_color);
}
