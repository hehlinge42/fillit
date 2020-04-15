/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:46:26 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/18 14:24:04 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <unistd.h>
#include <stdlib.h>

static void		ft_putstr_err(const char *str)
{
	if (!str)
		return ;
	write(2, str, ft_strlen(str));
}

int				ft_print_usage(void)
{
	ft_putstr_err("usage: fillit  source_file\n");
	return (EXIT_FAILURE);
}

int				ft_error(void)
{
	ft_putstr("error\n");
	return (EXIT_FAILURE);
}
