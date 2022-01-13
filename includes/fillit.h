/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:43:29 by trlevequ          #+#    #+#             */
/*   Updated: 2018/11/26 17:46:54 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define ABS(x) (x < 0) ? -x : x

# include "../libft/includes/libft.h"

typedef struct		s_tetri
{
	char			letter;
	int				x[4];
	int				y[4];
	int				xmin;
	int				ymin;
	int				xmax;
	int				ymax;
	struct s_tetri	*next;
}					t_tetri;

typedef struct		s_coor
{
	int				x;
	int				y;
}					t_coor;

void				ft_free_lst(t_tetri *tetri);
char				**ft_create_tab(int len_tab);
int					ft_realloc_tab(char ***tab, int len_tab);
void				ft_exit(void);
int					ft_create_list(int fd, t_tetri **list);
void				ft_print_list(t_tetri *list);
void				ft_print_tab(char **tab);
int					ft_recup(int fd, t_tetri **list);
int					ft_check_file1(int fd, char **str, t_tetri **list);
int					ft_check_file2(char **str, t_tetri **list);
int					ft_check_file3(t_tetri **list);
void				ft_make_list(t_tetri **list);
void				ft_make_list2(t_tetri **list);
int					ft_make_list3(t_tetri *list);

#endif
