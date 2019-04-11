/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehlinge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:23:49 by hehlinge          #+#    #+#             */
/*   Updated: 2019/04/10 17:18:58 by hehlinge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if (!(res = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	res[i] = '\0';
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	return (res);
}
