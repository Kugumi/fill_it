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

int paste(char **map, char *str, int cmp_sd, int d)
{
	int		box[4];
	int		i;
	int		str_i;

	i = 0;
	str_i = 0;
	while (i < 4)
	{
		box[i] = (str[str_i] - 48) + (str[str_i + 4] - 48) * (cmp_sd + 1);
		i++;
		str_i++;
	}
	while (d != (cmp_sd * (cmp_sd + 1) - 2))
	{
		if (map[0][box[0] + d] == '.' && map[0][box[1] + d] == '.' && map[0][box[2] + d] == '.' && map[0][box[3] + d] == '.')
		{
			while (i-- != 0)
				map[0][box[i] + d] = str[str_i + 4];
			return (1);
		}
		d++;
	}
	return (0);
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
		if (map[0][i] == s[8])
			map[0][i] = '.';
		i++;
	}
}
char	*bctr(char *map, t_tetr *tetr, int cmp_sd, int i)
{
    char    *t;

    if (paste(&map, tetr->fig, cmp_sd, i))
    {
    	if (tetr->next == NULL)
    		return (map);
    	t = bctr(map, tetr->next, cmp_sd, i);
    	if (t)
    		return (t);
    }
    if (tetr->prev)
    {
    	ft_remove(&map, tetr = tetr->prev);
    	return (bctr(map, tetr, cmp_sd, i + 1));
    }
    if (i == cmp_sd * (cmp_sd + 1))
		return (NULL);
	return (map);
}

char	*solve(char *str, t_tetr *tetr, int cmp_sd)
{
	char	*map;
	char	*tmpmp;
	int		str_i;

	str_i = 0;
	map = ft_strnew(131);
	mapper(cmp_sd, &map);
	while (!(bctr(map, tetr, cmp_sd, 0)))
	{
		cmp_sd++;
		map = mapper(cmp_sd, &map);
	}
	return (map);
}
