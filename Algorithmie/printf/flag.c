/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 19:15:13 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/12/21 20:02:57 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int			ft_atoi(const char *str, int *i)
{
	int		nb;
	int		sign;

	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		++(*i);
	nb = 0;
	sign = (str[*i] == '-' ? -1 : 1);
	*i = (str[*i] == '-' || str[*i] == '+' ? *i : *i - 1);
	while (str[++(*i)] >= '0' && str[*i] <= '9')
	{
		nb *= 10;
		nb += (str[*i] - '0') * sign;
	}
	return (nb);
}

void		init_flag(const char *format, int *pos, t_flag *flag)
{
	int		i;
	int		is_flag;
	char	known[] = "+- #0";
	int		*ptr_flag[] = {&flag->plus, &flag->minus, &flag->space,
							&flag->sharp, &flag->zero, &flag->width};

	i = -1;
	while (++i < 6)
		*(ptr_flag[i]) = 0;
	is_flag = 1;
	while (is_flag)
	{
		is_flag = 0;
		i = -1;
		while (known[++i] && !is_flag)
		{
			if (format[*pos] == known[i] && (is_flag = 1))
			{
				*(ptr_flag[i]) = 1;
				++(*pos);
			}
		}
	}
	if (format[*pos] > '0' && format[*pos] <= '9')
		flag->width = ft_atoi(format, pos);
}

int		flag_length(t_list *elem)
{
	int		count;
	int		len;
	long	n;

	count = 0;
	if (!elem->flag && elem->type != INTEGER && elem->type != U_INTEGER)
		return (0);
	len = ft_strlen(elem->base);
	if (elem->type == INTEGER)
		n = (int)(long int)(elem->content);
	else
		n = (unsigned int)(long int)(elem->content);
	if (elem->flag->space && n >= 0 && !elem->flag->plus)
		++count;
	if (n >= 0 && elem->flag->plus)
		++count;
	if (n != 0 && elem->flag->sharp)
	{
		if (len == 8)
			++count;
		else if (len == 16)
			count += 2;
	}
	return (count);
}

void		flag_spaces(t_list *elem, char *strout, int *pos)
{
	long	n;

	n = elem->len + elem->flag_len;
	while (n < elem->flag->width)
	{
		if (!elem->flag->zero || elem->flag->minus)
			strout[(*pos)++] = ' ';
		if (elem->flag->zero && !elem->flag->minus)
			strout[(*pos)++] = '0';
		++n;
	}
}

void		flag_aff(t_list *elem, char *strout, int pos)
{
	int		len;
	long	n;

	if (!elem->flag)
		return ;
	len = ft_strlen(elem->base);
	if (elem->type == INTEGER)
		n = (int)(long int)(elem->content);
	else
		n = (unsigned int)(long int)(elem->content);
	if (elem->flag->space && n >= 0 && !elem->flag->plus)
		strout[pos++] = ' ';
	if (n >= 0 && elem->flag->plus)
		strout[pos++] = '+';
	if (n != 0 && elem->flag->sharp)
	{
		if (len == 8 || len == 16)
			strout[pos++] = '0';
		if (len == 16 && elem->base[10] == 'a')
			strout[pos++] = 'x';
		else if (len == 16)
			strout[pos++] = 'X';
	}
}
