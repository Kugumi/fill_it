/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:01:46 by jijerde           #+#    #+#             */
/*   Updated: 2019/04/16 02:20:14 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"

# define BUFF_SIZE 21

typedef struct	s_tetr
{
	char *fig;
 	struct	s_tetr *next;
}				t_tetr;

#endif
