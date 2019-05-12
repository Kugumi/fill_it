/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perebor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:06:05 by dstracke          #+#    #+#             */
/*   Updated: 2019/05/12 20:17:16 by dstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char 	*buf19(int ret, char *str, char *buf, char *c)
{
	char	*tmp;

	if (ret == 19)
	{
		buf[ret] = '\0';
		if (ft_validate(buf, ret))
		{
			tmp = ft_strjoin(str, ft_cuttetr(ft_cup(buf, c)));
			free(str);
			str = tmp;
		}
		else
		{
			write(1, "error\n", 6);
			return (NULL);
		}
	}
	else
	{
		write(1, "error\n", 6);
		return (NULL);
	}
	return (str);
}

char	*ft_tet(char *str, int fd, int ret, char *buf)
{
	char		*tmp;
	static char	c = '@';

	str = ft_strnew(0);
	while ((ret = read(fd, buf, 21)) == 21)
	{
		buf[ret] = '\0';
		if (ft_validate(buf, ret))
		{
			tmp = ft_strjoin(str, ft_cuttetr(ft_cup(buf, &c)));
			free(str);
			str = tmp;
		}
		else
		{
			write(1, "error\n", 6);
			return (NULL);
		}
	}
	if (ret != 21)
		str = buf19(ret, str, buf, &c);
	return (str);
}

void	mapper(int cmp_sd, char **map)
{
	int		fill;

	fill = 0;
	while (fill < (cmp_sd * (cmp_sd + 1) - 1))
	{
		if ((fill + 1) % (cmp_sd + 1) != 0 || fill == 0)
		{
            map[0][fill] = '.';
			fill++;
		}
		else
		{
			map[0][fill] = '\n';
			fill++;
		}
	}
	map[0][fill] = '\0';
}

int		main(int argc, char **argv)
{
	int			fd;
	char		buf[22];
	char		*str;
	int			ret;
	t_tetr 		*tetr;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		str = ft_tet(str, fd, ret, buf);
		tetr = tlist(str);
		printf("\n%s\n", str);
		str = solve(str, tetr, ft_sqrt(str));
		printf("%s\n", str);
	}
	else
		printf("Error: No more than 1 argument.");
	return (0);
}
