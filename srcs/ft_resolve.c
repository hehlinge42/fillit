/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehlinge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:02:55 by hehlinge          #+#    #+#             */
/*   Updated: 2019/04/17 10:59:42 by hehlinge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_check_shift(t_tetri *piece, int opt, int size)
{
	int		i;

	int debog = -1;
	/*ft_putstr("piece avant right & down\n");
	  while (++debog < 16)
	  ft_print_bits(piece->tetri[debog]);*/
	if (opt == CHECK_RIGHT && piece->width + piece->x < size)
	{
		i = -1;
		while (++i < 4)
			piece->tetri[piece->y + i] >>= 1;
		(piece->x)++;

		/*debog = -1;
		  ft_putstr("piece apres RIGHT\n");
		  while (++debog < 16)
		  ft_print_bits(piece->tetri[debog]);*/

		return (EXIT_SUCCESS);
	}
	else if (opt == CHECK_DOWN && piece->height + piece->y < size)
	{			
		/*ft_putstr("piece down AVANT\n");
		  debog = -1;
		  while (++debog < 16)
		  ft_print_bits(piece->tetri[debog]);*/

		i = piece->height + 1;
		//ft_putstr("IIIIIIIIIII : \n");
		//ft_putnbr(i);
		//ft_putstr("\n YYYYYYYYYYY : \n");
		//ft_putnbr(piece->y);
		//ft_putstr("\n");
		while (--i >= 0)
		{
			piece->tetri[piece->y + i + 1] = piece->tetri[piece->y + i];
			debog = -1;
		}
		i = piece->height + 1;
		while (--i >= 0)
			piece->tetri[piece->y + i + 1] <<= piece->x;
		piece->tetri[piece->y] = 0;
		/*debog = -1;
		  ft_putstr("piece apres down\n");
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
			if (tetri.x == 0 && tetri.y == 2)
			{
				/*int debog = -1;
				ft_putstr("LOLOLOLOL\n");
				while (++debog < 16)
					ft_print_bits(tetri.tetri[debog]);
				ft_putstr("tetri\n");
				ft_print_bits(tetri.tetri[y + tetri.y]);
				ft_putstr("map\n");
				ft_print_bits(map->tetri[y + tetri.y]);
				ft_putstr("full map\n");
				debog = -1;
				while (++debog < 16)
					ft_print_bits(map->tetri[debog]);*/

			}
			ft_putstr("Insertion impossible. tetri.x = ");
			ft_putnbr(tetri.x);
			ft_putstr(", tetri.y = ");
			ft_putnbr(tetri.y);
			ft_putchar('\n');
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
	int debog = -1;
	ft_putstr("piece numero ");
	ft_putnbr(tetri + 1);
	ft_putchar('\n');
	while (++debog < 16)
	  ft_print_bits(tab[tetri].tetri[debog]);

	if (ft_check_insert(&tab[nb_piece], tab[tetri]) == EXIT_SUCCESS)
	{
		ft_putstr("piece inseree, nb piece = ");
		ft_putnbr(tetri + 1);
		ft_putstr(" size de la map = ");
		ft_putnbr(size);
		ft_putchar('\n');
		ft_create_map(tab, size, tetri + 1);

		if (ft_backtrack(tab, nb_piece, ++tetri, size) == EXIT_SUCCESS)
			return (EXIT_SUCCESS);
	}
	else
	{
		while (ft_check_shift(&tab[tetri], CHECK_RIGHT, size) == EXIT_SUCCESS)
			if (ft_backtrack(tab, nb_piece, tetri, size) == EXIT_SUCCESS)
				return (EXIT_SUCCESS);
		ft_putstr("passe a shift down, piece = ");
		ft_putnbr(tetri + 1);
		ft_putchar('\n');
		while (ft_check_shift(&tab[tetri], CHECK_DOWN, size) == EXIT_SUCCESS)
			if (ft_backtrack(tab, nb_piece, tetri, size) == EXIT_SUCCESS)
				return (EXIT_SUCCESS);
	}
	/*ft_putstr("retirer la piece ");
	ft_putnbr(tetri);
	ft_putstr("\n");
	ft_create_map(tab, size, tetri);
	ft_putchar('\n');
	int		i = -1;
	while (++i < tab[tetri - 1].height)
		tab[nb_piece].tetri[tab[tetri - 1].y + i] &= ~tab[tetri - 1].tetri[tab[tetri - 1].y + i];
	ft_create_map(tab, size, tetri);*/
		return (EXIT_FAILURE);
}
