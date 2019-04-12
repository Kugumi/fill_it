/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bctr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:25:27 by dstracke          #+#    #+#             */
/*   Updated: 2019/04/12 18:22:40 by dstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*paste(char *map, char *str, int str_i, int cmp_sd)
{
	int		box[4];
	int		i;
	int		d;

	i = 0;
	d = 0;
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
			while (--i != 0)
				map[box[i] + d] = str[str_i + 4];
			return (map); // возврат карты заполненной фигурой, но необходим какой-то счетчик внешний для сохранения указателя на то место, где перестановка фигурки.
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

char	*solve(char *str, int cmp_sd)
{
	int		cmp_sd;
	char	*map;
	int		str_i;

	str_i = 0;
	cmp_sd = ft_sqrt(str);
	map = mapper(cmp_sd);
	while (!bctr(map, str, str_i, cmp_sd)) // здесь нужно в конце каким-то образом вернуть заполненную карту
	{
		map = mapper(cmp_sd);
		cmp_sd++;
	}
	return (map);
}

static bool	bctr(char *map, char *str, int str_i, int cmp_sd)
{
	if (!str[str_i])
		return (0);
	while (1) // пока непонятно за счет чего будем циклить
	{
		if (paste(map, str, str_i, cmp_sd)) // если встала фигура
		{
			if (bctr(map, str, str_i + 9, cmp_sd)) // пробуем некст, но как уже писалось ранне - нужен якорь, который даст возможность ставить текущую фигуру после предыдущей в самой мапе
				return (1);
			else
			{
				ft_remove(map, str, str_i); // для фии ремува нужен якорь для очистки пред текущей, не подставленной фигуры, но мб можно обойтись без этого
				return (bctr(map, str, str_i, cmp_sd))
			}
		}
		str_i += 9;
	}
	return (0);
}

char	*ft_remove(char *map, char *str, int str_i)
{
	
}
