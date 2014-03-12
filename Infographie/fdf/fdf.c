/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 15:40:36 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/12/21 18:24:49 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			<mlx.h>
#include			"proto.h"

void				pxl_putimg(t_mlx *mlx, int x, int y, unsigned int color)
{
	int				i;
	int				dest;
	unsigned int	new_color;

	if (y < 0 || x < 0)
		return ;
	new_color = mlx_get_color_value(mlx->ptr, color);
	dest = y * mlx->sline + x * (mlx->bpp / 8);
	i = -1;
	while (++i < mlx->bpp / 8)
	{
		if (mlx->endian == 0)
			mlx->data[dest + i] = new_color >> (i * 8) & 0xFF;
		else
			mlx->data[dest + i] = new_color >> (mlx->bpp - (i + 1) * 8) & 0xFF;
	}
}

static void			line(t_point *begin, t_point *end,
						 t_mlx *mlx, int color)
{
	int				cur;

	if (ABS((begin->x - end->x)) >= ABS((begin->y - end->y)))
	{
		if (begin->x > end->x)
			line(end, begin, mlx, color);
		cur = begin->x - 1;
		while (++cur < end->x)
			pxl_putimg(mlx, cur,
					   begin->y + ((end->y - begin->y) * (cur - begin->x))
						/ (end->x - begin->x), color);
	}
	else
	{
		if (begin->y > end->y)
			line(end, begin, mlx, color);
		cur = begin->y - 1;
		while (++cur < end->y)
			pxl_putimg(mlx, begin->x + ((end->x - begin->x) * (cur - begin->y))
						/ (end->y - begin->y), cur, color);
	}
}

void				iso_coord(t_mlx *mlx, int pos, t_point *coord, int is_calc)
{
	coord->x = mlx->cst.x * mlx->map[pos].x - mlx->cst.y * mlx->map[pos].y;
	coord->y = -mlx->cst.z * mlx->map[pos].z + (mlx->cst.x / 2.0)
		* mlx->map[pos].x + (mlx->cst.y / 2.0) * mlx->map[pos].y;
	if (is_calc)
	{
		coord->x = coord->x * mlx->mult + mlx->trans.x;
		coord->y = coord->y * mlx->mult + mlx->trans.y;
	}
}

void				aff_fdf(t_mlx *mlx)
{
	int				i;
	t_point			cur;
	t_point			prev;

	i = -1;
	while (++i < mlx->map_size)
	{
		iso_coord(mlx, i, &cur, 1);
		if (i - 1 >= 0 && i % (int)mlx->max.x != 0)
		{
			iso_coord(mlx, i - 1, &prev, 1);
			line(&cur, &prev, mlx, 0xFFFFFF);
		}
		if (i - (int)mlx->max.x >= 0)
		{
			iso_coord(mlx, i - (int)mlx->max.x, &prev, 1);
			line(&cur, &prev, mlx, 0xFFFFFF);
		}
	}
}
