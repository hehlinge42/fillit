/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehlinge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:09:47 by hehlinge          #+#    #+#             */
/*   Updated: 2019/04/11 18:02:38 by hehlinge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/fillit.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_shift_domino(unsigned long long *tetri)
{
	while (!(*tetri & LEFT_SHIFT))
		*tetri <<= 1;
	while (!(*tetri & UP_SHIFT))
		*tetri <<= 4;
}

int		ft_check_domino(char *buff)
{
	int		i;

	i = 0;
	while (i < BUFF_SIZE)
	{
		if (i % 5 == 4 && buff[i] != '\n')
			return (EXIT_FAILURE);
		if (buff[i] != '#' && buff[i] != '.' && i % 5 != 4 && i != 20)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

void	ft_size_len(unsigned long long *tetri, char buff[BUFF_SIZE + 1])
{
	int		i;
	unsigned long long	empty_col;
	unsigned long long	len;

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
	len = 4 - empty_col;
	len <<= 52;
	*tetri |= len;
}

void	ft_size_height(unsigned long long *tetri, char buff[BUFF_SIZE + 1])
{
	int		i;
	unsigned long long	empty_row;
	unsigned long long	width;

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
	width = 4 - empty_row;
	width <<= 48;
	*tetri |= width;
}

int		ft_create_domino(char buff[BUFF_SIZE + 1], unsigned long long table[27], int rank)
{
	int					i;
	unsigned long long	tmp_tetri;

	i = -1;
	tmp_tetri = 0;
	if (ft_check_domino(buff) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	table[rank] = rank;
	table[rank] <<= 56;
	ft_size_len(&table[rank], buff);
	ft_size_height(&table[rank], buff);
	while (++i < BUFF_SIZE)
		if (buff[i] == '#')
		{	
			tmp_tetri <<= 1;
			tmp_tetri |= 1;
		}
		else if (buff[i] == '.')
			tmp_tetri <<= 1;
	ft_shift_domino(&tmp_tetri);
	tmp_tetri <<= 32;
	table[rank] |= tmp_tetri;
	return (EXIT_SUCCESS);
}

int		ft_parse(const int fd)
{
	char				buff[BUFF_SIZE + 1];
	unsigned long long	table[27];
	int					ret;
	int					i;

	i = -1;
	while (table[++i])
		table[i] = 0;
	i = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (ft_create_domino(buff, table, i) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	if (ret < 0)
		return (EXIT_FAILURE);
	if (!ft_map_realloc(table))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
