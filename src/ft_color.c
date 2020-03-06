/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.f...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 12:12:09 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/03/05 16:16:52 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	int_to_rgb(int color, int *rgb)
{
	rgb[2] = color & 0xFF;
	rgb[1] = (color >> 8) & 0xFF;
	rgb[0] = (color >> 16) & 0xFF;
}

int		rgb_to_int(int *rgb)
{
	return ((rgb[0] << 16) + (rgb[1] << 8) + rgb[2]);
}

int		ft_color(int start, int end, int percent)
{
	int		start_rgb[3];
	int		end_rgb[3];
	int		current_rgb[3];
	int		delta[4];
	int		change;

	int_to_rgb(start, start_rgb);
	int_to_rgb(start, current_rgb);
	int_to_rgb(end, end_rgb);
	delta[0] = ft_abs(end_rgb[0] - start_rgb[0]);
	delta[1] = ft_abs(end_rgb[1] - start_rgb[1]);
	delta[2] = ft_abs(end_rgb[2] - start_rgb[2]);
	delta[3] = delta[0] + delta[1] + delta[2];
	change = delta[3] * percent / 100;
	while (change > 0)
	{
		if (current_rgb[0] != end_rgb[0])
			current_rgb[0]++;
		else if (current_rgb[1] != end_rgb[1])
			current_rgb[1]++;
		else if (current_rgb[2] != end_rgb[2])
			current_rgb[2]++;
		change--;
	}
	return (rgb_to_int(current_rgb));
}

void	ft_current_color(t_point *a, t_point *b, t_point *c)
{
	if (ft_abs(b->iy - a->iy) < ft_abs(b->ix - a->ix))
	{
		if (a->color < b->color)
			c->color = ft_color(a->color, b->color,
								get_pct(a->ix, b->ix, c->ix));
		else
			c->color = ft_color(b->color, a->color,
								get_pct(b->ix, a->ix, c->ix));
	}
	else
	{
		if (a->color < b->color)
			c->color = ft_color(a->color, b->color,
								get_pct(a->iy, b->iy, c->iy));
		else
			c->color = ft_color(b->color, a->color,
								get_pct(b->iy, a->iy, c->iy));
	}
}
