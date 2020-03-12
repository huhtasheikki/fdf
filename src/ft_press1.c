/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.f...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:21:39 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/03/12 15:18:45 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		press_keyboard(int key, void *param)
{
	t_fdf	*map;

	map = param;
	key == ESC ? exit(0) : 0;
	key == PARALLEL ? ft_press_parallel(map) : 0;
	key == ISO ? ft_press_iso(map) : 0;
	key == PLUS ? ft_press_plus(map) : 0;
	key == MINUS ? ft_press_minus(map) : 0;
	key == LEFT ? ft_press_left(map) : 0;
	key == RIGHT ? ft_press_right(map) : 0;
	key == UP ? ft_press_up(map) : 0;
	key == DOWN ? ft_press_down(map) : 0;
	key == LOWER ? ft_press_lower(map) : 0;
	key == HIGHER ? ft_press_higher(map) : 0;
	key == ROTATE_Z_L ? ft_press_rotz_l(map) : 0;
	key == ROTATE_Z_R ? ft_press_rotz_r(map) : 0;
	key == ROTATE_Y_L ? ft_press_roty_l(map) : 0;
	key == ROTATE_Y_R ? ft_press_roty_r(map) : 0;
	key == ROTATE_X_L ? ft_press_rotx_l(map) : 0;
	key == ROTATE_X_R ? ft_press_rotx_r(map) : 0;
	key == COLOR_R ? ft_press_red(map) : 0;
	key == COLOR_G ? ft_press_green(map) : 0;
	key == COLOR_B ? ft_press_blue(map) : 0;
	return (0);
}

void	ft_press_parallel(t_fdf *map)
{
	map->perspective = PARALLEL;
	ft_perspective(map);
	ft_bresenham_map(map);
}

void	ft_press_iso(t_fdf *map)
{
	map->perspective = ISO;
	ft_perspective(map);
	ft_bresenham_map(map);
}

void	ft_press_plus(t_fdf *map)
{
	map->size += 1;
	ft_perspective(map);
	ft_bresenham_map(map);
}

void	ft_press_minus(t_fdf *map)
{
	map->size -= 1;
	ft_perspective(map);
	ft_bresenham_map(map);
}
