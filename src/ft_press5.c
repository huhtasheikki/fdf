/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.f...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 10:19:21 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/06/02 12:14:57 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_press_rotx_l(t_fdf *map)
{
	if (map->anglex == 0)
		map->anglex = 39;
	else
		map->anglex -= 1;
	if (map->anglex == 0)
		map->angle_x = 0;
	else
		map->angle_x = 2 * M_PI + M_PI * 0.05 * map->anglex;
	ft_perspective(map);
	ft_bresenham_map(map);
}

void	ft_press_rotx_r(t_fdf *map)
{
	if (map->anglex == 39)
		map->anglex = 0;
	else
		map->anglex += 1;
	if (map->anglex == 0)
		map->angle_x = 0;
	else
		map->angle_x = 2 * M_PI + M_PI * 0.05 * map->anglex;
	ft_perspective(map);
	ft_bresenham_map(map);
}

void	ft_press_roty_l(t_fdf *map)
{
	if (map->angley == 0)
		map->angley = 39;
	else
		map->angley -= 1;
	if (map->angley == 0)
		map->angle_y = 0;
	else
		map->angle_y = 2 * M_PI + M_PI * 0.05 * map->angley;
	ft_perspective(map);
	ft_bresenham_map(map);
}

void	ft_press_roty_r(t_fdf *map)
{
	if (map->angley == 39)
		map->angley = 0;
	else
		map->angley += 1;
	if (map->angley == 0)
		map->angle_y = 0;
	else
		map->angle_y = 2 * M_PI + M_PI * 0.05 * map->angley;
	ft_perspective(map);
	ft_bresenham_map(map);
}

void	ft_press_reset(t_fdf *map)
{
	map->bg_color = BACKGROUND;
	map->size = 10;
	map->x_disp = WIN_X / 2;
	map->y_disp = WIN_Y / 2;
	map->z_disp = 5;
	map->perspective = PARALLEL;
	map->angle_x = 0;
	map->angle_y = 0;
	map->angle_z = 0;
	ft_perspective(map);
	ft_bresenham_map(map);
}
