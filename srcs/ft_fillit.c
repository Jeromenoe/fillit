/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:24:51 by trlevequ          #+#    #+#             */
/*   Updated: 2018/11/26 17:47:46 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "fillit.h"

int		ft_nb_tetriminos(t_tetri *tetri)
{
	int	len;
	int	i;

	len = 0;
	while (tetri != NULL)
	{
		++len;
		tetri = tetri->next;
	}
	i = 0;
	while (i * i < len * 4)
		i++;
	return (i);
}

int		ft_dispo_place(char **tab, t_tetri *tetri, t_coor coor, int len_tab)
{
	int k;
	int x;
	int y;

	x = coor.x;
	y = coor.y;
	if (tab[y][x] != '.')
		return (0);
	if ((x + tetri->xmax >= len_tab) || (x + tetri->xmin < 0) \
			|| (y + tetri->ymax >= len_tab))
		return (0);
	k = 0;
	while (++k < 4)
		if (tab[y + tetri->y[k]][x + tetri->x[k]] != '.')
			return (0);
	k = -1;
	while (++k < 4)
		tab[y + tetri->y[k]][x + tetri->x[k]] = tetri->letter;
	return (1);
}

void	ft_del_tetriminos(char **tab, t_tetri *tetri, t_coor coor)
{
	int k;
	int x;
	int y;

	x = coor.x;
	y = coor.y;
	k = -1;
	while (++k < 4)
		tab[y + tetri->y[k]][x + tetri->x[k]] = '.';
}

int		ft_fillit(char ***tab, t_tetri *tetri, int len_tab)
{
	t_coor coor;

	if (!tetri)
		return (1);
	coor.y = -1;
	while (++(coor.y) < len_tab)
	{
		coor.x = -1;
		while (++(coor.x) < len_tab)
		{
			if (ft_dispo_place(*tab, tetri, coor, len_tab))
			{
				if (ft_fillit(tab, tetri->next, len_tab))
					return (1);
				ft_del_tetriminos(*tab, tetri, coor);
			}
		}
	}
	if (tetri->letter == 'A')
	{
		len_tab = ft_realloc_tab(tab, len_tab);
		ft_fillit(tab, tetri, len_tab);
	}
	return (0);
}

int		main(int ac, char **av)
{
	char	**tab;
	t_tetri	*tetri;
	int		fd;
	int		len_tab;

	if (ac != 2)
	{
		ft_putstr(av[0]);
		ft_putstr(" input file\n");
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putstr("error\n");
		return (0);
	}
	if (ft_create_list(fd, &tetri) == -1)
		return (0);
	len_tab = ft_nb_tetriminos(tetri);
	tab = ft_create_tab(len_tab);
	ft_fillit(&tab, tetri, len_tab);
	ft_print_tab(tab);
	ft_free_lst(tetri);
	return (0);
}
