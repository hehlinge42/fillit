/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 12:20:42 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/17 17:50:45 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_create_map(t_tetri tab[NB_TETRI_MAX + 2], int size, int nb_piece)
{
	char	map[size][size + 1];
	int		piece;
	int		mask;
	int		line;
	int		col;

	piece = -1;
	while (++piece < size)
	{
		ft_memset(&map[piece], '.', size);
		map[piece][size] = '\0';
	}
	piece = -1;
	while (++piece < nb_piece) // on itere dans les pieces
	{
		line = -1;
		while (++line < 4) // on itere dans les lignes de la piece
		{
			col = -1;
			mask = 1 << (15 - tab[piece].x);
			while (++col < 4) // on itere dans les colonnes de la piece
			{
				if (mask & tab[piece].tetri[tab[piece].y])
					map[tab[piece].y][tab[piece].x] = piece + 'A';
				mask >>= 1;
				tab[piece].x++;
				if (col == 3)
					tab[piece].x -= 4;
			}
			tab[piece].y++;
		}
		tab[piece].y -= 4;
	}
	ft_print_map(size, map);
}

void	ft_print_map(int size, char map[size][size + 1])
{
	int		count;

	count = -1;
	while (++count < size)
	{
		write(1, map[count], size);
		write(1, "\n", 1);
	}
}
