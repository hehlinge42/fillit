/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:06:40 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/18 09:51:09 by hehlinge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_debug(char *str, int nb)
{
	ft_putstr(str);
	ft_putchar(' ');
	ft_putnbr(nb);
	ft_putchar('\n');
}

void	ft_print_bits(unsigned short int n)
{
	unsigned int	i;
	int				count;

	count = 0;
	i = (1 << 15);
	while (i > 0)
	{
		if (n & i)
			ft_putchar('1');
		else
			ft_putchar('0');
		if (count % 4 == 3)
			ft_putchar(' ');
		i /= 2;
		count++;
	}
	ft_putchar('\n');
}
