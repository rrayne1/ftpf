/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:03:15 by rrayne            #+#    #+#             */
/*   Updated: 2019/09/27 17:46:24 by rrayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*point;
	size_t			i;

	i = 0;
	point = (unsigned char *)s;
	while (i < n)
	{
		point[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
