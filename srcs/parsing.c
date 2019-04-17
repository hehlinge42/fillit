/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehlinge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:06:24 by hehlinge          #+#    #+#             */
/*   Updated: 2019/04/17 17:01:52 by edbaudou         ###   ########.fr       */
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

void	ft_shift(t_tetri *piece, int opt)
{
	/*int debog = -1;
	ft_putstr("PIECE AVANT SHIFT \n");
	while (++debog < 16)
		ft_print_bits(piece->tetri[debog]);*/
	while ((piece->tetri[0] ^ UP_SHIFT) == UP_SHIFT)
	{
		//ft_putstr("AVANT SHIFT UP\n");
		
		/*ft_putstr("x = ");
		ft_putnbr(piece->x);
		ft_putchar('\n');
		ft_putstr("y = ");
		ft_putnbr(piece->y);
		ft_putchar('\n');
		ft_putchar('\n');*/

		/*debog = -1;
		while (++debog < 16)
			ft_print_bits(piece->tetri[debog]);*/

		piece->tetri[piece->y - 1] = piece->tetri[piece->y];
		piece->tetri[piece->y] = piece->tetri[piece->y + 1];
		piece->tetri[piece->y + 1] = piece->tetri[piece->y + 2];
		piece->tetri[piece->y + 2] = piece->tetri[piece->y + 3];
		piece->tetri[piece->y + 3] = 0;
		if (opt == 1)
			piece->y--;
	}
	while ((piece->tetri[piece->y] | LEFT_SHIFT) == LEFT_SHIFT
			&& (piece->tetri[piece->y + 1] | LEFT_SHIFT) == LEFT_SHIFT
			&& (piece->tetri[piece->y + 2] | LEFT_SHIFT) == LEFT_SHIFT
			&& (piece->tetri[piece->y + 3] | LEFT_SHIFT) == LEFT_SHIFT)
	{
		//debog = -1;
		/*ft_putstr("AVANT SHIFT LEFT\n");
		ft_putnbr(piece->x);
		ft_putchar('\n');
		ft_putnbr(piece->y);
		ft_putchar('\n');*/
		/*while (++debog < 16)
			ft_print_bits(piece->tetri[debog]);*/
		piece->tetri[piece->y] <<= 1;
		piece->tetri[piece->y + 1] <<= 1;
		piece->tetri[piece->y + 2] <<= 1;
		piece->tetri[piece->y + 3] <<= 1;
		if (opt == 1)
			piece->x--;
		//ft_putstr("inf 2\n");
	}
	/*debog = -1;
	ft_putstr("PIECE APRES SHIFT \n");
	while (++debog < 16)
		ft_print_bits(piece->tetri[debog]);*/

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
	/*ft_putstr("x = ");
	ft_putnbr(piece->x);
	ft_putchar('\n');
	ft_putstr("y = ");
	ft_putnbr(piece->y);
	ft_putchar('\n');
	ft_putchar('\n');*/
	ft_shift(piece, 1);
	/*ft_putstr("x = ");
	ft_putnbr(piece->x);
	ft_putchar('\n');
	ft_putstr("y = ");
	ft_putnbr(piece->y);
	ft_putchar('\n');
	ft_putchar('\n');*/
	ft_size_height(piece, buff);
	ft_size_width(piece, buff);
	i = -1;/*
			  while (++i < 4)
			  ft_print_bits(piece->tetri[i]);*/
	return (EXIT_SUCCESS);
}

void	ft_init_struct(t_tetri *piece)
{
	int		i;

	i = -1;
	while (++i < 16)
		piece->tetri[i] = 0;
	piece->x = 4;
	//piece->x = 0;
	piece->y = 0;
}

void	ft_bandaid(t_tetri tab[NB_TETRI_MAX + 2], int nb_piece)
{
	int		i;

	i = -1;
	while (++i < nb_piece)
		tab[i].x = -1;
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
	size = ft_nextsqrt(i * 4);
	/*ft_putstr("size = ");
	ft_putnbr(size);
	ft_putchar('\n');*/
	ft_bandaid(tab, i);
	while (ft_backtrack(tab, i, 0, size) == EXIT_FAILURE)
	{
		ft_restart(tab, i, 1);
		size++;
		ft_putstr("resize\n");
	}		
	/*ft_putstr("IT Works, its amazing and we are the best!\n");
	int	debog = -1;
	while (++debog < 16)
		ft_print_bits(tab[i].tetri[debog]);
	ft_putchar('\n');*/
	ft_create_map(tab, size, i);
	return (EXIT_SUCCESS);
}

void	ft_restart(t_tetri tab[NB_TETRI_MAX + 2], int nb, int opt)
{
	int		i;

	i = 0;
	//ft_putstr("in restart\n");
	while (i < nb)
	{
		if (opt == 1)
			ft_shift(&tab[i], 1);
		else
			ft_shift(&tab[i], 0);
		i++;
	}
	if (opt == 1)
	{
		//int debog = -1;
		/*ft_putstr("avant full 0\n");
		while (++debog < 16)
			ft_print_bits(tab[nb].tetri[debog]);*/
		ft_bzero(&tab[nb].tetri, 16);
		/*ft_putstr("apres full 0\n");
		debog = -1;
		while (++debog < 16)
			ft_print_bits(tab[nb].tetri[debog]);*/
	}
}
