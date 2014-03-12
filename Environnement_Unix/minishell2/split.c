/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 09:43:18 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/01/26 09:43:35 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

int			is_sep(char c, char *sep)
{
	int		i;

	i = -1;
	while (sep[++i])
	{
		if (c == sep[i])
			return (1);
	}
	return (0);
}

static int	count_words(char *buf, char *sep)
{
	int		i;
	int		words;

	if (!buf)
		return (-1);
	words = 0;
	i = 0;
	while (buf[i])
	{
		while (buf[i] && is_sep(buf[i], sep))
			++i;
		if (buf[i])
			++words;
		while (buf[i] && !is_sep(buf[i], sep))
			++i;
		if (buf[i])
			++i;
	}
	return (words);
}

static int	count_letters(char *buf, char *sep)
{
	int		i;

	i = 0;
	while (buf[i] && !is_sep(buf[i], sep))
		++i;
	return (i);
}

char		**ft_strsplit(char *buf, char *sep)
{
	int		i;
	int		j;
	int		pos;
	int		words;
	char	**tab;

	words = count_words(buf, sep);
	if ((tab = malloc(sizeof(char *) * (words + 1))) == NULL)
		return (NULL);
	tab[words] = NULL;
	i = -1;
	pos = 0;
	while (++i < words)
	{
		while (buf[pos] && is_sep(buf[pos], sep))
			++pos;
		if ((tab[i] = malloc(count_letters(buf + pos, sep) + 1)) == NULL)
			return (NULL);
		j = 0;
		while (buf[pos] && !is_sep(buf[pos], sep))
			tab[i][j++] = buf[pos++];
		tab[i][j] = 0;
	}
	return (tab);
}
