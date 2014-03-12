/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 19:19:38 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/12/21 19:29:07 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void		stk_nbr(long int nb, char *base, char *strout, int pos)
{
	int		len;

	len = ft_strlen(base);
	if (nb / len)
		stk_nbr(nb / len, base, strout, pos - 1);
	if (nb < 0 && nb > -len)
		strout[pos - 1] = '-';
	nb %= len;
	if (nb < 0)
		nb *= -1;
	strout[pos] = base[nb];
}

void		stk_addrnbr(unsigned long nb, char *base, char *strout, int pos)
{
	int		len;

	len = ft_strlen(base);
	if (nb / len)
		stk_addrnbr(nb / len, base, strout, pos - 1);
	strout[pos] = base[nb % len];
}

void		stk_int(t_list *elem, char *strout, int pos)
{
	flag_aff(elem, strout, pos);
	stk_nbr((int)(long int)(elem->content), elem->base,
			strout, pos + elem->len - 1 + elem->flag_len);
}

void		stk_uint(t_list *elem, char *strout, int pos)
{
	flag_aff(elem, strout, pos);
	stk_nbr((unsigned int)(long int)(elem->content), elem->base,
			strout, pos + elem->len - 1 + elem->flag_len);
}
