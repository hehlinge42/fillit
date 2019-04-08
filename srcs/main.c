/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehlinge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:28:08 by hehlinge          #+#    #+#             */
/*   Updated: 2019/04/08 18:10:10 by hehlinge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <fcntl.h>

void	ft_debog(t_list **begin_list)
{
	t_list *tmp;
	int		i = 0;
	int		j;

	tmp = *begin_list;
	while (tmp)
	{
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				ft_putchar(((t_fillit *)(tmp->content))->parsed[i][j]);
				j++;
			}
			i++;
		}
		ft_putchar('\n');
		tmp = tmp->next;
	}
}
#include <stdio.h>
int		main(int ac, char **av)
{
	int	fd;

    if (ac != 2)
	{
		//ft_print_usage();
		return (EXIT_FAILURE);
	}
	if ((fd = open(av[1], O_RDONLY)) < 0)
	{
		printf("fd pas ok\n");
		return (EXIT_FAILURE);
	}
	ft_parse(fd);
	return (EXIT_SUCCESS);
}
