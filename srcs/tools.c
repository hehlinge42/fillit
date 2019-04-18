/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:07:33 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/18 10:02:05 by hehlinge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_init_struct(t_tetri *piece)
{
	int		i;

	i = -1;
	while (++i < 16)
		piece->tetri[i] = 0;
	piece->x = 4;
	piece->y = 0;
}

void	ft_bandaid(t_tetri tab[NB_TETRI_MAX + 2], int nb_piece)
{
	int		i;

	i = -1;
	while (++i < nb_piece)
		tab[i].x = -1;
}

void	ft_restart(t_tetri tab[NB_TETRI_MAX + 2], int nb, int *size)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		ft_shift(&tab[i]);
		i++;
	}
	ft_bzero(&tab[nb].tetri, 16);
	(*size)++;
	ft_bandaid(tab, nb);
}

void	ft_shift(t_tetri *piece)
{
	while ((piece->tetri[0] ^ UP_SHIFT) == UP_SHIFT)
	{
		piece->tetri[piece->y - 1] = piece->tetri[piece->y];
		piece->tetri[piece->y] = piece->tetri[piece->y + 1];
		piece->tetri[piece->y + 1] = piece->tetri[piece->y + 2];
		piece->tetri[piece->y + 2] = piece->tetri[piece->y + 3];
		piece->tetri[piece->y + 3] = 0;
		piece->y--;
	}
	while ((piece->tetri[piece->y] | LEFT_SHIFT) == LEFT_SHIFT
			&& (piece->tetri[piece->y + 1] | LEFT_SHIFT) == LEFT_SHIFT
			&& (piece->tetri[piece->y + 2] | LEFT_SHIFT) == LEFT_SHIFT
			&& (piece->tetri[piece->y + 3] | LEFT_SHIFT) == LEFT_SHIFT)
	{
		piece->tetri[piece->y] <<= 1;
		piece->tetri[piece->y + 1] <<= 1;
		piece->tetri[piece->y + 2] <<= 1;
		piece->tetri[piece->y + 3] <<= 1;
		piece->x--;
	}
}

void	ft_reset_for_back_track(t_tetri tab[NB_TETRI_MAX + 2], int tetri,
		int nb_piece, unsigned short tmp[16])
{
	int		i;

	i = -1;
	while (++i < 16)
		tab[nb_piece].tetri[i] = tmp[i];
	i = tetri;
	while (++i < nb_piece)
	{
		ft_shift(&tab[i]);
		tab[i].x = -1;
	}
}
