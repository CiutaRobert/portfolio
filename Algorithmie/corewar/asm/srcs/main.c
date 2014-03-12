/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 19:17:32 by fflorens          #+#    #+#             */
/*   Updated: 2014/01/29 22:35:05 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fcntl.h>
#include	<unistd.h>
#include	<limits.h>
#include	<stdlib.h>
#include	<corewar_asm.h>

static char		*parsename(char *av)
{
	int			i;
	int			j;
	int			k;
	char		*name;

	i = ft_strlen(av);
	if ((i - 2) > 0 && (av[i - 1] != 's' || av[i - 2] != '.'))
		return (NULL);
	j = i;
	while (i && av[i] != '/')
		i--;
	while (j && av[j] != '.')
		j--;
	i = (av[i] == '/' ? i + 1 : i);
	name = (char *)malloc(j - i + 5);
	k = -1;
	while (i <= j)
		name[++k] = av[i++];
	name[k] = '.';
	name[k + 1] = 'c';
	name[k + 2] = 'o';
	name[k + 3] = 'r';
	name[k + 4] = '\0';
	return (name);
}

static int		read_all_dat_shit(t_all *all, char *file)
{
	int			fd;
	char		*buf;

	all->list = NULL;
	all->labl = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putstr_fd(2, "Error: cannot open ");
		ft_putstr_fd(2, file);
		ft_putstr_fd(2, "\n");
		return (EXIT_FAILURE);
	}
	buf = NULL;
	while (ft_gnl(fd, &buf))
		lst_pushback(&all->list, buf);
	close(fd);
	return (EXIT_SUCCESS);
}

static int		parse_header(t_all *all, int fd)
{
	int			i;

	all->header.magic = to_big_endian(COREWAR_EXEC_MAGIC, 4);
	i = -1;
	while (++i < CORRECTOCT(PROG_NAME_LENGTH))
		all->header.prog_name[i] = 0;
	i = -1;
	while (++i <= CORRECTOCT(COMMENT_LENGTH))
		all->header.comment[i] = 0;
	get_labels_and_size(all);
	write(fd, &all->header, sizeof(t_header));
	parse_code(all, fd);
	return (EXIT_SUCCESS);
}

int				main(int ac, char **av)
{
	int			fd;
	t_all		all;
	char		*name;

	if (ac != 2)
		return (ft_putstr_fd(2, "usage: ./asm mychamp.s\n"));
	if (!(name = parsename(av[1])))
		return (ft_putstr_fd(2, "asm: wrong file extension\n"));
	if (is_valid_file(av[1]) != EXIT_SUCCESS)
		return (ft_putstr_fd(2, "asm: error in input file, aborting.\n"));
	if (read_all_dat_shit(&all, av[1]) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if ((fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
		return (ft_putstr_fd(2, name));
	if (parse_header(&all, fd) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	close(fd);
	return (EXIT_SUCCESS);
}
