/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 00:36:43 by jijerde           #+#    #+#             */
/*   Updated: 2019/04/29 22:57:18 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetr	*firstlist(char *str)
{
	int		i;
	t_tetr	*tetr;
	char	tmp[10];

	i = 0;
	tetr = (t_tetr *)malloc(sizeof(t_tetr));
	tetr->next = NULL;
	tetr->fig = (char *)malloc(sizeof(char) * 10);
	tmp[9] = '\0';
	while (i < 9)
	{
		tmp[i] = str[i];
		i++;
	}
	tetr->fig = ft_strcpy(tetr->fig, tmp);
	return (tetr);
}

t_tetr	*tlist(char *str)
{
	int		i;
	int		str_i;
	char	tmp[10];
	t_tetr	*tetr;
	t_tetr	*nachalo;

	str_i = 9;
	tetr = firstlist(str);
	nachalo = tetr;
	tmp[9] = '\0';
	while (str[str_i] && !(i = 0))
	{
		tetr->next = (t_tetr *)malloc(sizeof(t_tetr));
		tetr = tetr->next;
		tetr->fig = (char *)malloc(sizeof(char) * 10);
		while (i < 9)
			tmp[i++] = str[str_i++];
		tetr->fig = ft_strcpy(tetr->fig, tmp);
	}
	tetr->next = NULL;
	return (nachalo);
}

void	freetlist(t_tetr *tetr)
{
	t_tetr *buf;

	while (tetr)
	{
		buf = tetr->next;
		free(tetr->fig);
		free(tetr);
		tetr = buf;
	}
}
