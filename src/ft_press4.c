/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.f...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:38:28 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/03/10 14:07:13 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_press_red(t_fdf *map)
{
	map->bg_color += 0x110000;
	ft_bresenham_map(map);
}

void	ft_press_green(t_fdf *map)
{
	map->bg_color += 0x1100;
	ft_bresenham_map(map);
}

void	ft_press_blue(t_fdf *map)
{
	map->bg_color += 0x11;
	ft_bresenham_map(map);
}
