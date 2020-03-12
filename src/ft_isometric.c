/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isometric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.f...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:42:48 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/03/12 16:05:55 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		iso_ix(t_point *a, t_fdf *map)
{
	float	x2;
	float	y2;

	x2 = a->x;
	y2 = a->y;
	a->ix = (((x2 - y2) * cos(0.523599)) + map->x_disp);
}

static void		iso_iy(t_point *a, t_fdf *map)
{
	float	x2;
	float	y2;

	x2 = a->x;
	y2 = a->y;
	a->iy = ((x2 + y2) * sin(0.523599) - a->z) + map->y_disp;
}

static void		ft_isomap(t_fdf *map)
{
	size_t		ix;
	size_t		iy;

	ix = 0;
	iy = 0;
	while (iy < map->rows)
	{
		while (ix < map->columns)
		{
			map->dot[iy][ix].x = ix * map->size;
			map->dot[iy][ix].y = iy * map->size;
			map->dot[iy][ix].z = map->dot[iy][ix].iz * map->size / map->z_disp;
			ft_rotate_x_axis(&map->dot[iy][ix], map);
			ft_rotate_y_axis(&map->dot[iy][ix], map);
			ft_rotate_z_axis(&map->dot[iy][ix], map);
			iso_ix(&map->dot[iy][ix], map);
			iso_iy(&map->dot[iy][ix], map);
			ix++;
		}
		iy++;
		ix = 0;
	}
}

static void		ft_parallel_map(t_fdf *map)
{
	size_t		ix;
	size_t		iy;

	ix = 0;
	iy = 0;
	while (iy < map->rows)
	{
		while (ix < map->columns)
		{
			map->dot[iy][ix].x = ix;
			map->dot[iy][ix].y = iy;
			ft_rotate_z_axis(&map->dot[iy][ix], map);
			map->dot[iy][ix].ix = map->dot[iy][ix].x * map->size + map->x_disp;
			map->dot[iy][ix].iy = map->dot[iy][ix].y * map->size + map->y_disp;
			ix++;
		}
		iy++;
		ix = 0;
	}
}

void			ft_perspective(t_fdf *map)
{
	if (map->perspective == ISO)
		ft_isomap(map);
	if (map->perspective == PARALLEL)
		ft_parallel_map(map);
}
