/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehlinge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 09:40:03 by hehlinge          #+#    #+#             */
/*   Updated: 2019/04/18 11:11:50 by hehlinge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# define BUFF_SIZE 21
# define NB_TETRI_MAX 26
# define UP_SHIFT 0xFFFF
# define LEFT_SHIFT 0x7FFF
# define CHECK_RIGHT 0
# define CHECK_DOWN 1

typedef struct	s_tetri
{
	unsigned short	tetri[16];
	int				x;
	int				y;
	int				height;
	int				width;
}				t_tetri;

int		ft_print_usage(void);
int		ft_error(void);
int		ft_parse(const int);
void	ft_print_bits(unsigned short int n);
void	ft_shift(t_tetri *piece);
void	ft_size_width(t_tetri *piece, char buff[BUFF_SIZE + 1]);
void	ft_size_height(t_tetri *piece, char buff[BUFF_SIZE + 1]);
int		ft_check_shift(t_tetri *piece, int x, int y);
int		ft_backtrack(t_tetri tab[NB_TETRI_MAX + 2], int nb_piece, int tetri, int size);
void	ft_restart(t_tetri tab[NB_TETRI_MAX + 2], int nb, int *size);
void	ft_create_map(t_tetri tab[NB_TETRI_MAX + 2], int size, int nb_piece);
void	ft_debug(char *str, int nb);
int		ft_check_size(t_tetri tab[NB_TETRI_MAX + 2], int nb_tetri);
void	ft_init_struct(t_tetri *piece);
void	ft_bandaid(t_tetri tab[NB_TETRI_MAX + 2], int nb_piece);
void	ft_reset_for_back_track(t_tetri tab[NB_TETRI_MAX + 2], int tetri, int nb_piece,
		unsigned short tmp[16]);

#endif
