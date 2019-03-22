/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perebor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:06:05 by dstracke          #+#    #+#             */
/*   Updated: 2019/03/22 18:09:55 by dstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
# define BUFF_SIZE 21

int		ft_connect_count(char *s, int i);
int		ft_check_backslash(char *s, int i, int ret);
int		ft_prov_kol(int i, int j, int ret, int t);
int		ft_validate(char *buf, int ret);
char	*ft_cuttetr(char *tmp);
char	*ft_cup(char *buf, char *c);

char	*ft_tet(char *str, char *tmp, int fd, int ret, char *buf)
{
	static char	c = '@';

	str = ft_strnew(0);
	while ((ret = read(fd, buf, 21)) > 20)
	{
		buf[ret] = '\0';
		if (ft_validate(buf, ret))
		{
			tmp = ft_strjoin(str, ft_cuttetr(ft_cup(buf, &c)));
			free(str);
			str = tmp;
		}
		else
			break ;
	}
	if (ret < 21)
	{
		buf[ret] = '\0';
		if (ft_validate(buf, ret))
		{
			tmp = ft_strjoin(str, ft_cuttetr(ft_cup(buf, &c)));
			free(str);
			str = tmp;
		}
		else
			printf("kall");
	}
	return (str);
}

char	*fill_map(char *str)
{
	int		mp_ln;
	int		mp_sd;
	char	*map;
	int		str_i;
	int		map_i;
	int		x_i;
	int		fl_i;

	fl_i = 0;
	x_i = 4;
//	map_i = 0;
	str_i = 0;
	mp_sd = 1;
	mp_ln = (ft_strlen(str) / 9) * 4;
	while (mp_sd * mp_sd < mp_ln)
		mp_sd++;
	map = ft_strnew(131);
	while (fl_i < (mp_sd * (mp_sd + 1) - 1))
	{
		if ((fl_i + 1) % (mp_sd + 1) != 0 || fl_i == 0)
		{
			map[fl_i] = '.';
			fl_i++;
		}
		else
		{
			map[fl_i] = '\n';
			fl_i++;
		}
	}
	map[fl_i] = '\0';
	while (mp_ln / 4)
	{
		map_i = 0;
		while (str_i < x_i)
		{
				map_i = (str[str_i] - 48) + (str[str_i + 4] - 48) * (mp_sd + 1);
				if (map[map_i] == '.')
					map[map_i] = str[x_i + 4];
				else
					printf("kekeslales\n");
				str_i++;
				map_i++;
		}
		x_i += 
		mp_ln--;
	}
	return (map);
}

int		main(int argc, char **argv)
{
	int			fd;
	char		*tmp;
	char		buf[22];
	char		*str;
	int			ret;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		str = ft_tet(str, tmp, fd, ret, buf);
		printf("\n%s\n", str);
		str = fill_map(str);
		printf("%s\n", str);
	}
	else
	{
		printf("Error: No more than 1 argument.");
	}
	return (0);
}
