/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:16:58 by rrayne            #+#    #+#             */
/*   Updated: 2019/09/27 20:05:28 by rrayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *stack, const char *needle)
{
	int	poisk;
	int	i;

	poisk = 0;
	if (!*needle)
		return ((char *)stack);
	while (stack[poisk != '\0'])
	{
		if (stack[poisk] == needle[0])
		{
			i = 1;
			while (needle[i] && stack[poisk + i] == needle[i])
				i++;
			if (needle[i] == '\0')
				return ((char *)&stack[poisk]);
		}
		stack++;
	}
	return (0);
}
