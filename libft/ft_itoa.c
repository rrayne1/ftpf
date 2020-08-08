/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:19:38 by rrayne            #+#    #+#             */
/*   Updated: 2019/09/27 20:20:52 by rrayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int				len;
	char			*num;
	int				i;
	unsigned int	nb;

	((n > 0) ? (nb = (unsigned int)n) :\
	(nb = (unsigned int)(-n)));
	len = ft_getlen(n);
	i = len - 1;
	if (!(num = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	if (n < 0)
		num[0] = '-';
	if (n == 0)
		num[0] = '0';
	while (nb != 0)
	{
		num[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	num[len] = 0;
	return (num);
}
