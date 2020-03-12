/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.f...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 10:19:21 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/03/12 16:07:26 by hhuhtane         ###   ########.fr       */
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
