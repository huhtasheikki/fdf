/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.f...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:34:12 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/03/05 12:36:27 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_press_left(t_fdf *map)
{
	map->x_disp -= 100;
	ft_perspective(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);
	ft_bresenham_map(map);
}

void	ft_press_right(t_fdf *map)
{
	map->x_disp += 100;
	ft_perspective(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);
	ft_bresenham_map(map);
}

void	ft_press_up(t_fdf *map)
{
	map->y_disp -= 100;
	ft_perspective(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);
	ft_bresenham_map(map);
}

void	ft_press_down(t_fdf *map)
{
	map->y_disp += 100;
	ft_perspective(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);
	ft_bresenham_map(map);
}
