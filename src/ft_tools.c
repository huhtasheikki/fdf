/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.f...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:56:49 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/03/06 16:07:41 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_pct(int a, int b, int c)
{
	int		current;
	int		distance;

	current = c - a;
	distance = b - a;
	if (distance == 0)
		return (100);
	else
		return (100 * current / distance);
}

void	rotate_x(int x, int y, t_point *a, t_fdf *map)
{
	if (map->angle_xy == 0)
		a->x = x;
	else
		a->x = x * cosf(map->angle_xy) + y * sinf(map->angle_xy);
}

void	rotate_y(int x, int y, t_point *a, t_fdf *map)
{
	if (map->angle_xy == 0)
		a->y = y;
	else
		a->y = x * sinf(map->angle_xy) + y * cosf(map->angle_xy);
}

void	ft_read_rows(int fd, t_fdf *map)
{
	char	*str;

	map->rows = 0;
	while (get_next_line(fd, &str) > 0)
	{
		map->rows += 1;
		ft_memdel((void**)&str);
	}
	free(str);
}
