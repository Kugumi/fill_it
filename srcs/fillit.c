/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 13:32:35 by dstracke          #+#    #+#             */
/*   Updated: 2019/05/15 21:48:52 by dstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_letter(char *tmp, int j, char *c)
{
	*c = *c + 1;
	tmp[j + 4] = *c;
	tmp[j + 5] = '\0';
	return (tmp);
}

char	*ft_cup(char *buf, char *c)
{
	int		x;
	int		y;
	int		j;
	char	*tmp;

	y = 0;
	j = 0;
	tmp = ft_strnew(9);
	while (*buf && !(x = 0))
	{
		while (*buf && *buf != '\n')
		{
			if (*buf == '#')
			{
				tmp[j] = (x + 48);
				tmp[j + 4] = (y + 48);
				j++;
			}
			x++;
			buf++;
		}
		y++;
		buf++;
	}
	return (ft_letter(tmp, j, c));
}
