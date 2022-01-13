/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makelist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:39:12 by trlevequ          #+#    #+#             */
/*   Updated: 2018/11/23 16:08:13 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "fillit.h"

int		ft_create_list(int fd, t_tetri **list)
{
	if ((ft_recup(fd, list) == -1) || (ft_make_list3(*list) == -1))
	{
		write(1, "error\n", 6);
		return (-1);
	}
	return (1);
}

void	ft_make_list(t_tetri **list)
{
	int i;

	ft_make_list2(list);
	(*list)->xmin = 3;
	(*list)->ymin = 3;
	(*list)->xmax = 0;
	(*list)->ymax = 0;
	i = -1;
	while (++i < 4)
	{
		if ((*list)->x[i] < (*list)->xmin)
			(*list)->xmin = (*list)->x[i];
		if ((*list)->y[i] < (*list)->ymin)
			(*list)->ymin = (*list)->y[i];
		if ((*list)->x[i] > (*list)->xmax)
			(*list)->xmax = (*list)->x[i];
		if ((*list)->y[i] > (*list)->ymax)
			(*list)->ymax = (*list)->y[i];
	}
}

void	ft_make_list2(t_tetri **list)
{
	int i;
	int x0;
	int y0;

	x0 = (*list)->x[0];
	y0 = (*list)->y[0];
	i = -1;
	while (++i < 4)
	{
		(*list)->x[i] = (*list)->x[i] - x0;
		(*list)->y[i] = (*list)->y[i] - y0;
	}
}

int		ft_make_list3(t_tetri *list)
{
	char c;

	c = 'A';
	while (list != NULL && c <= 'Z')
	{
		list->letter = c;
		c++;
		list = list->next;
	}
	if (c > 'Z' + 1)
		return (-1);
	return (1);
}
