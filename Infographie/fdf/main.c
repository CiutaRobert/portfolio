/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 21:45:27 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/12/21 18:28:30 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<mlx.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	"proto.h"

static int	get_key(int keycode, t_mlx *mlx)
{
	(void)mlx;
	if (keycode == 65307)
		exit(EXIT_SUCCESS);
	return (0);
}

static int	get_expose(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	return (0);
}

char		*ft_perror(const char *str)
{
	perror(str);
	return (NULL);
}

char		*parse_arg(int ac, char **av)
{
	int		fd;
	int		ret;
	char	buf[BUFSIZE];
	char	*totalbuf;

	totalbuf = NULL;
	if (ac != 2)
	{
		ft_putstr("usage : ./fdf file1\n");
		return (NULL);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (ft_perror("fdf"));
	while ((ret = read(fd, buf, BUFSIZE)) > 0)
	{
		buf[ret] = 0;
		totalbuf = ft_strjoin(totalbuf, buf);
	}
	if (ret == -1 || close(fd) == -1)
		return (ft_perror("fdf"));
	if (!totalbuf)
		ft_putstr("fdf: Empty map\n");
	return (totalbuf);
}

int			main(int ac, char **av)
{
	t_mlx	mlx;
	char	*totalbuf;

	if ((totalbuf = parse_arg(ac, av)) == NULL)
		return (1);
	if ((mlx.ptr = mlx_init()) == NULL)
		return (ft_putstr("fdf: mlx_init fail to work\n"));
	if ((mlx.img = mlx_new_image(mlx.ptr, WIN_X, WIN_Y)) == NULL)
		return (ft_putstr("fdf: mlx_new_image fail to work\n"));
	mlx.data = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.sline, &mlx.endian);
	get_map(&mlx, totalbuf);
	if ((mlx.win = mlx_new_window(mlx.ptr, WIN_X, WIN_Y, "FDF")) == NULL)
		return (ft_putstr("fdf: mlx_new_window fail to work\n"));
	aff_fdf(&mlx);
	mlx_key_hook(mlx.win, &get_key, &mlx);
	mlx_expose_hook(mlx.win, &get_expose, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
