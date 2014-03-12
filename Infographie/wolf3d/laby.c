/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   laby.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 14:26:07 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/01/17 10:17:55 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"wolf3d.h"

static char	get_laby_part1(int x, int y)
{
	char	laby[22][MAP_Y] = {
		"1111111111111111111111111111111111111111111111111111111111111111",
		"1111111000000000000000011111111000000000011111111111000000000111",
		"1111110000000000000000001111110000000000001111111110000000000011",
		"1111110000000000000000001111110000000000001111111110000000000011",
		"1111114444444444474440004444440004444440000000000000004444400011",
		"1111110004000444000440007000070004000040000000000000004000400011",
		"1111110004000444000440004444440004000040000000000000004000400011",
		"1111110007000000000444444444444444440044444444444444444444400011",
		"1111110004000000000400000000000000040004000000400000004000400011",
		"1111110004444400000400000000000000040007000000700000004000400011",
		"1111110004000444744422227222227220040004000000400000004000400011",
		"1111000004000400000020000002000020040004000000444474744000400011",
		"1110000004000400000070000007000070044044000000000400000000400011",
		"1110000004000400000020000002000020040004000000000400000000400011",
		"1110004444000444444422222222222220040004000000000400044444400011",
		"1110004000000000003400000000000000040004444444744400040000000011",
		"1110007000000000003400000000000000040004000040000000040000000011",
		"1110004003337333003474444444444444440004000040000000040000000111",
		"1100004003000003003400000000000400000004000040000000040001111111",
		"1000004333000003007700000000000700000004444440000040040001111111",
		"1000004003000003003444400000000400000004000040000040040001111111",
		"1000444003330333333333344444444444444444000040000040040001111111"};

	return (laby[x][y]);
}

static char	get_laby_part2(int x, int y)
{
	char	laby[22][MAP_Y] = {
		"1000433003000033000000034444444444444440000044404440040001111111",
		"1000430003000030000000034000000000000040000000000040040000000111",
		"1000430003000030000000034000000000000040000000000040040000000011",
		"1000430003000030000000340000444044000000000000000044440000000011",
		"1000430003000030000000000000444444000044444444444440044444400011",
		"1000433333000030030000034444444444444444444444444440000000400011",
		"1000444443337333333333333333000004444444000000000444444444400011",
		"1000000001100000000000000000000000000000000000000000000000000011",
		"1100000001100000000000000000000000000000000000000000000000000011",
		"1100000001100000000000000000044400000000044444444444444440000111",
		"1111111111000004444444444444440444444444455555555555555551111111",
		"1100000000000006666400040000040000000045500000000500000050000011",
		"1100000000000006006400070000070000000045000000000000000000000001",
		"1000000000000006006400040000040000000045000000000500000050000001",
		"1000666666666666006400040000040000444445000000000555555554440001",
		"1000600060000000006400044444440000422225000000000500005444440001",
		"1000600070000000006400040000000000420025555500000500005400000001",
		"1000600060000000006400040000000000770022222205555500005400000001",
		"1000600066666660606447440000000000420000000200000000005400000011",
		"1000600066666600006400040000000000420000000200000000005400011111",
		"1000600006666600006400044444440444420000000200000000005400011111",
		"1000600007778600006400000400000000422722222222222727272400000011"};

	return (laby[x - 22][y]);
}

static char	get_laby_part3(int x, int y)
{
	char	laby[16][MAP_Y] = {
		"1000600006666600006400000400000000000000000400020000002400000001",
		"1000600066666600006400000400000000000004000700020000002400000001",
		"1000600066666667676400000444444440000004000400020000002444440001",
		"1000666666000000006400000000000044444444000400022222002222240001",
		"1000000006000000006400000000000040000000000700000000000000240001",
		"1000000006666600006400000000000040000000000400000002222222240001",
		"1100000000000600006444474444444440000000000400444444444444440001",
		"1111110000000600006600000044444444444444447400444000000000040001",
		"1100011000000600000700000040000000000040000000400000000000040001",
		"1000001111000600000600000040000000000040000000400000000000040001",
		"1000000011000666666600000040000000000044444444400011111100040001",
		"1000001111000000000444444440001111100000000000000011000100000001",
		"1000001007000000000000000000001111100000000000000011000700000001",
		"1000000000100000000000000000001111110000000000000110000110000011",
		"1100000000111111000000000000011111111111111111111100000011111111",
		"1111111111111111111111111111111111111111111111111111111111111111"};

	return (laby[x - 44][y]);
}

void		get_laby(char mlxlaby[MAP_X][MAP_Y], int aff)
{
	int		x;
	int		y;

	x = -1;
	while (++x < MAP_X)
	{
		y = -1;
		while (++y < MAP_Y)
		{
			if (x < 22)
				mlxlaby[x][y] = (aff ? get_laby_part1(x, y) : 0);
			else if (x < 44)
				mlxlaby[x][y] = (aff ? get_laby_part2(x, y) : 0);
			else
				mlxlaby[x][y] = (aff ? get_laby_part3(x, y) : 0);
		}
	}
}
