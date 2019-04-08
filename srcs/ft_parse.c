/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehlinge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:39:39 by hehlinge          #+#    #+#             */
/*   Updated: 2019/04/08 18:10:03 by hehlinge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/fillit.h"
#include "../libft/includes/libft.h"

void	ft_create_domino(int nb, t_list **begin_list, char domino[21])
{
	t_fillit	t_domino;
	int			i;
	int			j;
	t_list		*tmp;

	i = -1;
	ft_memset(&t_domino, 0, sizeof(t_fillit));
	t_domino.rank = nb;
	t_domino.letter = 'A' + nb;
	while (++i < 4)
	{
		ft_bzero(t_domino.parsed[i], 4);
		j = -1;
		while (++j < 4)
			t_domino.piece[i][j] = domino[i * 4 + j];
	}
	ft_fill_struct(&t_domino); // renseigne les champs parsed, length, width
	tmp = ft_lstnew(&t_domino, sizeof(t_domino));
	ft_lstadd(begin_list, tmp);
}

int		ft_neighbour(char domino[21], int i)
{
	int neighbours;

	neighbours = 0;
	if (i > 0 && domino[i - 1] == '#')
		neighbours++;
	if (i < 18 && domino[i + 1] == '#')
		neighbours++;
	if (i > 4 && domino[i - 5] == '#')
		neighbours++;
	if (i < 14 && domino[i + 5] == '#')
		neighbours++;
	return (neighbours);
}

int		ft_check_domino(char domino[21], t_list **begin_list)
{
	int				i;
	int				count;
	static int		nb = 0;

	i = -1;
	count = 0;
	while (++i < 20)
	{
		if (i % 5 == 4 && domino[i] != '\n')
		{	
			printf("if 1\n");
			return (EXIT_FAILURE);
		}
		if (i % 5 != 4 && domino[i] != '#' && domino[i] != '.')
		{	
			printf("if 2\n");
			return (EXIT_FAILURE);
		}
		if (domino[i] == '#')
		{
			if ((((i == 6 || i == 7 || i == 11 || i == 12) && ft_neighbour(domino, i) >= 1))
				|| ((i != 6 && i != 7 && i != 11 && i != 12) && ft_neighbour(domino, i) >= 1))
				count++;
			else
			{
				printf("if 3, i = %d, nb = %d\n", i, nb);
				return (EXIT_FAILURE);
			}
		}
	}
	if (count != 4 || nb > 25)
	{
		printf("if 4\n");
		return (EXIT_FAILURE);
	}
	ft_create_domino(nb, begin_list, domino);
	nb++;
	return (EXIT_SUCCESS);
}

int		ft_parse(int fd)
{
	char		buf[21];
	int			ret;
//	char		*line;
	t_list		*begin_list;

	begin_list = NULL;
	while ((ret = read(fd, buf, 20)) > 0)
	{
		buf[ret] = '\0';
		if (ft_check_domino(buf, &begin_list) == EXIT_FAILURE)
		{
			//ft_clear();
			return (EXIT_FAILURE);
		}
		//get_next_line(fd, &line);
//		if (!(*line == '\0'))
//		{
			//ft_clear();
//			return (EXIT_FAILURE);
//		}
		printf("buf %s\n", buf);
	}
	printf("ret = %d\n", ret);
	//ft_debog(&begin_list);
	return (EXIT_SUCCESS);
}
