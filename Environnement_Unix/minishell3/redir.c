/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 09:42:54 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/01/26 11:12:40 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"ft_sh.h"

static char	*get_new_cmd(char *cmd, char *cmdref, int start, int end)
{
	int		i;
	int		j;
	char	*new_cmd;

	if ((new_cmd = malloc(ft_strlen(cmd) - (end - start) + 1)) == NULL)
		return (NULL);
	i = -1;
	while (cmd[++i] && !is_sep(cmd[i], "<>"))
		new_cmd[i] = cmd[i];
	j = i + end - start;
	while (cmd[j])
		new_cmd[i++] = cmd[j++];
	new_cmd[i] = 0;
	if (cmd != cmdref)
		free(cmd);
	return (new_cmd);
}

static void	skip_word(char *cmd, int *i)
{
	while (cmd[*i] && is_sep(cmd[*i], "<> \t"))
		++(*i);
	while (cmd[*i] && !is_sep(cmd[*i], "<> \t"))
		++(*i);
}

char		*check_redir(char *cmd)
{
	int		i;
	int		start;
	int		end;
	char	*new_cmd;

	new_cmd = cmd;
	start = -1;
	end = -1;
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '>' || cmd[i] == '<')
		{
			start = i;
			skip_word(cmd, &i);
			end = i;
			if ((cmd[start] == '>' && redir_output(cmd + start, end - start))
				|| (cmd[start] == '<' && redir_input(cmd + start, end - start))
				|| !(new_cmd = get_new_cmd(new_cmd, cmd, start, end)))
				return (NULL);
		}
		if (cmd[i])
			++i;
	}
	return (new_cmd);
}
