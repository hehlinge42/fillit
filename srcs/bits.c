/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehlinge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 09:55:36 by hehlinge          #+#    #+#             */
/*   Updated: 2019/04/11 14:05:34 by hehlinge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/../includes/libft.h"

void	ft_print_bits(unsigned long long int n) 
{ 
	unsigned long long i; 
	int					count;

	count = 0;
	i = 9223372036854775808ULL;
	while (i > 0)
	{
		if (n & i)
			ft_putchar('1');
		else
			ft_putchar('0');
		if (count > 0 && count % 8 == 7)
			ft_putchar(' ');
		i /= 2;
		count++;
	}
}
