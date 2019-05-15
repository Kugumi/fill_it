/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 13:32:35 by dstracke          #+#    #+#             */
/*   Updated: 2019/05/14 18:11:02 by dstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_connect_count(char *s, int i)
{
	int		counter;

	counter = 0;
	if ((i + 1 < 21) && (s[i] == s[i + 1]))
		counter++;
	if ((i + 5 < 21) && (s[i] == s[i + 5]))
		counter++;
	if ((i - 1 > -1) && (s[i] == s[i - 1]))
		counter++;
	if ((i - 5 > -1) && (s[i] == s[i - 5]))
		counter++;
	return (counter);
}

int		ft_check_backslash(int i, ssize_t ret)
{
	if (ret == 20)
	{
		if (i == 4 || i == 9 || i == 14 || i == 19)
			return (1);
		else
			return (0);
	}
	else if (ret == 21)
	{
		if (i == 4 || i == 9 || i == 14 || i == 19 || i == 20)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

int		ft_prov_kol(int i, int j, ssize_t ret, int t)
{
	if (ret == 21 && (i == 6 || i == 8) && j == 5 && t == 4)
		return (1);
	else if (ret == 20 && (i == 6 || i == 8) && j == 4 && t == 4)
		return (1);
	else
		return (0);
}

int		ft_validate(char *buf, ssize_t ret)
{
	int		y;
	int		i;
	int		j;
	int		t;

	t = 0;
	y = 0;
	i = 0;
	j = 0;
	while (buf[y])
	{
		if (buf[y] == '#')
		{
			i = i + ft_connect_count(buf, y);
			t++;
		}
		else if (buf[y] == '\n')
			j = j + ft_check_backslash(y, ret);
		y++;
	}
	return (ft_prov_kol(i, j, ret, t));
}

char	*ft_cup(char *buf, char *c)
{
	int		i;
	int		x;
	int		y;
	int		j;
	char	*tmp;

	y = 0;
	j = 0;
	i = 0;
	tmp = ft_strnew(9);
	while (buf[i])
	{
		x = 0;
		while (buf[i] && buf[i] != '\n')
		{
			if (buf[i] == '#')
			{
				tmp[j] = (x + 48);
				tmp[j + 4] = (y + 48);
				j++;
			}
			x++;
			i++;
		}
		y++;
		i++;
	}
	*c = *c + 1;
	tmp[j + 4] = *c;
	tmp[j + 5] = '\0';
	return (tmp);
}
