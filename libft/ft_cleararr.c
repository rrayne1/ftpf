/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clearsplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 19:39:17 by rrayne            #+#    #+#             */
/*   Updated: 2019/09/28 14:28:18 by rrayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_cleararr(char **mas, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(mas[i]);
		i++;
	}
	free(mas);
}
