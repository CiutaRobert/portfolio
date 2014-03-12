/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 19:23:03 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/12/21 19:29:47 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void		stk_char(t_list *elem, char *strout, int pos)
{
	strout[pos] = (int)(long int)(elem->content);
}

void		stk_addr(t_list *elem, char *strout, int pos)
{
	strout[pos] = '0';
	strout[pos + 1] = 'x';
	stk_addrnbr((unsigned long)(elem->content), elem->base,
				strout, pos + elem->len - 1);
}

void		stk_str(t_list *elem, char *strout, int pos)
{
	int		i;
	char	*str;

	str = (char *)(elem->content);
	i = -1;
	while (str[++i])
		strout[pos + i] = str[i];
}

void		stk_strsp(t_list *elem, char *strout, int pos)
{
	int		i;
	char	*str;

	str = (char *)(elem->content);
	i = -1;
	while (str[++i])
	{
		if (str[i] < ' ' || str[i] > 126)
		{
			strout[pos + i] = '\\';
			if (str[i] < 64)
				strout[pos + i + 1] = '0';
			if (str[i] < 8)
				strout[pos + i + 2] = '0';
			stk_nbr(str[i], "01234567", strout, pos + i + 3);
			pos += 3;
		}
		else
			strout[pos + i] = str[i];
	}
}
