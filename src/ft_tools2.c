/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.f...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:55:53 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/03/12 16:00:06 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_check_move(int *index, int *move)
{
	if (*index < 0)
	{
		*index *= -1;
		*move = -1;
	}
	else
		*move = 1;
}

int		ft_use_mouse(int button, int x, int y, void *param)
{
	t_fdf	*map;

	map = param;
	(void)x;
	(void)y;
	button == 4 ? ft_press_minus(map) : 0;
	button == 5 ? ft_press_plus(map) : 0;
	return (0);
}

int		ft_exit_properly(int button, void *param)
{
	t_fdf	*map;

	map = param;
	ft_putnbr(button);
	if (button)
		exit(0);
	return (0);
}

void	ft_rotate_x_axis(t_point *a, t_fdf *map)
{
	float	temp_y;

	temp_y = a->y;
	if (map->angle_x != 0)
	{
		a->y = temp_y * cosf(map->angle_x) + a->z * sinf(map->angle_x);
		a->z = -temp_y * sinf(map->angle_x) + a->z * cosf(map->angle_x);
	}
}

void	ft_rotate_y_axis(t_point *a, t_fdf *map)
{
	float	temp_z;

	temp_z = a->z;
	if (map->angle_y != 0)
	{
		a->z = temp_z * cosf(map->angle_y) + a->x * sinf(map->angle_y);
		a->x = -temp_z * sinf(map->angle_y) + a->x * cosf(map->angle_y);
	}
}
