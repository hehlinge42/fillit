/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 12:20:42 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/19 10:18:10 by hehlinge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <unistd.h>

static void	ft_add_tetri(t_tetri tab[NB_TETRI_MAX + 2], int piece,
	char map[MAX_SIZE][MAX_SIZE + 1])
{
	int		line;
	int		col;
	int		mask;

	line = -1;
	while (++line < 4)
	{
		col = -1;
		mask = 1 << (15 - tab[piece].x);
		while (++col < 4)
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

static void	ft_print_map(int size, char map[MAX_SIZE][MAX_SIZE + 1])
{
	int		count;

	count = -1;
	while (++count < size)
	{
		write(1, map[count], size);
		write(1, "\n", 1);
	}
}

void		ft_create_map(t_tetri tab[NB_TETRI_MAX + 2], int size, int nb_piece)
{
	char	map[MAX_SIZE][MAX_SIZE + 1];
	int		piece;

	piece = -1;
	while (++piece < MAX_SIZE)
		ft_bzero(map[piece], MAX_SIZE);
	piece = -1;
	while (++piece < size)
	{
		ft_memset(&map[piece], '.', size);
		map[piece][size] = '\0';
	}
	piece = -1;
	while (++piece < nb_piece)
		ft_add_tetri(tab, piece, map);
	ft_print_map(size, map);
}
