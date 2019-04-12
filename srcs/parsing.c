#include "../libft/includes/libft.h"
#include "../includes/fillit.h"

int		ft_check_domino(char *buff)
{
	int		i;

	i = 0;
	while (i < BUFF_SIZE)
	{
		if (i % 5 == 4 && buff[i] != '\n')
			return (EXIT_FAILURE);
		if (buff[i] != '#' && buff[i] != '.' && i % 5 != 4 && i != 20)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

void	ft_shift(short tetri[16], int x, int y)
{
	while ((tetri[y] ^ UP_SHIFT) == UP_SHIFT)
	{
		tetri[y] = tetri[y + 1];
		tetri[y + 1] = tetri[y + 2];
		tetri[y + 2] = tetri[y + 3];
		tetri[y + 3] = 0;
	}
	while (((tetri[x] | LEFT_SHIFT) == LEFT_SHIFT)
		&& ((tetri[x + 1] | LEFT_SHIFT) == LEFT_SHIFT)
		&& ((tetri[x + 2] | LEFT_SHIFT) == LEFT_SHIFT)
		&& ((tetri[x + 3] | LEFT_SHIFT) == LEFT_SHIFT))
	{
		tetri[x] <<= 1;
		tetri[x + 1] <<= 1;
		tetri[x + 2] <<= 1;
		tetri[x + 3] <<= 1;
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
			}
			else if (buff[i * 5 + j] == '.')
				piece->tetri[i] <<= 1;
		}
		piece->tetri[i] <<= 12;
	}
	ft_shift(piece->tetri, 0, 0);
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
	piece->x = 0;
	piece->y = 0;
}

int		ft_parse(const int fd)
{
	t_tetri	tab[NB_TETRI_MAX + 2];
	char	buff[BUFF_SIZE + 1];
	int		ret;
	int		i;

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
	int	debog = i;
	if (ft_backtrack(tab, i, 0, ft_nextsqrt(i * 4)) == EXIT_SUCCESS)
	{
		printf("IT Works, its amazing and we are the best!\n");
		i = -1;
		while (++i < 10)
			ft_print_bits(tab[debog].tetri[i]);
	}
	else
		printf("fuck yourself\n");
	return (EXIT_SUCCESS);
}
