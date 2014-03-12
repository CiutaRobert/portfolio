/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 10:17:37 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/01/17 10:17:37 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<mlx.h>
#include	"wolf3d.h"

static void	load_img(t_mlx *mlx, t_img *img, char *path)
{
	img->ptr = mlx_xpm_file_to_image(mlx->ptr, path, &img->x, &img->y);
	img->data = mlx_get_data_addr(img->ptr, &img->bpp,
								&img->sline, &img->endian);
	img->bpp = img->bpp >> 3;
}

static void	load_gun(t_mlx *mlx)
{
	int		i;
	char	*pathgun[] = {"imgs/gun00.xpm", "imgs/gun01.xpm", "imgs/gun02.xpm",
						"imgs/gun03.xpm", "imgs/gun04.xpm", "imgs/gun05.xpm",
						"imgs/gun06.xpm", "imgs/gun07.xpm", "imgs/gun08.xpm",
						"imgs/gun09.xpm", "imgs/gun10.xpm"};

	mlx->cur_g = 0;
	i = -1;
	while (++i < 11)
		load_img(mlx, &mlx->gun[i], pathgun[i]);
}

static void	load_wall(t_mlx *mlx)
{
	int		i;
	char	*path[8] = {"imgs/wall0.xpm", "imgs/wall1.xpm", "imgs/wall2.xpm",
						"imgs/wall3.xpm", "imgs/wall4.xpm", "imgs/wall5.xpm",
						"imgs/door.xpm", "imgs/youwin.xpm"};

	i = -1;
	while (++i < 8)
		load_img(mlx, &mlx->wall[i], path[i]);
}

void		init_all(t_mlx *mlx)
{
	int		i;
	t_img	load;

	mlx->x0 = 30.5;
	mlx->y0 = 8.5;
	mlx->a = 4.7;
	i = -1;
	while (++i < 5)
		mlx->event[i] = 0;
	load_img(mlx, &load, "imgs/load.xpm");
	mlx_put_image_to_window(mlx->ptr, mlx->win, load.ptr,
							(WIN_X - load.x) / 2, (WIN_Y - load.y) / 2);
	mlx->screen.ptr = mlx_new_image(mlx->ptr, WIN_X, WIN_Y);
	mlx->screen.data = mlx_get_data_addr(mlx->screen.ptr, &mlx->screen.bpp,
									&mlx->screen.sline, &mlx->screen.endian);
	mlx->screen.bpp = mlx->screen.bpp >> 3;
	load_img(mlx, &mlx->sky, "imgs/sky.xpm");
	load_wall(mlx);
	load_gun(mlx);
	get_laby(mlx->laby, 1);
	get_laby(mlx->laby_mask, 0);
}
