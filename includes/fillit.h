/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehlinge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 09:40:03 by hehlinge          #+#    #+#             */
/*   Updated: 2019/04/18 14:33:35 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# define BUFF_SIZE 21
# define NB_TETRI_MAX 26
# define UP_SHIFT 0xFFFF
# define LEFT_SHIFT 0x7FFF

typedef struct	s_tetri
{
	unsigned short	tetri[16];
	int				x;
	int				y;
	int				height;
	int				width;
}				t_tetri;

int				ft_print_usage(void);
int				ft_error(void);
int				ft_parse(const int fd);
void			ft_print_bits(unsigned short int n);
void			ft_shift(t_tetri *piece);
void			ft_size_width(t_tetri *piece, char buff[BUFF_SIZE + 1]);
void			ft_size_height(t_tetri *piece, char buff[BUFF_SIZE + 1]);
int				ft_check_shift(t_tetri *piece, int x, int y);
int				ft_backtrack(t_tetri tab[NB_TETRI_MAX + 2], int nb_piece,
				int tetri, int size);
void			ft_restart(t_tetri tab[NB_TETRI_MAX + 2], int nb, int *size);
void			ft_create_map(t_tetri tab[NB_TETRI_MAX + 2], int size,
				int nb_piece);
int				ft_check_size(t_tetri tab[NB_TETRI_MAX + 2], int nb_tetri);
void			ft_init_struct(t_tetri *piece);
void			ft_bandaid(t_tetri tab[NB_TETRI_MAX + 2], int nb_piece);
void			ft_reset_for_back_track(t_tetri tab[NB_TETRI_MAX + 2],
				int tetri, int nb_piece, unsigned short tmp[16]);
size_t			ft_strlen(const char *str);
void			ft_putstr(const char *str);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *b, size_t len);

#endif
