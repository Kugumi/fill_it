/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bctr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:25:27 by dstracke          #+#    #+#             */
/*   Updated: 2019/04/18 19:42:49 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*paste(char *map, char *str, int cmp_sd)
{
	int		box[4];
	int		i;
	int		d;
	int		str_i;

	i = 0;
	d = 0;
	str_i = 0;
	while (i < 4)
	{
		box[i] = (str[str_i] - 48) + (str[str_i + 4] - 48) * (cmp_sd + 1);
		i++;
		str_i++;
	}
	while (d != (cmp_sd * (cmp_sd + 1) - 2))
	{
		if (map[box[0] + d] == '.' && map[box[1] + d] == '.' && map[box[2] + d] == '.' && map[box[3] + d] == '.')
		{
			while (i-- != 0)
				map[box[i] + d] = str[str_i + 4];
			return (map);
		}
		d++;
	}
	return (NULL);
}

int		ft_sqrt(char *str)
{
	int		cmp_sd;
	int		i;

	cmp_sd = 1;
	i = ft_strlen(str) / 9 * 4;
	while (cmp_sd * cmp_sd < i)
		cmp_sd++;
	return (cmp_sd);
}

void	ft_remove(char **map, t_tetr *tetr)
{
	int i;
	char tmp[10] = "";
	char	*s;
	s = ft_strcpy(tmp, tetr->fig);
	i = 0;
	while (map[0][i])
	{
		if (map[0][i] == s[9])
			map[0][i] = '.';
		i++;
	}
}
char	*bctr(char *map, t_tetr *tetr, int cmp_sd)
{
    char    *t;

	while (*map)
	{
		if ((map = paste(map, tetr->fig, cmp_sd)))
		{
			if (tetr->next == NULL)
				return (map);
			t = bctr(map, tetr->next, cmp_sd);
			if (t)
			    return (t);
		}
		else
		{
			ft_remove(&map, tetr);
			map++;
		}
	}
	return (0);
}

char	*solve(char *str, t_tetr *tetr, int cmp_sd)
{
	char	*map;
	char	*tmpmp;
	int		str_i;

	str_i = 0;
	map = ft_strnew(131);
	mapper(cmp_sd, &map);
	while (!(bctr(map, tetr, cmp_sd)))
	{
		cmp_sd++;
		map = mapper(cmp_sd, &map);
	}
	return (map);
}
