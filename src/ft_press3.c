/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.f...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:28:26 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/03/06 10:10:34 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_press_lower(t_fdf *map)
{
	map->z_disp += 1;
	ft_perspective(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);
	ft_bresenham_map(map);
}

void	ft_press_higher(t_fdf *map)
{
	map->z_disp -= 1;
	ft_perspective(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);
	ft_bresenham_map(map);
}

void	ft_press_rotate_l(t_fdf *map)
{
	if (map->angle_xy == 0)
		map->angle_xy = 2 * M_PI;
	else
		map->angle_xy -= M_PI * 0.1;
	ft_perspective(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);
	ft_bresenham_map(map);
}

void	ft_press_rotate_r(t_fdf *map)
{
	if (map->angle_xy == 2 * M_PI)
		map->angle_xy = 0;
	else
		map->angle_xy += M_PI * 0.1;
	ft_perspective(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);
	ft_bresenham_map(map);
}
