/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehlinge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 09:40:03 by hehlinge          #+#    #+#             */
/*   Updated: 2019/04/12 09:46:34 by hehlinge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# define BUFF_SIZE 21
# define NB_TETRI_MAX 26
# define LEFT_SHIFT 0x8888
# define UP_SHIFT 0xF000

typedef struct	s_tetri
{
	short		tetri[4];
	int			x;
	int			y;
}				t_tetri;

int		ft_print_usage(void);
int		ft_error(void);
int		ft_parse(const int);
int		ft_create_domino(t_list **begin_list, char buff[BUFF_SIZE + 1]);
void	ft_print_board(t_list **begin_list);
void	ft_print_bits(unsigned int n);
int		ft_reverse_bits(unsigned int n);
void	ft_del_list(t_list **begin_list);
int		ft_check_domino(char *buff);
void	ft_shift(int *tetri);

#endif
