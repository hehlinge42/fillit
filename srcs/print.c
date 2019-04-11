/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehlinge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:28:36 by hehlinge          #+#    #+#             */
/*   Updated: 2019/04/10 22:26:28 by hehlinge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/fillit.h"

void	ft_print_map2(short  *map)
{
	int			i;
	int			j;
	short int	tmp_domino;

	j = 0;
	while (j < 9)
	{
		i = 1;
		while (i <= 16)
		{
			tmp_domino = 32768 >> (i - 1) ;
			if (tmp_domino & *map)
				ft_putchar('A' + j);
			else
				ft_putchar('.');
			i++;
		}
		ft_putchar('\n');
		j++;
		map += 2;
	}
}

void	ft_print_map(short int map[26])
{
	int			i;
	int			j;
	short int	tmp_domino;

	j = 0;
	while (map[j])
	{
		i = 1;
		while (i <= 16)
		{
			tmp_domino = 32768 >> (i - 1) ;
			if (tmp_domino & map[j])
				ft_putchar('A' + j);
			else
				ft_putchar('.');
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}

void	ft_print_board(t_list **begin_list)
{
	t_list		*tmp;
	t_domino	*v_domino;
	short int	tmp_domino;
	int			i;

	tmp = *begin_list;
	while (tmp)
	{
		v_domino = ((t_domino *)tmp->content);
		if (!v_domino)
			break ;
		i = 1;
		while (i <= 16)
		{
			tmp_domino = 32768 >> (i - 1) ;
			if (tmp_domino & v_domino->piece)
				ft_putchar(v_domino->rank);
			else
				ft_putchar('.');
			i++;
		}
		tmp = tmp->next;
		ft_putchar('\n');
	}
}

void	ft_del_list(t_list **begin_list)
{
	t_list		*tmp;
	t_domino	*del;
	t_list		*tmp2;

	tmp = *begin_list;
	while (tmp)
	{
		del = ((t_domino *)tmp->content);
		if (!del)
			return ;
		ft_memdel(&del);
		tmp2 = tmp->next;
		if (!tmp2)
			return ;
		ft_memdel(&tmp);
		tmp = tmp2;
	}
}
