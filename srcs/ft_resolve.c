/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehlinge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:02:55 by hehlinge          #+#    #+#             */
/*   Updated: 2019/04/12 13:35:58 by hehlinge         ###   ########.fr       */
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
	else if (opt == CHECK_DOWN && piece->width + piece->x < size)
	{
		i = piece->width + 1;
		while (--i > 0)
			piece->tetri[piece->y + i + 1] = piece->tetri[piece->y + i];
		(piece->y)++;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int		ft_check_insert(t_tetri *map, t_tetri tetri)
{
	int		y;

	y = 0;
	while (y < 4)
	{
		if (tetri.tetri[y + tetri.y] & map->tetri[y + tetri.y])
			return (EXIT_FAILURE);
		y++;
	}
	y = 0;
	while (y < 4)
	{
		tetri.tetri[y + tetri.y] ^= map->tetri[y + tetri.y];
		y++;
	}
	return (EXIT_SUCCESS);
}

int		ft_backtrack(t_tetri tab[NB_TETRI_MAX + 2], int nb_piece, int tetri, int size)
{
	int		i;

	if (tetri == nb_piece)
		return (EXIT_SUCCESS);
	while (!ft_check_shift(&tab[tetri], CHECK_RIGHT, size))
	{
		while (!ft_check_shift(&tab[tetri], CHECK_DOWN, size))
		{
			if (ft_check_insert(&tab[nb_piece], tab[tetri]))
				ft_backtrack(tab, nb_piece, ++tetri, size);
		}
	}
	i = 0;
	while (i < nb_piece)
	{
		ft_shift(tab[i].tetri, tab[i].x, tab[i].y);
		tab[i].x = 0;
		tab[i].y = 0;
		i++;
	}
	ft_backtrack(tab, nb_piece, 0, ++size);
	return (EXIT_FAILURE);
}
