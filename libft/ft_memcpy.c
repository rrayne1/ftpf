/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:18:12 by rrayne            #+#    #+#             */
/*   Updated: 2019/09/27 17:44:43 by rrayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	i = 0;
	p1 = (unsigned char *)dest;
	p2 = (unsigned char *)src;
	if (p1 == 0 && p2 == 0)
		return (dest);
	while (i < n)
	{
		p1[i] = p2[i];
		i++;
	}
	return (dest);
}
