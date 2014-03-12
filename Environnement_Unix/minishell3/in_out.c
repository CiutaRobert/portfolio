/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 10:00:39 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/02/09 01:56:16 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fcntl.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"ft_sh.h"

static char	*get_file_name(char *file, int end)
{
	int		i;
	int		j;
	char	*new_file;

	i = 0;
	while (file[i] && is_sep(file[i], "<> \t"))
		++i;
	if ((new_file = malloc(end - i + 1)) == NULL)
		return (NULL);
	new_file[end - i] = 0;
	j = 0;
	while (file[i] && !is_sep(file[i], "<> \t"))
		new_file[j++] = file[i++];
	return (new_file);
}

int			redir_output(char *file, int end)
{
	char	*new_file;
	int		out;
	int		is_otrunc;

	is_otrunc = (file[1] == '>' ? 0 : O_TRUNC);
	if ((new_file = get_file_name(file, end)) == NULL)
		return (ft_putstr_fd(2, "gabtoubl_sh: Error with malloc\n"));
	if ((out = open(new_file, O_WRONLY | is_otrunc
					| O_APPEND | O_CREAT, 0644)) == -1)
	{
		ft_putstr_fd(2, new_file);
		free(new_file);
		return (ft_putstr_fd(2, ": Permission denied\n"));
	}
	dup2(out, 1);
	close(out);
	free(new_file);
	return (0);
}

static int	redir_double_input(char *file)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		fdpipe[2];

	if (pipe(fdpipe) == -1)
		return (-1);
	buf[0] = 0;
	while (ft_strcmp(buf, file))
	{
		ft_putstr_fd(1, "toodamndufromage> ");
		if ((ret = read(0, buf, BUFF_SIZE)) < 0)
			return (ft_putstr_fd(2, "gabtoubl_sh: Error with read\n"));
		if (ret)
			buf[ret - 1] = 0;
		if (ft_strcmp(buf, file))
		{
			ft_putstr_fd(fdpipe[1], buf);
			ft_putstr_fd(fdpipe[1], "\n");
		}
	}
	close(fdpipe[1]);
	dup2(fdpipe[0], 0);
	close(fdpipe[0]);
	return (0);
}

int			redir_input(char *file, int end)
{
	char	*new_file;
	int		in;

	if ((new_file = get_file_name(file, end)) == NULL)
		return (ft_putstr_fd(2, "gabtoubl_sh: Error with malloc\n"));
	if (file[1] == '<')
		return (redir_double_input(new_file));
	if ((in = open(new_file, O_RDONLY)) == -1)
	{
		ft_putstr_fd(2, new_file);
		free(new_file);
		return (ft_putstr_fd(2, ": Permission denied\n"));
	}
	dup2(in, 0);
	close(in);
	free(new_file);
	return (0);
}
