/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:07:33 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/17 18:13:16 by edbaudou         ###   ########.fr       */
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

