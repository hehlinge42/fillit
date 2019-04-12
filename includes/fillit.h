/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehlinge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 09:40:03 by hehlinge          #+#    #+#             */
/*   Updated: 2019/04/12 13:21:27 by hehlinge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# define BUFF_SIZE 21
# define NB_TETRI_MAX 26
# define UP_SHIFT 0xF
# define LEFT_SHIFT 0x7000
# define CHECK_RIGHT 0
# define CHECK_DOWN 1

typedef struct	s_tetri
{
	short		tetri[16];
	int			x;
	int			y;
	int			height;
	int			width;
}				t_tetri;

int		ft_print_usage(void);
int		ft_error(void);
int		ft_parse(const int);
int		ft_create_domino(t_tetri *piece, char buff[BUFF_SIZE + 1]);
void	ft_print_board(t_list **begin_list);
void	ft_print_bits(unsigned int n);
int		ft_reverse_bits(unsigned int n);
void	ft_del_list(t_list **begin_list);
int		ft_check_domino(char *buff);
void	ft_shift(short tetri[16], int x, int y);
int		ft_nextsqrt(int nb);
void	ft_size_width(t_tetri *piece, char buff[BUFF_SIZE + 1]);
void	ft_size_height(t_tetri *piece, char buff[BUFF_SIZE + 1]);
int		ft_check_shift(t_tetri *piece, int x, int y);
int		ft_backtrack(t_tetri tab[NB_TETRI_MAX + 2], int nb_piece, int tetri, int size);
int		ft_check_insert(t_tetri *map, t_tetri tetr);

#endif
