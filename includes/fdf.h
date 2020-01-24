/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.f...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:11:29 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/01/23 18:28:29 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../libft/libft.h"
#include "get_next_line.h"
#include "/usr/local/include/mlx.h"
#include <stdlib.h>
#include <fcntl.h>

typedef struct			s_read
{
	int					count;
	char				*line;
	struct s_read		*next;
}						t_read;

typedef struct			s_point
{
	float				y;
	float				x;
	float				z;
	char				*hex_color;
}						t_point;

#endif
