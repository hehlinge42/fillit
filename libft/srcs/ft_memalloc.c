/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehlinge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:38:36 by hehlinge          #+#    #+#             */
/*   Updated: 2019/04/10 17:18:54 by hehlinge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*res;

	if (!(res = (char *)malloc(sizeof(char) * (size))))
		return (NULL);
	ft_bzero(res, size);
	return (res);
}
