/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehlinge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:06:51 by hehlinge          #+#    #+#             */
/*   Updated: 2019/04/11 18:33:04 by hehlinge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdlib.h>

int		ft_map_realloc(unsigned long long tab[27])
{
	char	**map;
	int		i;
	int		size;

	i = -1;
	while (tab[++i])
		;
	size = ft_next_sqrt(i * 4);
	if (!(map = ft_init_map(0)))
		return (0);
	while (!(ft_backtrack(map, tab, 0)))
	{
		//free ta mere mouhaha
		if (!(map = ft_init_map(++size)))
			return (0);
	}
	return (1);
}

char	**ft_init_map(int size)
{
	char	**map;
	int		i;

	if (!(map = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	map[size] = 0;
	i = -1;
	while (++i < size)
		if (!(map[i] = ft_strnew(size)))
		{
			//ft_free_le_bordel()
			return (NULL);
		}
	return (map);
}

int		ft_backtrack(char **map, unsigned long long tab[27], int tetri)
{
	if (!tab[tetri])
		return (EXIT_SUCCESS);

	ft_print_bits(tab[0]);
	ft_putchar('\n');
	int tmp = tab[0] & GET_X;
	tmp++;
	tab[0] |= ~tmp;
	ft_print_bits(tab[0]);/*
	ft_putchar('\n');
	tab[0] |= (int)(tab[0] & GET_X) + 1;
	ft_print_bits(tab[0]);*/
	(void)map;
	/*
	   while (x + len <= size && y + width <= size)
	   {
	   if (ft_check_tetri())
	//on le met
	if (backtrack piece suivante == TRUE)
	return TRUE;
	else
	on l'enleve
	shift piece actuelle
	}
	return FALSE;*/
	return (1);
}
