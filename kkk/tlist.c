/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 00:36:43 by jijerde           #+#    #+#             */
/*   Updated: 2019/04/16 02:40:42 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

t_tetr *firstlist(char *str)
{
	int i;
	t_tetr *tetr;
	char tmp[10];

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

t_tetr *tlist(char *str)
{
	int i;
	int str_i;
	t_tetr *tetr;
	t_tetr *nachalo;
	char tmp[10];

	str_i = 9;
	tetr = firstlist(str);
	nachalo = tetr;
	tmp[9] = '\0';
	while (str[str_i] && !(i = 0))
	{
		tetr->next = (t_tetr *)malloc(sizeof(t_tetr));
		tetr=tetr->next;
		tetr->fig = (char *)malloc(sizeof(char) * 10);
		while (i < 9)
			tmp[i++] = str[str_i++];
		tetr->fig = ft_strcpy(tetr->fig, tmp);
	}
	tetr->next = NULL;
	return (nachalo);
}
int main()
{
	t_tetr *priv;
	int i = 3;
	char str[] = "12345678A12345678B12345678C";
	priv = tlist(str);
	while (i)
	{
		printf("%s\n", priv->fig);
		priv=priv->next;
		i--;
	}
	//printf("%s\n", priv->fig);
}
