/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.f...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:58:07 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/03/06 16:22:10 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_calculate_color(size_t x, size_t y, t_fdf *map)
{
	int		palette;

	palette = END_COLOR - START_COLOR;
	if (map->dot[y][x].iz == map->max_height && map->dot[y][x].color == 0)
		map->dot[y][x].color = END_COLOR;
	else if (map->dot[y][x].iz == map->min_height && map->dot[y][x].color == 0)
		map->dot[y][x].color = START_COLOR;
	else if (map->dot[y][x].color == 0)
		map->dot[y][x].color = palette / (map->max_height - map->min_height)
			* (map->dot[y][x].iz - map->min_height) + START_COLOR;
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
	map->img_guide_ptr = mlx_new_image(map->mlx_ptr, WIN_X, (WIN_Y / 10));
	map->size = 10;
	map->x_disp = 500;
	map->y_disp = 500;
	map->z_disp = 5;
	map->perspective = PARALLEL;
	map->angle_xy = 0;
	return (map);
}

int		main(int argc, char **argv)
{
	int			fd;
	t_fdf		*map;

	if (argc != 2 || !(fd = open(argv[1], O_RDONLY)))
	{
		ft_putendl("fdf source.file");
		return (0);
	}
	else
	{
		map = ft_create_tfdf();
		ft_read_file(fd, argv[1], map);
		mlx_key_hook(map->win_ptr, press_keyboard, map);
	}
	ft_collect_color(map);
	ft_perspective(map);
	ft_bresenham_map(map);
	mlx_loop(map->mlx_ptr);
	return (0);
}
