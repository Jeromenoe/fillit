/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:48:21 by trlevequ          #+#    #+#             */
/*   Updated: 2018/11/23 16:02:07 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "fillit.h"

void	ft_tab_alloc(char ***str)
{
	int i;

	if (!(*str = (char **)malloc(sizeof(*str) * 4)))
		ft_exit();
	i = -1;
	while (++i < 4)
	{
		if (!((*str)[i] = (char *)malloc(sizeof(char) * 6)))
			ft_exit();
		bzero((*str)[i], 6);
	}
}

int		ft_recup(int fd, t_tetri **list)
{
	int		check;
	char	**str;
	int		i;

	ft_tab_alloc(&str);
	if (!(*list = (t_tetri *)malloc(sizeof(**list))))
		ft_exit();
	check = ft_check_file1(fd, str, list);
	i = -1;
	while (++i < 4)
		free(str[i]);
	free(str);
	if (check == -1)
		return (-1);
	if (check == 0)
	{
		(*list)->next = NULL;
		return (0);
	}
	return (ft_recup(fd, &((*list)->next)));
}

int		ft_check_file1(int fd, char **str, t_tetri **list)
{
	int		i;
	int		j;
	int		res;
	char	c;

	i = -1;
	while (++i < 4)
		read(fd, str[i], 5);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (str[i][j] != '.' && str[i][j] != '#')
				return (-1);
		if (str[i][j] != '\n')
			return (-1);
	}
	if ((res = read(fd, &c, 1)) == -1 || ft_check_file2(str, list) == -1)
		return (-1);
	if (!res)
		return (0);
	if (c == '\n')
		return (1);
	return (-1);
}

int		ft_check_file2(char **str, t_tetri **list)
{
	int i;
	int j;
	int c;

	c = -1;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (str[i][j] == '#')
			{
				c++;
				if (c == 4)
					return (-1);
				(*list)->x[c] = j;
				(*list)->y[c] = i;
			}
		}
	}
	if (c != 3)
		return (-1);
	return (ft_check_file3(list));
}

int		ft_check_file3(t_tetri **list)
{
	int absx;
	int absy;
	int i;
	int j;
	int c;

	i = -1;
	c = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			absx = ABS(((*list)->x[i] - (*list)->x[j]));
			absy = ABS(((*list)->y[i] - (*list)->y[j]));
			if (absx + absy == 1)
				c++;
		}
	}
	if (c < 6)
		return (-1);
	ft_make_list(list);
	return (1);
}
