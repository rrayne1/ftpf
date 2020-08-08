/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:35:57 by rrayne            #+#    #+#             */
/*   Updated: 2019/09/28 19:14:17 by rrayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *stack, const char *needle, size_t len)
{
	unsigned int	poisk;
	unsigned int	i;

	if (*needle == '\0' || needle == NULL)
		return ((char *)stack);
	poisk = 0;
	while (stack[poisk] != '\0' && (size_t)poisk < len)
	{
		if (stack[poisk] == needle[0])
		{
			i = 1;
			while (stack[poisk + i] != '\0' && stack[poisk + i] == needle[i] \
					&& (size_t)(poisk + i) < len)
				i++;
			if (needle[i] == '\0')
				return ((char *)&stack[poisk]);
		}
		poisk++;
	}
	return (0);
}
