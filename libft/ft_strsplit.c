/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:59:09 by rrayne            #+#    #+#             */
/*   Updated: 2019/09/28 14:41:34 by rrayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**mas;

	i = 0;
	if (!s || \
			!(mas = (char**)malloc(sizeof(char*) * (ft_countwords(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			if (!(mas[i] = ft_clear(s, c, i, mas)))
				return (NULL);
			j = 0;
			while (*s != c && *s)
				mas[i][j++] = *(s++);
			mas[i++][j] = '\0';
		}
	}
	mas[i] = NULL;
	return (mas);
}
