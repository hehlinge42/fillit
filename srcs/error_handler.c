/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:46:26 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/17 17:47:15 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <stdlib.h>

int		ft_print_usage(void)
{
	ft_putstr_err("usage: fillit  source_file\n");
	return (EXIT_FAILURE);
}

int		ft_error(void)
{
	ft_putstr("error\n");
	return (EXIT_FAILURE);
}
