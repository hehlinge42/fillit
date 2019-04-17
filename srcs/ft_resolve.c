/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehlinge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:02:55 by hehlinge          #+#    #+#             */
/*   Updated: 2019/04/17 13:25:41 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_check_shift(t_tetri *piece, int opt, int size)
{
	int		i;

	if (opt == CHECK_RIGHT && piece->width + piece->x < size)
	{
		i = -1;
		while (++i < 4)
			piece->tetri[piece->y + i] >>= 1;
		(piece->x)++;
		return (EXIT_SUCCESS);
	}
	else if (opt == CHECK_DOWN && piece->height + piece->y < size)
	{			
		i = piece->height + 1;
		while (--i >= 0)
			piece->tetri[piece->y + i + 1] = piece->tetri[piece->y + i];
		i = piece->height + 1;
		while (--i >= 0)
			piece->tetri[piece->y + i + 1] <<= piece->x;
		piece->tetri[piece->y] = 0;
		piece->x = 0;
		(piece->y)++;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int		ft_check_insert(t_tetri *map, t_tetri tetri)
{
	int		y;

	y = 0;
	while (y < tetri.height)
	{
		if ((tetri.tetri[y + tetri.y] & map->tetri[y + tetri.y]))
			return (EXIT_FAILURE);
		y++;
	}
	y = 0;
	while (y < tetri.height)
	{
		map->tetri[y + tetri.y] ^= tetri.tetri[y + tetri.y];
		y++;
	}
	return (EXIT_SUCCESS);
}

int		ft_backtrack(t_tetri tab[NB_TETRI_MAX + 2], int nb_piece, int tetri, int size)
{
	if (tetri  == nb_piece)
		return (EXIT_SUCCESS);

	return (EXIT_FAILURE);
}
