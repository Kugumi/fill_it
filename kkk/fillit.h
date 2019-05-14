/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:01:46 by jijerde           #+#    #+#             */
/*   Updated: 2019/05/14 18:05:36 by dstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <stdlib.h>

typedef	struct		s_tetr
{
	char			*fig;
	struct s_tetr	*next;
}					t_tetr;

char				*buf19(ssize_t ret, char *str, char *buf, char *c);
char				*ft_tet(int fd, char *buf);
int					bctr(char *map, t_tetr *tetr, size_t cmp_sd);
void				ft_remove(char *map, t_tetr *tetr, size_t i);
char				*solve(t_tetr *tetr, size_t cmp_sd);
int					paste(char *map, char *str, size_t cmp_sdm, size_t d);
void				mapper(size_t cmp_sd, char *map);
int					ft_connect_count(char *s, int i);
int					ft_check_backslash(int i, ssize_t ret);
int					ft_prov_kol(int i, int j, ssize_t ret, int t);
int					ft_validate(char *buf, ssize_t ret);
char				*ft_cuttetr(char *tmp);
char				*ft_cup(char *buf, char *c);
void				freetlist(t_tetr *tetr);
t_tetr				*tlist(char *str);
t_tetr				*firstlist(char *str);
size_t				ft_sqrt(char *str);

#endif
