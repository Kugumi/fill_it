/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bctr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:25:27 by dstracke          #+#    #+#             */
/*   Updated: 2019/04/09 14:27:56 by dstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static bool	paste(char *map, char *str, int str_i, int cmp_sd)
{
	int		box[4];
	int		i;
	int		d;

	i = 0;
	doter = 0;
	while (i < 4)
	{
		box[i] = (str[str_i] - 48) + (str[str_i + 4] - 48) * (cmp_sd + 1);
		i++;
		str_i++;
	}
	while (d != (cmp_sd * (cmp_sd + 1) - 2))
	{
		if (map[box[0] + d] == '.' && map[box[1] + d] == '.' && map[box[2] + d] == '.' && map[box[3] + d] == '.')
			return (1);
		d++;
	}
	return (0);
}

char	*bctr(char *map, char *str, int str_i, int cmp_sd)
{
	int		str_i;

	str_i = 0;
	if (!str[str_i])
		return (NULL);
	while (str[str_i])
	{
		if (paste(map, str, str_i, cmp_sd))
		{
			//вставка фигуры
			str_i += 9;
			if (bctr(map, str, ))
				return (1);
			else
				removeprevfigure();
		}
		str_i++;
	}
	return (0);
}
