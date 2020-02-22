/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.f...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:58:07 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/02/22 14:21:19 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		press_keyboard(int key, void *param)
{
	if (key == 53)
		exit(0);
	param = 0;
	ft_putnbr(key);
	return (0);
}

/*
int				read_and_validate(char *file, t_point *xyz_array)
{

collect data from the file, line by line
use ft_strsplit to split line read to strings
store the data to linked list and continue to next line?

use atoi to first gather variable Z
use ft_strchr to find ',' -> if found collect the color
	return (1);
}
*/

void	ft_read_rows(int fd, int *rows)
{
	char		*str;

	*rows = 0;
	while (get_next_line(fd, &str) > 0)
	{
		*rows += 1;
		free(str);
	}
}

void	ft_collect_data(size_t *x1, int y, char **split, t_fdf *map)
{
	size_t		i1;

	map->dot[0][0].x = 3;

	i1 = 0;
	while (i1 < *x1)
	{
		map->dot[y][i1].y = y;
		map->dot[y][i1].x = i1;
		map->dot[y][i1].z = ft_atoi(split[i1]);
		if (ft_strchr(split[i1], ',') == NULL)
			map->dot[y][i1].color = 0;
		else
			map->dot[y][i1].color = ft_atoi_base((ft_strchr(split[i1], ',') + 3), 16);
		free(split[i1]);
		i1++;
	}
	split = NULL;
}

void	ft_read_first(int fd, size_t *x1, t_fdf *map)
{
	char		*str;
	char		**split;

	if (get_next_line(fd, &str) < 0)
		exit(0);
	*x1 = ft_array_len(str, ' ') - 1;
	map->dot[0] = (t_point*)malloc(sizeof(t_point) * (*x1));
	split = ft_strsplit(str, ' ');
	free(str);
	ft_collect_data(x1, 0, split, map);
}

void	ft_read_rest(int fd, size_t *x1, int rows, t_fdf *map)
{
	char		*str;
	char		**split;
	int			i1;

	i1 = 1;
	while (i1 < rows)
	{
		if (get_next_line(fd, &str) < 0)
			exit(0);
		if (*x1 != (ft_array_len(str, ' ') - 1))
		{
			ft_putnbr(i1);
			ft_putendl("Map is invalid!");
			exit(0);
		}
		map->dot[i1] = (t_point*)malloc(sizeof(t_point) * (*x1));
		split = ft_strsplit(str, ' ');
		free(str);
		ft_collect_data(x1, i1, split, map);
		i1++;
	}
}

void	ft_read_map(int fd, int rows, t_fdf *map)
{
	size_t		x1;

	ft_read_first(fd, &x1, map);
	ft_read_rest(fd, &x1, rows, map);
}

void	ft_read_file(int fd, char *file, t_fdf *map)
{
	int			rows;

	ft_read_rows(fd, &rows);
	ft_putnbr(rows);
	close(fd);
	if (!(fd = open(file, O_RDONLY)))
		exit(0);
	map->dot = (t_point**)malloc(sizeof(t_point*) * rows);
	ft_read_map(fd, rows, map);
	close(fd);
}

t_fdf	*ft_create_tfdf()
{
	t_fdf		*map;

	map = (t_fdf*)malloc(sizeof(t_fdf));
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, 800, 800, "Heikki's Fdf");
	return (map);
}

int		main(int argc, char **argv)
{
	int			fd;
	t_fdf		*map;


	int			x;
	int			y;

	x = 10;
	y = 10;

	if (argc != 2 || !(fd = open(argv[1], O_RDONLY)))
	{
		ft_putendl("fdf source.file");
		return (0);
	}
	else
	{
		map = ft_create_tfdf();
		ft_read_file(fd, argv[1], map);
		mlx_key_hook(map->win_ptr, press_keyboard, (void *)0);
	}

/*
	while (x < 200)
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x++, y++, 0xff0000);
	}
	mlx_string_put(map->mlx_ptr, map->win_ptr, 300, 100, 0xffffff, "I can write!");
*/
	mlx_loop(map->mlx_ptr);
	return (0);
}
