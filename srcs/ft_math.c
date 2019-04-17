/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehlinge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:32:47 by hehlinge          #+#    #+#             */
/*   Updated: 2019/04/17 17:36:26 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			ft_check_size(t_tetri tab[NB_TETRI_MAX + 2], int nb_tetri)
{
	int		size;
	int		i;

	size = ft_nextsqrt(nb_tetri * 4);
	if (size >= 4)
		return (size);
	i = -1;
	while (++i < nb_tetri && size < 4)
	{
		if (tab[i].width > size)
			size = tab[i].width;
		if (tab[i].height > size)
			size = tab[i].height;
	}
	return (size);
}

static int	ft_sqrt(int nb)
{
	int i;

	i = 1;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		else
			i++;
	}
	return (0);
}

int		ft_nextsqrt(int nb)
{
	int res;

	while (!(res = ft_sqrt(nb)))
		nb++;
	return (res);
}

void	ft_size_width(t_tetri *piece, char buff[BUFF_SIZE + 1])
{
	int		i;
	int		empty_col;

	i = 0;
	empty_col = 0;
	while (i < 5)
	{
		while (i < BUFF_SIZE - 1 && buff[i] == '.')
			i += 5;
		if (i >= 20)
			empty_col++;
		i = i % 5 + 1;
	}
	piece->width = 4 - empty_col;
}

void	ft_size_height(t_tetri *piece, char buff[BUFF_SIZE + 1])
{
	int		i;
	int		empty_row;

	empty_row = 0;
	i = 0;
	while (buff[i])
	{
		while (buff[i] != '\n' && buff[i] == '.')
			i++;
		if (i % 5 == 4)
			empty_row++;
		i = (i / 5) * 5 + 5;
	}
	piece->height = 4 - empty_row;
}
