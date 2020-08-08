/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 19:49:48 by rrayne            #+#    #+#             */
/*   Updated: 2019/09/27 17:47:13 by rrayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*p1;
	char	*p2;
	size_t	i;

	p1 = (char *)dest;
	p2 = (char *)src;
	if (p2 > p1)
	{
		i = 0;
		while (i < n)
		{
			p1[i] = p2[i];
			i++;
		}
	}
	else if (p1 > p2)
	{
		i = 1;
		while (i <= n)
		{
			p1[n - i] = p2[n - i];
			i++;
		}
	}
	return (p1);
}
