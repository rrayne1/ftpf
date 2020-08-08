/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 20:14:05 by rrayne            #+#    #+#             */
/*   Updated: 2020/02/15 20:14:12 by rrayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*check(char **pntr, char *stack)
{
	char *str;

	if ((*pntr = ft_strchr(stack, '\n')))
	{
		str = ft_strsub(stack, 0, *pntr - stack);
		ft_strcpy(stack, ++(*pntr));
	}
	else
	{
		str = ft_strnew(ft_strlen(stack) + 1);
		ft_strcat(str, stack);
		ft_strclr(stack);
	}
	return (str);
}

int		get_line(const int fd, char **line, char *stack)
{
	char		buf[BUFF_SIZE + 1];
	char		*pntr;
	char		*tmp;
	int			ret;

	pntr = NULL;
	ret = 1;
	*line = check(&pntr, stack);
	while (pntr == 0 && ((ret = read(fd, buf, BUFF_SIZE)) != 0))
	{
		buf[ret] = '\0';
		if ((pntr = ft_strchr(buf, '\n')) != NULL)
		{
			ft_strcpy(stack, ++pntr);
			ft_strclr(--pntr);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, buf)) || ret < 0)
			return (-1);
		ft_strdel(&tmp);
	}
	return ((ft_strlen(*line) || ft_strlen(stack) || ret) ? 1 : 0);
}

t_gnl	*new(const int fd)
{
	t_gnl	*lst;

	if (!(lst = (t_gnl *)ft_memalloc(sizeof(t_gnl))))
		return (NULL);
	lst->fd = fd;
	lst->stack = ft_strnew(BUFF_SIZE);
	lst->next = NULL;
	return (lst);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*head;
	t_gnl			*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	if (head == NULL)
		head = new(fd);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = new(fd);
		tmp = tmp->next;
	}
	return (get_line(tmp->fd, line, tmp->stack));
}
