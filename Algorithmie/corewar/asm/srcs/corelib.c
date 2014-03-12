/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corelib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 16:00:17 by fflorens          #+#    #+#             */
/*   Updated: 2014/01/29 19:35:31 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		to_big_endian(unsigned int nb, int size)
{
	int				i;
	unsigned int	new_nb;

	i = 0;
	size = (size - 1) * 8;
	new_nb = 0;
	while (i <= size)
	{
		new_nb |= ((nb >> (size - i) & 0xFF)) << i;
		i += 8;
	}
	return (new_nb);
}

int					ft_atoi(const char *s)
{
	int				sign;
	int				out;

	out = 0;
	sign = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		sign = ((*s == '+') ? 1 : -1);
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		out = out * 10 + (*s - '0');
		s++;
	}
	return (out * sign);
}

int					skipspacetabs(int i, char *str)
{
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	return (i);
}

int					skipnospacetabs(int i, char *str)
{
	while (str[i] && !(str[i] == ' ' || str[i] == '\t'))
		i++;
	return (i);
}

int					skiptoend(char *line, int i)
{
	while (line[i])
		i++;
	return (i);
}
