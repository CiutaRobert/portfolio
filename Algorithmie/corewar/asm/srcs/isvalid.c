/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvalid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 22:23:34 by fflorens          #+#    #+#             */
/*   Updated: 2014/03/12 20:11:05 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fcntl.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<op.h>
#include	<corewar_asm.h>

static int		is_comment_or_cmd_line(char *str)
{
	if (!ft_strncmp(str, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
		return (1);
	else if (!ft_strncmp(str,
						COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
		return (1);
	else
		return (0);
}

static int		is_valid_char(char *str)
{
	int			i;
	int			k;
	int			j;

	i = -1;
	while (str[++i])
	{
		if ((str[i] == COMMENT_CHAR || str[i] == ';') && k)
			return (1);
		else if ((str[i] == COMMENT_CHAR || str[i] == ';') && !k)
			return (0);
		j = -1;
		k = 0;
		while (LABEL_CHARS[++j])
		{
			if (str[i] == LABEL_CHARS[j]
				|| str[i] == LABEL_CHAR || str[i] == DIRECT_CHAR
				|| str[i] == SEPARATOR_CHAR || str[i] == '\t'
				|| str[i] == ' ' || str[i] == '.')
				k++;
		}
		if (k == 0)
			return (0);
	}
	return (1);
}

int				is_valid_file(char *file)
{
	char		*line;
	int			fd;
	int			k;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (ft_putstr_fd(2, "asm: can't open input file.\n"));
	line = NULL;
	while (ft_gnl(fd, &line))
	{
		k = 0;
		if (is_comment_or_cmd_line(line))
			k = 1;
		else
			k = is_valid_char(line);
		free(line);
		if (k == 0)
		{
			close(fd);
			return (EXIT_FAILURE);
		}
	}
	close(fd);
	return (EXIT_SUCCESS);
}
