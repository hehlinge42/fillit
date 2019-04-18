/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehlinge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:28:08 by hehlinge          #+#    #+#             */
/*   Updated: 2019/04/18 14:37:08 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdlib.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		return (ft_print_usage());
	else if ((fd = open(av[1], O_RDONLY)) < 0)
		return (ft_error());
	else if (ft_parse(fd) == EXIT_FAILURE)
		return (ft_error());
	return (EXIT_SUCCESS);
}
