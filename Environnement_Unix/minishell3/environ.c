/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 09:42:02 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/02/09 03:31:28 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"ft_sh.h"

char		*ft_strcpy(char *src, char *dest)
{
	int		i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	return (dest);
}

char		**copy_env(char **envp, char *line, int pos, int flag)
{
	int		i;
	int		word;
	int		letter;
	char	**new_env;

	if (!(word = 0) && !envp)
		return (NULL);
	while (envp[word])
		++word;
	word += (line == NULL ? 0 : 1);
	if ((new_env = malloc(sizeof(char *) * (word + 1))) == NULL)
		return (NULL);
	new_env[word] = NULL;
	i = -1;
	while (++i < word)
	{
		letter = (i == pos ? ft_strlen(line) : ft_strlen(envp[i + flag]));
		if ((new_env[i] = malloc(sizeof(char) * (letter + 1))) == NULL)
			return (NULL);
		if (i == pos && !flag && (flag = -1))
			new_env[i] = ft_strcpy(line, new_env[i]);
		else
			new_env[i] = ft_strcpy(envp[i + flag], new_env[i]);
	}
	return (new_env);
}

void		delete_one_from_env(char ***envp, int pos)
{
	int		i;
	int		move;

	i = -1;
	move = 0;
	while ((*envp)[++i])
	{
		if (i == pos)
			move = 1;
		if (move)
			(*envp)[i] = (*envp)[i + 1];
	}
}

void		free_env(char **envp)
{
	int		word;
	char	*tmp;

	word = 0;
	while (envp[word])
	{
		tmp = envp[word];
		++word;
		free(tmp);
	}
	free(envp);
}
