/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.f...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:28:26 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/03/12 11:56:47 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_press_lower(t_fdf *map)
{
	map->z_disp += 1;
	ft_perspective(map);
	ft_bresenham_map(map);
}

void	ft_press_higher(t_fdf *map)
{
	if (map->z_disp > 1)
	{
		map->z_disp -= 1;
		ft_perspective(map);
		ft_bresenham_map(map);
	}
}

void	ft_press_rotz_l(t_fdf *map)
{
	if (map->anglez == 0)
		map->anglez = 19;
	else
		map->anglez -= 1;
	if (map->anglez == 0)
		map->angle_z = 0;
	else
		map->angle_z = 2 * M_PI + M_PI * 0.1 * map->anglez;
	ft_perspective(map);
	ft_bresenham_map(map);
}

void	ft_press_rotz_r(t_fdf *map)
{
	if (map->anglez == 19)
		map->anglez = 0;
	else
		map->anglez += 1;
	if (map->anglez == 0)
		map->angle_z = 0;
	else
		map->angle_z = 2 * M_PI + M_PI * 0.1 * map->anglez;
	ft_perspective(map);
	ft_bresenham_map(map);
}
