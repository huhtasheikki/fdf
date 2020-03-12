/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.f...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:44:51 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/03/12 11:54:07 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_collect_data(int y, char **split, t_fdf *map)
{
	size_t		i1;

	i1 = 0;
	while (i1 < map->columns)
	{
		map->dot[y][i1].z = ft_atoi(split[i1]) / map->z_disp;
		map->dot[y][i1].iz = ft_atoi(split[i1]);
		if (map->dot[y][i1].iz < map->min_z)
			map->min_z = map->dot[y][i1].iz;
		if (map->dot[y][i1].iz > map->max_z)
			map->max_z = map->dot[y][i1].iz;
		if (ft_strchr(split[i1], ',') == NULL)
			map->dot[y][i1].color = 0;
		else
			map->dot[y][i1].color = ft_atoi_base((ft_strchr(split[i1],
															',') + 3), 16);
		ft_memdel((void**)&split[i1]);
		i1++;
	}
	ft_memdel((void**)&split);
}

static void		ft_read_first(int fd, t_fdf *map)
{
	char		*str;
	char		**split;

	if (get_next_line(fd, &str) < 0)
		exit(0);
	map->columns = ft_array_len(str, ' ') - 1;
	map->dot[0] = (t_point*)malloc(sizeof(t_point) * (map->columns));
	split = ft_strsplit(str, ' ');
	ft_memdel((void**)&str);
	ft_collect_data(0, split, map);
}

static void		ft_read_rest(int fd, t_fdf *map)
{
	char		*str;
	char		**split;
	size_t		i1;

	i1 = 1;
	while (i1 < map->rows)
	{
		if (get_next_line(fd, &str) < 0)
			exit(0);
		if (map->columns != (ft_array_len(str, ' ') - 1))
		{
			ft_putendl("Map is invalid!");
			exit(0);
		}
		map->dot[i1] = (t_point*)malloc(sizeof(t_point) * (map->columns));
		split = ft_strsplit(str, ' ');
		ft_memdel((void**)&str);
		ft_collect_data(i1, split, map);
		i1++;
	}
}

static void		ft_read_map(int fd, t_fdf *map)
{
	ft_read_first(fd, map);
	ft_read_rest(fd, map);
}

void			ft_read_file(int fd, char *file, t_fdf *map)
{
	ft_read_rows(fd, map);
	close(fd);
	if (!(fd = open(file, O_RDONLY)))
		exit(0);
	map->dot = (t_point**)malloc(sizeof(t_point*) * map->rows);
	ft_read_map(fd, map);
	close(fd);
}
