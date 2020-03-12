/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.f...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:34:12 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/03/10 16:41:35 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_press_left(t_fdf *map)
{
	map->x_disp -= 10;
	ft_perspective(map);
	ft_bresenham_map(map);
}

void	ft_press_right(t_fdf *map)
{
	map->x_disp += 10;
	ft_perspective(map);
	ft_bresenham_map(map);
}

void	ft_press_up(t_fdf *map)
{
	map->y_disp -= 10;
	ft_perspective(map);
	ft_bresenham_map(map);
}

void	ft_press_down(t_fdf *map)
{
	map->y_disp += 10;
	ft_perspective(map);
	ft_bresenham_map(map);
}
