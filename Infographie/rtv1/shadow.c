/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 00:46:17 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/02/15 00:46:17 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdio.h>
#include	"rtv1.h"

static void	set_vectors(t_mlx *mlx, t_xyz *spot, t_xyz *p, t_xyz *light)
{
	*p = (t_xyz){mlx->eye.x + mlx->k * mlx->vector.x,
				mlx->eye.y + mlx->k * mlx->vector.y,
				mlx->eye.z + mlx->k * mlx->vector.z};
	*light = (t_xyz){spot->x - p->x, spot->y - p->y, spot->z - p->z};
}

u_int		shadow_cast(t_mlx *mlx, t_xyz *spot, u_int cur_color)
{
	t_xyz	p;
	t_xyz	light;
	double	new_k;
	double	k[2];
	t_obj	*tmp;

	if (mlx->cur_obj->type != PLAN)
		return (cur_color);
	set_vectors(mlx, spot, &p, &light);
	new_k = -1;
	tmp = mlx->objs;
	while (tmp)
	{
		if (tmp != mlx->cur_obj)
		{
			calc_curobj(&p, &light, tmp, k);
			new_k = (k[0] > 0.1 && k[0] < 0.9) ? k[0] : new_k;
			new_k = (k[1] > 0.1 && k[1] < 0.9) ? k[1] : new_k;
		}
		tmp = tmp->next;
	}
	cur_color = (new_k != -1) ? mult_color(cur_color, 0.6) : cur_color;
	return (cur_color);
}
