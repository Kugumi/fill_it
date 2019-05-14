/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freetlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:52:39 by dstracke          #+#    #+#             */
/*   Updated: 2019/05/14 17:52:46 by dstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	freetlist(t_tetr *tetr)
{
	t_tetr *buf;

	while (tetr)
	{
		buf = tetr->next;
		free(tetr->fig);
		free(tetr);
		tetr = buf;
	}
}
