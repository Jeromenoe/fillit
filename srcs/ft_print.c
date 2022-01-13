/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:01:00 by trlevequ          #+#    #+#             */
/*   Updated: 2018/11/26 17:53:00 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "fillit.h"

void	ft_free_lst(t_tetri *tetri)
{
	t_tetri *tmp;

	while (tetri)
	{
		tmp = tetri;
		tetri = tetri->next;
		free(tmp);
	}
}

void	ft_exit(void)
{
	write(2, "Impossible to allocate memory.\n", 31);
	exit(84);
}

void	ft_print_tab(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
	{
		write(1, tab[i], ft_strlen(tab[i]));
		write(1, "\n", 1);
		free(tab[i]);
	}
	free(tab);
}
