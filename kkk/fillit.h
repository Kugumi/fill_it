/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:01:46 by jijerde           #+#    #+#             */
/*   Updated: 2019/04/29 22:51:51 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"
#include <stdlib.h>

# define BUFF_SIZE 21

typedef struct	s_tetr
{
	char *fig;
 	struct	s_tetr *next;
	struct s_tetr *prev;
} t_tetr
;

char    *ft_tet(char *str, int fd, int ret, char *buf);
char    *bctr(char *map, t_tetr *tetr, int cmp_sd, int i);
void    ft_remove(char **map, t_tetr *tetr);
char    *solve(char *str, t_tetr *tetr, int cmp_sd);
int     ft_sqrt(char *str);
int     paste(char **map, char *str, int cmp_sd, int ik);
char    *mapper(int cmp_sd, char **map);
int     ft_connect_count(char *s, int i);
int     ft_check_backslash(char *s, int i, int ret);
int     ft_prov_kol(int i, int j, int ret, int t);
int     ft_validate(char *buf, int ret);
char    *ft_cuttetr(char *tmp);
char    *ft_cup(char *buf, char *c);
t_tetr *tlist(char *str);
t_tetr *firstlist(char *str);

#endif
