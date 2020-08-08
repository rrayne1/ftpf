/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:14:15 by rrayne            #+#    #+#             */
/*   Updated: 2019/09/28 14:29:28 by rrayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_clear(char const *s, char c, int i, char **mas)
{
	char *str;

	str = (char*)malloc(sizeof(char) * (ft_getword(s, c)));
	if (!str)
	{
		ft_cleararr(mas, i);
		return (NULL);
	}
	return (str);
}
