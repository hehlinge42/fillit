#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# define BUFF_SIZE 21
# define LEFT_SHIFT 0x8888
# define RIGHT_SHIFT 0x1111
# define UP_SHIFT 0xF000
# define DOWN_SHIFT 0xF
# define GET_TETRI 0x20
# define GET_X 0xFF000000
# define GET_Y 0xFF0000
# define PLUS_PLUS_X 0x1000000

int		ft_print_usage(void);
int		ft_error(void);
int		ft_parse(const int);
int		ft_create_domino(char buff[BUFF_SIZE + 1], unsigned long long table[27], int rank);
void	ft_print_bits(unsigned long long n);
int		ft_check_domino(char *buff);
void	ft_size_len(unsigned long long *tetri, char buff[BUFF_SIZE + 1]);
void	ft_size_height(unsigned long long *tetri, char buff[BUFF_SIZE + 1]);
void	ft_shift_domino(unsigned long long *tetri);
int		ft_map_realloc(unsigned long long tabl[27]);
char	**ft_init_map(int size);
int		ft_backtrack(char **map, unsigned long long tab[27], int tetri);

#endif
