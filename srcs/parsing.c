/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehlinge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:06:24 by hehlinge          #+#    #+#             */
/*   Updated: 2019/04/17 18:11:14 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/fillit.h"

int		ft_count_neighbours(char *buff, int index)
{
	int		count;

	count = 0;
	if (index + 1 < BUFF_SIZE && buff[index + 1] == '#')
		count++;
	if (index - 1 >= 0 && buff[index - 1] == '#')
		count++;
	if (index + 5 < BUFF_SIZE && buff[index + 5] == '#')
		count++;
	if (index - 5 >= 0 && buff[index - 5] == '#')
		count++;
	return (count);
}

int		ft_check_domino(char *buff)
{
	int		i;
	int		count_hash;
	int		count_neighbours;

	i = 0;
	count_hash = 0;
	count_neighbours = 0;
	while (i < BUFF_SIZE)
	{
		if (i % 5 == 4 && buff[i] != '\n')
			return (EXIT_FAILURE);
		else if (buff[i] != '#' && buff[i] != '.' && i % 5 != 4 && i != 20)
			return (EXIT_FAILURE);
		else if (buff[i] == '#')
		{
			count_hash++;
			count_neighbours += ft_count_neighbours(buff, i);
		}
		i++;
	}
	if (count_hash != 4 || count_neighbours < 6)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
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

int		ft_create_domino(t_tetri *piece, char buff[BUFF_SIZE + 1])
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (ft_check_domino(buff) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (++i < 4)
	{
		j = -1;
		while (++j < 5)
		{
			if (buff[i * 5 + j] == '#')
			{
				piece->tetri[i] <<= 1;
				piece->tetri[i] |= 1;
				if (j % 5 < piece->x)
					piece->x = j % 5;
			}
			else if (buff[i * 5 + j] == '.')
				piece->tetri[i] <<= 1;
		}
		if ((piece->tetri[i] | 0) == 0 && piece->x == 4)
			piece->y++;
		piece->tetri[i] <<= 12;
	}
	ft_shift(piece);
	ft_size_height(piece, buff);
	ft_size_width(piece, buff);
	return (EXIT_SUCCESS);
}

int		ft_parse(const int fd)
{
	t_tetri	tab[NB_TETRI_MAX + 2];
	char	buff[BUFF_SIZE + 1];
	int		ret;
	int		i;
	int		size;

	i = -1;
	while (++i < NB_TETRI_MAX)
		ft_init_struct(&(tab[i]));
	i = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0 && i < NB_TETRI_MAX)
	{
		buff[ret] = '\0';
		if (ft_create_domino(&(tab[i]), buff) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	if (ret < 0)
		return (EXIT_FAILURE);
	size = ft_check_size(tab, i);
	ft_bandaid(tab, i);
	while (ft_backtrack(tab, i, 0, size) == EXIT_FAILURE)
		ft_restart(tab, i, &size);
	ft_create_map(tab, size, i);
	return (EXIT_SUCCESS);
}
