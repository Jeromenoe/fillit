/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:14:49 by trlevequ          #+#    #+#             */
/*   Updated: 2018/11/23 16:38:56 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

char	**ft_create_tab(int len_tab)
{
	char	**tab;
	int		i;
	int		j;

	if (!(tab = (char **)malloc(sizeof(char *) * (len_tab + 1))))
		ft_exit();
	i = -1;
	while (++i < len_tab)
	{
		if (!(tab[i] = (char *)malloc(sizeof(char) * (len_tab + 1))))
			ft_exit();
		j = -1;
		while (++j < len_tab)
			tab[i][j] = '.';
		tab[i][j] = '\0';
	}
	tab[i] = NULL;
	return (tab);
}

int		ft_realloc_tab(char ***tab, int len_tab)
{
	int i;

	i = -1;
	while ((*tab)[++i])
		free((*tab)[i]);
	free(*tab);
	++len_tab;
	*tab = ft_create_tab(len_tab);
	return (len_tab);
}
