/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 20:33:14 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/12/21 18:30:09 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"proto.h"

static int	init_map_size(t_mlx *mlx, char *totalbuf)
{
	while (*totalbuf)
	{
		while (*totalbuf && *totalbuf != ' ' && *totalbuf != '\n')
		{
			if (*totalbuf < '0' || *totalbuf > '9')
				return (ft_putstr("fdf: Incorrect character in map\n"));
			++totalbuf;
		}
		if (mlx->max.y == 0)
			++mlx->max.x;
		else
			++mlx->max.z;
		while (*totalbuf && *totalbuf == ' ')
			++totalbuf;
		if (*totalbuf == '\n' || !*totalbuf)
		{
			if (mlx->max.y && mlx->max.z != mlx->max.x)
				return (ft_putstr("fdf: Incorrect map length\n"));
			mlx->max.z = 0;
			++mlx->max.y;
			if (*totalbuf)
				++totalbuf;
		}
	}
	return (0);
}

static int	init_map(t_mlx *mlx, char *totalbuf)
{
	int		ret;

	mlx->cst.x = CSTX;
	mlx->cst.y = CSTY;
	mlx->cst.z = CSTZ;
	mlx->max.x = 0;
	mlx->max.y = 0;
	mlx->max.z = 0;
	if ((ret = init_map_size(mlx, totalbuf)))
		return (ret);
	mlx->map_size = mlx->max.x * mlx->max.y;
	return (0);
}

static void	get_map_mult(t_mlx *mlx)
{
	t_point	edge[4];

	iso_coord(mlx, mlx->max.x * (mlx->max.y - 1), &edge[0], 0);
	iso_coord(mlx, mlx->max.x - 1, &edge[1], 0);
	iso_coord(mlx, 0, &edge[2], 0);
	iso_coord(mlx, mlx->map_size - 1, &edge[3], 0);
	mlx->mult = MIN((WIN_X / (edge[1].x - edge[0].x)),
					(WIN_Y / (edge[3].y - edge[2].y)));
	mlx->trans.x = -edge[0].x * mlx->mult
		+ (WIN_X - mlx->mult * (edge[1].x - edge[0].x)) / 2;
	mlx->trans.y = -edge[2].y * mlx->mult
		+ (WIN_Y - mlx->mult * (edge[3].y - edge[2].y)) / 2;
}

void		get_map(t_mlx *mlx, char *totalbuf)
{
	int		pos;
	int		x;
	int		y;

	pos = 0;
	x = 0;
	y = 0;
	if (init_map(mlx, totalbuf) != 0)
		exit(EXIT_FAILURE);
	if ((mlx->map = malloc(sizeof(t_point) * (mlx->map_size))) == NULL)
		return ;
	while (*totalbuf)
	{
		mlx->map[pos].x = x++;
		mlx->map[pos].y = y;
		mlx->map[pos].z = ft_atoi(totalbuf);
		while (*totalbuf && *totalbuf != ' ' && *totalbuf != '\n')
			++totalbuf;
		if (*totalbuf == '\n' && (++y))
			x = 0;
		while (*totalbuf && (*totalbuf == ' ' || *totalbuf == '\n'))
			++totalbuf;
		++pos;
	}
	get_map_mult(mlx);
}
