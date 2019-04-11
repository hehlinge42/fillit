/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehlinge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:51:22 by hehlinge          #+#    #+#             */
/*   Updated: 2019/04/10 22:26:20 by hehlinge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdlib.h>

int		ft_fill_table(t_list **begin_list)
{
	short int	table[27];
	t_list		*tmp;
	int			i;
	int			j;
	short int	*map;

	tmp = *begin_list;
	i = -1;
	while (++i < 27)
		table[i] = 0;
	i = 0;
	while (tmp)
	{
		table[i] = ((t_domino *)tmp->content)->piece;
		tmp = tmp->next;
		i++;
	}
	ft_print_map(table);
	if (!(map = (short int *)malloc(sizeof(short int) * 27)))
		return (EXIT_FAILURE);
	j = -1;
	while (++j < 27)
		map[j] = 0;
	ft_backtrack(i, map, table, ft_size_max(i));
	return (EXIT_SUCCESS);
}

int	ft_backtrack(int nb_dominos, short int *map, short int table[27], int size_max)
{
	
}
