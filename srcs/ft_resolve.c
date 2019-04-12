/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehlinge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:02:55 by hehlinge          #+#    #+#             */
/*   Updated: 2019/04/12 17:12:44 by hehlinge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_check_shift(t_tetri *piece, int opt, int size)
{
	int		i;

	int debog = -1;
	/*ft_putstr("piece avant\n");
	  while (++debog < 16)
	  ft_print_bits(piece->tetri[debog]);*/
	if (opt == CHECK_RIGHT && piece->width + piece->x <= size)
	{
		i = -1;
		while (++i < 4)
			piece->tetri[piece->y + i] >>= 1;
		(piece->x)++;

		debog = -1;
		ft_putstr("piece avant\n");
		while (++debog < 16)
			ft_print_bits(piece->tetri[debog]);

		return (EXIT_SUCCESS);
	}
	else if (opt == CHECK_DOWN && piece->height + piece->y <= size)
	{
		i = piece->width + 1;
		while (--i >= 0)
		{
			ft_putstr("Check down\n");
			/*debog = -1;
			ft_putstr("piece au debut\n");
			while (++debog < 16)
				ft_print_bits(piece->tetri[debog]);*/

			piece->tetri[piece->y + i + 1] = piece->tetri[piece->y + i];
			/*debog = -1;
			ft_putstr("piece down\n");
			while (++debog < 16)
				ft_print_bits(piece->tetri[debog]);
			debog = -1;
			ft_putstr("piece left\n");
			while (++debog < 16)
				ft_print_bits(piece->tetri[debog]);*/

		}
		i = piece->width + 1;
		while (--i >= 0)
			piece->tetri[piece->y + i + 1] <<= piece->x;
		piece->tetri[piece->y] = 0;
		debog = -1;
		/*ft_putstr("piece finale\n");
		while (++debog < 16)
			ft_print_bits(piece->tetri[debog]);*/
		//piece->tetri[piece->y + i] <<= piece->x;
		piece->x = 0;
		(piece->y)++;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int		ft_check_insert(t_tetri *map, t_tetri tetri)
{
	int		y;

	y = 0;/*
			 int debog = -1;
			 ft_putstr("map \n");
			 while (++debog < 16)
			 ft_print_bits(map->tetri[debog]);
			 debog = -1;
			 ft_putstr("piece \n");
			 while (++debog < 16)
			 ft_print_bits(tetri.tetri[debog]);*/

	while (y < tetri.height)
	{
		/*ft_putstr("map \n");
		  ft_print_bits(map->tetri[y + tetri.y]);
		  ft_putstr("piece \n");
		  ft_print_bits(tetri.tetri[y + tetri.y]);*/
		if ((tetri.tetri[y + tetri.y] & map->tetri[y + tetri.y]))
		{
			ft_putstr("je me barre\n");
			return (EXIT_FAILURE);
		}
		y++;
	}

	//int debog = -1;
	//ft_putstr("map \n");
	/*while (++debog < 16)
	  ft_print_bits(map->tetri[debog]);
	  debog = -1;*/
	/*ft_putstr("piece \n");
	  while (++debog < 16)
	  ft_print_bits(tetri.tetri[debog]);*/

	y = 0;
	while (y < tetri.height)
	{
		map->tetri[y + tetri.y] ^= tetri.tetri[y + tetri.y];
		y++;
	}
	return (EXIT_SUCCESS);
}

int		ft_backtrack(t_tetri tab[NB_TETRI_MAX + 2], int nb_piece, int tetri, int size)
{
	//int		i;
	//
	/*ft_putchar('\n');
	  ft_putnbr(nb_piece);
	  ft_putnbr(tetri);
	  ft_putchar('\n');*/
	if (tetri  == nb_piece)
		return (EXIT_SUCCESS);
	if (ft_check_insert(&tab[nb_piece], tab[tetri]) == EXIT_SUCCESS)
	{
		/*ft_putstr("piece inserree\n");
		  int debog = -1;
		  ft_putstr("map \n");
		  while (++debog < 16)
		  ft_print_bits(tab[nb_piece].tetri[debog]);*/

		if (ft_backtrack(tab, nb_piece, ++tetri, size) == EXIT_SUCCESS)
			return (EXIT_SUCCESS);
	}
	else
	{
		while (ft_check_shift(&tab[tetri], CHECK_RIGHT, size) == EXIT_SUCCESS)
				if (ft_backtrack(tab, nb_piece, tetri, size) == EXIT_SUCCESS)
					return (EXIT_SUCCESS);
		ft_putstr("you shall not pass\n");
		while (ft_check_shift(&tab[tetri], CHECK_DOWN, size) == EXIT_SUCCESS)
			if (ft_backtrack(tab, nb_piece, tetri, size) == EXIT_SUCCESS)
				return (EXIT_SUCCESS);
	}

	/*i = 0;
	  while (i < nb_piece)
	  {
	  ft_shift(tab[i].tetri, tab[i].x, tab[i].y);
	  tab[i].x = 0;
	  tab[i].y = 0;
	  i++;
	  }
	  ft_backtrack(tab, nb_piece, 0, ++size);*/
	return (EXIT_FAILURE);
}
