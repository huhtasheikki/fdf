/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.f...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:58:07 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/06/02 12:15:49 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_calculate_color(size_t x, size_t y, t_fdf *map)
{
	int		start[4];
	int		end[4];
	int		d;

	int_to_rgb(START_COLOR, start);
	int_to_rgb(END_COLOR, end);
	start[3] = start[0] + start[1] + start[2];
	end[3] = end[0] + end[1] + end[2];
	d = end[3] * get_pct(map->min_z, map->max_z, map->dot[y][x].iz) / 100;
	while (d > 0)
	{
		if (start[0] != end[0])
			start[0]++;
		else if (start[1] != end[1])
			start[1]++;
		else if (start[2] != end[2])
			start[2]++;
		d--;
	}
	if (map->dot[y][x].iz == map->max_z && map->dot[y][x].color == 0)
		map->dot[y][x].color = END_COLOR;
	else if (map->dot[y][x].iz == map->min_z && map->dot[y][x].color == 0)
		map->dot[y][x].color = START_COLOR;
	else if (map->dot[y][x].color == 0)
		map->dot[y][x].color = rgb_to_int(start);
}

void	ft_collect_color(t_fdf *map)
{
	size_t		iy;
	size_t		ix;

	iy = 0;
	ix = 0;
	while (iy < map->rows)
	{
		while (ix < map->columns)
		{
			ft_calculate_color(ix, iy, map);
			ix++;
		}
		iy++;
		ix = 0;
	}
}

t_fdf	*ft_create_tfdf(void)
{
	t_fdf		*map;

	map = (t_fdf*)malloc(sizeof(t_fdf));
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, WIN_X, WIN_Y, "Fdf hhuhtane");
	map->img_ptr = mlx_new_image(map->mlx_ptr, WIN_X, WIN_Y);
	map->buffer = (int*)mlx_get_data_addr(map->img_ptr, &map->bits_per_pixel,
											&map->size_line, &map->endian);
	map->bg_color = BACKGROUND;
	map->size = 10;
	map->x_disp = WIN_X / 2;
	map->y_disp = WIN_Y / 2;
	map->z_disp = 5;
	map->perspective = PARALLEL;
	map->angle_x = 0;
	map->angle_y = 0;
	map->angle_z = 0;
	return (map);
}

int		main(int argc, char **argv)
{
	int			fd;
	t_fdf		*map;

	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_putendl("fdf source.file");
		return (0);
	}
	map = ft_create_tfdf();
	ft_read_file(fd, argv[1], map);
	mlx_hook(map->win_ptr, 2, 0, press_keyboard, map);
	mlx_hook(map->win_ptr, 4, 0, ft_use_mouse, map);
	mlx_hook(map->win_ptr, 17, 0, ft_exit_properly, map);
	ft_collect_color(map);
	ft_perspective(map);
	ft_bresenham_map(map);
	mlx_loop(map->mlx_ptr);
	return (0);
}
