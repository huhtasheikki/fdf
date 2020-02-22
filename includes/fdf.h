/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.f...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:11:29 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/02/22 14:12:24 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "/usr/local/include/mlx.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct			s_point
{
	float				y;
	float				x;
	float				z;
	int					color;
}						t_point;

typedef struct			s_fdf
{
	t_point				**dot;
	void				*mlx_ptr;
	void				*win_ptr;
}						t_fdf;

void					ft_read_file(int fd, char *file, t_fdf *map);
void					ft_read_rows(int fd, int *rows);


#endif
