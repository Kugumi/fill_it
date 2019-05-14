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

int		paste(char *map, char *str, size_t cmp_sd, size_t d)
{
	size_t		box[4];
	size_t		i;
	size_t		str_i;

	i = 0;
	str_i = 0;
	while (i < 4)
	{
		box[i] = (str[str_i] - 48) + (str[str_i + 4] - 48) * (cmp_sd + 1);
		str_i++;
		i++;
	}
	if (map[box[0] + d] == '.' && map[box[1] + d] == '.' \
		&& map[box[2] + d] == '.' && map[box[3] + d] == '.')
	{
		while (i-- != 0)
			map[box[i] + d] = str[str_i + 4];
		return (1);
	}
	return (0);
}

size_t	ft_sqrt(char *str)
{
	size_t		cmp_sd;
	size_t		i;

	cmp_sd = 1;
	i = ft_strlen(str) / 9 * 4;
	while (cmp_sd * cmp_sd < i)
		cmp_sd++;
	return (cmp_sd);
}

void	ft_remove(char *map, t_tetr *tetr, size_t i)
{
	while (map[i])
	{
		if (map[i] == tetr->fig[8])
			map[i] = '.';
		i++;
	}
}

int		bctr(char *map, t_tetr *tetr, size_t cmp_sd)
{
	size_t		i;

	i = 0;
	if (!tetr)
		return (1);
	while (i < (cmp_sd * (cmp_sd + 1)))
	{
		if (paste(map, tetr->fig, cmp_sd, i))
		{
			if (bctr(map, tetr->next, cmp_sd))
				return (1);
			ft_remove(map, tetr, i);
		}
		i++;
	}
	return (0);
}

char	*solve(t_tetr *tetr, size_t cmp_sd)
{
	char		*map;

	map = ft_strnew(500);
	mapper(cmp_sd, map);
	while (!bctr(map, tetr, cmp_sd))
	{
		cmp_sd++;
		mapper(cmp_sd, map);
	}
	return (map);
}
