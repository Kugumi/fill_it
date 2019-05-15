/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perebor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:06:05 by dstracke          #+#    #+#             */
/*   Updated: 2019/05/15 22:31:58 by dstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*buf19(ssize_t ret, char *str, char *buf, char *c)
{
	char		*tmp;

	if (ret == 20)
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

char	*ft_tet(int fd, char *buf)
{
	char		*tmp;
	static char	c = '@';
	char		*str;
	ssize_t		ret;

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

void	mapper(size_t cmp_sd, char *map)
{
	size_t		fill;

	fill = 0;
	while (fill < (cmp_sd * (cmp_sd + 1) - 1))
	{
		if ((fill + 1) % (cmp_sd + 1) != 0 || fill == 0)
		{
			map[fill] = '.';
			fill++;
		}
		else
		{
			map[fill] = '\n';
			fill++;
		}
	}
	fill++;
	map[fill] = '\0';
}

int		main(int argc, char **argv)
{
	int			fd;
	char		buf[22];
	char		*str;
	char		*tmp;
	t_tetr		*tetr;

	tetr = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		str = ft_tet(fd, buf);
		tetr = tlist(str);
		tmp = str;
		str = solve(tetr, ft_sqrt(str));
		free(tmp);
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
		free(str);
	}
	else
		write(1, "usage: ./fillit source_file\n", 29);
	if (tetr)
		freetlist(tetr);
	return (0);
}
