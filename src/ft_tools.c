/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.f...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:56:49 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/06/02 12:06:53 by hhuhtane         ###   ########.fr       */
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

void	ft_read_rows(int fd, t_fdf *map)
{
	char	*str;

	map->rows = 0;
	while (get_next_line(fd, &str) > 0)
	{
		map->rows += 1;
		map->columns = ft_array_len(str, ' ') - 1;
		ft_memdel((void**)&str);
	}
	free(str);
	if (map->rows < 2 || map->columns < 2)
	{
		ft_putendl("Map is invalid!");
		exit(0);
	}
}

void	ft_clean_buffer(t_fdf *map)
{
	size_t	i1;
	size_t	i2;
	size_t	pixel;

	i1 = 0;
	i2 = 0;
	while (i1 < WIN_Y)
	{
		while (i2 < WIN_X)
		{
			pixel = i1 * map->size_line / 4 + i2;
			map->buffer[pixel] = map->bg_color;
			i2++;
		}
		i2 = 0;
		i1++;
	}
}

void	ft_rotate_z_axis(t_point *a, t_fdf *map)
{
	float	temp_x;

	temp_x = a->x;
	if (map->angle_z != 0)
	{
		a->x = temp_x * cosf(map->angle_z) + a->y * sinf(map->angle_z);
		a->y = -temp_x * sinf(map->angle_z) + a->y * cosf(map->angle_z);
	}
}
