/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_dominos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehlinge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:46:45 by hehlinge          #+#    #+#             */
/*   Updated: 2019/04/08 18:10:07 by hehlinge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_fill_struct(t_fillit *t_domino)
{
	int	first_i;
	int	first_j;
	int	i;
	int	j;

	i = 0;
	first_i = 0;
	first_j = 0;
	ft_width(t_domino, &first_j);
	ft_length(t_domino, &first_i);
	while (i < t_domino->length)
	{
		j = 0;
		while (j < t_domino->width)
		{
			t_domino->parsed[i][j] = t_domino->piece[i + first_i][j + first_j];
			j++;
		}
		i++;
	}
}

void	ft_width(t_fillit *t_domino, int *first_j)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	while (i < 4)
	{
		j = 0;
		temp = 0;
		while (j < 4)
		{
			if (t_domino->piece[i][j] == '#')
				temp++;
			j++;
		}
		if (!temp && !t_domino->width)
			(*first_j)++;
		if (temp > t_domino->width)
			t_domino->width = temp;
		i++;
	}
}

void	ft_length(t_fillit *t_domino, int *first_i)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	while (i < 4)
	{
		j = 0;
		temp = 0;
		while (j < 4)
		{
			if (t_domino->piece[j][i] == '#')
				temp++;
			j++;
		}
		if (!temp && !t_domino->width)
			(*first_i)++;
		if (temp > t_domino->length)
			t_domino->length = temp;
		i++;
	}
}
