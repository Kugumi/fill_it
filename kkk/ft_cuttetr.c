/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cuttetr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 20:35:08 by dstracke          #+#    #+#             */
/*   Updated: 2019/05/15 20:35:12 by dstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_cut1(char *tmp)
{
	char 	mini;
	int		i;

	mini = '4';
	i = 0;

	while (i < 4)
	{
		if (mini > tmp[i])
			mini = tmp[i];
		i++;
	}
	return (mini);
}

void	ft_cut2(char *tmp, char mini)
{
	int 	i;

	i = 0;
	while (i < 4 && mini != 0)
	{
		tmp[i] = tmp[i] - (mini - 48);
		i++;
	}
}

char	ft_cut3(char *tmp)
{
	char 	minj;
	int 	j;

	minj = '4';
	j = 4;
	while (j > 3 && j < 8)
	{
		if (minj > (tmp[j]))
			minj = (tmp[j]);
		j++;
	}
	return (minj);
}

void	ft_cut4(char *tmp, char minj)
{
	int 	j;

	j = 4;
	while ((j > 3 && j < 8) && minj != 0)
	{
		tmp[j] = tmp[j] - (minj - 48);
		j++;
	}
}

char	*ft_cuttetr(char *tmp)
{
	char 	mini;
	char 	minj;

	mini = ft_cut1(tmp);
	ft_cut2(tmp, mini);
	minj = ft_cut3(tmp);
	ft_cut4(tmp, minj);
	return (tmp);
}