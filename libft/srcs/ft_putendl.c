/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:59:17 by jnoe              #+#    #+#             */
/*   Updated: 2018/11/19 18:18:38 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	int i;

	if (s != NULL)
	{
		i = 0;
		while (s[i] != '\0')
		{
			ft_putchar(s[i]);
			i++;
		}
		ft_putchar('\n');
	}
}