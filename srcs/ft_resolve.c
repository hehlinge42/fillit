/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehlinge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:02:55 by hehlinge          #+#    #+#             */
/*   Updated: 2019/04/17 18:33:02 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_check_shift(t_tetri *piece, int opt, int size)
{
	int		i;

	if (piece->x == -1)
	{
		piece->x = 0;
		return (EXIT_SUCCESS);
	}
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

int		ft_backtrack(t_tetri tab[NB_TETRI_MAX + 2], int nb_piece,
		int tetri, int size)
{
	int				i;
	unsigned short	tmp[16];

	if (tetri  == nb_piece)
		return (EXIT_SUCCESS);
	i = -1;
	while (++i < 16)
		tmp[i] = tab[nb_piece].tetri[i];
	while (ft_check_shift(&tab[tetri], CHECK_RIGHT, size) == EXIT_SUCCESS
		|| ft_check_shift(&tab[tetri], CHECK_DOWN, size) == EXIT_SUCCESS)
	{
		if (ft_check_insert(&tab[nb_piece], tab[tetri]) == EXIT_SUCCESS)
		{
			if (ft_backtrack(tab, nb_piece, tetri + 1, size) == EXIT_SUCCESS)
				return (EXIT_SUCCESS);
			ft_reset_for_back_track(tab, tetri, nb_piece, tmp);
		}
	}
	return (EXIT_FAILURE);
}
