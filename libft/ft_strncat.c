/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:58:42 by rrayne            #+#    #+#             */
/*   Updated: 2019/09/27 20:11:01 by rrayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, const char *src, unsigned int n)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (dest[i] != '\0')
		i++;
	if (dest[i] == '\0')
	{
		while (src[k] != '\0' && n > 0)
		{
			dest[i + k] = src[k];
			k++;
			n--;
		}
	}
	dest[i + k] = '\0';
	return (dest);
}
