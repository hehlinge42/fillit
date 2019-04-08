#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/includes/libft.h"

typedef struct		s_fillit
{
	int			length;
	int			width;
	int			rank;
	char		piece[4][4];
	char		parsed[4][4];
	char		letter;
}					t_fillit;

int		ft_parse(int fd);
int		ft_check_domino(char domino[21], t_list **begin_list);
int		ft_neighbour(char domino[21], int i);
void	ft_create_domino(int nb, t_list **begin_list, char domino[21]);
void	ft_fill_struct(t_fillit *t_domino);
void	ft_width(t_fillit *domino, int *first_j);
void	ft_length(t_fillit *domino, int *first_i);
void	ft_debog(t_list **begin_list);

#endif
