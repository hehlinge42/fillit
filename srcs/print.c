/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 12:20:42 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/15 19:41:11 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_create_map(t_tetri tab[NB_TETRI_MAX + 2], int size, int nb_piece)
{
	char	map[size * size + 1];
	int		mask;

	map[size * size] = '\0';
	ft_memset(&map, '.', size * size);

	ft_print_map(size, map);
}

void	ft_print_map(int size, char map[size * size + 1])
{
	int		count;

	count = 0;
	while (count < size * size)
	{
		write(1, map + count, size);
		write(1, "\n", 1);
		count += size;
	}
}
