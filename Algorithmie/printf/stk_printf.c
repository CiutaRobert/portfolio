/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 20:03:56 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/12/21 20:37:24 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static void	skip_flag(const char *strin, int *i)
{
	int		j;
	int		is_over;
	char	known[] = "+- #0123456789";

	is_over = 0;
	while (!is_over)
	{
		is_over = 1;
		j = -1;
		while (known[++j])
		{
			if (strin[*i] == known[j])
			{
				++(*i);
				is_over = 0;
			}
		}
	}
}

static int	stk_spec(char spec, t_list *tmp, char *strout, int pos)
{
	int		i;
	t_ptr	ptr[SPECDONE];

	get_ptrs(ptr);
	i = -1;
	while (++i < SPECDONE)
	{
		if (spec == ptr[i].letter)
		{
			if (!tmp->flag->minus)
				flag_spaces(tmp, strout, &pos);
			(ptr[i].func)(tmp, strout, pos);
			if (tmp->flag->minus)
			{
				pos += tmp->len + tmp->flag_len;
				flag_spaces(tmp, strout, &pos);
			}
			return (MAX((tmp->len + tmp->flag_len), (tmp->flag->width)));
		}
	}
	return (-1);
}

void		stk_printf(const char *strin, char *strout, t_list *list)
{
	int		i;
	int		pos;
	int		tmp_pos;
	t_list	*tmp;

	tmp = list;
	pos = 0;
	i = -1;
	while (strin[++i])
	{
		if (strin[i] == '%' && (++i))
		{
			skip_flag(strin, &i);
			if ((tmp_pos = stk_spec(strin[i], tmp, strout, pos)) != -1)
			{
				tmp = tmp->next;
				pos += tmp_pos;
			}
			else
				strout[pos++] = strin[i];
		}
		else
			strout[pos++] = strin[i];
	}
}
