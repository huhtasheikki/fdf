/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.f...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:15:56 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/03/12 15:54:20 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_assign_dc(t_point *a, t_point *b, t_point *c, t_point *delta)
{
	delta->ix = b->ix - a->ix;
	delta->iy = b->iy - a->iy;
	c->iy = a->iy;
	c->ix = a->ix;
	c->color = a->color;
}

static void		ft_line_low(t_point *a, t_point *b, t_fdf *map)
{
	t_point		delta;
	t_point		c;
	int			y_m;
	float		der;

	ft_assign_dc(a, b, &c, &delta);
	ft_check_move(&delta.iy, &y_m);
	der = 2 * delta.iy - delta.ix;
	while (c.ix != b->ix)
	{
		ft_current_color(a, b, &c);
		if (c.ix >= 0 && c.ix < WIN_X && c.iy >= 0 && c.iy < WIN_Y)
			ft_draw_to_img(c.ix, c.iy, c.color, map);
		if (der > 0)
		{
			c.iy += y_m;
			der = der - 2 * delta.ix;
		}
		der = der + 2 * delta.iy;
		c.ix++;
	}
}

static void		ft_line_high(t_point *a, t_point *b, t_fdf *map)
{
	t_point		delta;
	t_point		c;
	int			x_m;
	float		der;

	ft_assign_dc(a, b, &c, &delta);
	ft_check_move(&delta.ix, &x_m);
	der = 2 * delta.ix - delta.iy;
	while (c.iy != b->iy)
	{
		ft_current_color(a, b, &c);
		if (c.ix >= 0 && c.ix < WIN_X && c.iy >= 0 && c.iy < WIN_Y)
			ft_draw_to_img(c.ix, c.iy, c.color, map);
		if (der > 0)
		{
			c.ix += x_m;
			der = der - 2 * delta.iy;
		}
		der = der + 2 * delta.ix;
		c.iy++;
	}
}

static void		ft_draw_line_ab(t_point *a, t_point *b, t_fdf *map)
{
	if (ft_abs(b->iy - a->iy) < ft_abs(b->ix - a->ix))
	{
		if (a->ix > b->ix)
			ft_line_low(b, a, map);
		else
			ft_line_low(a, b, map);
	}
	else
	{
		if (a->iy > b->iy)
			ft_line_high(b, a, map);
		else
			ft_line_high(a, b, map);
	}
}

void			ft_bresenham_map(t_fdf *map)
{
	size_t		ix;
	size_t		iy;

	ix = 0;
	iy = 0;
	while (iy < map->rows)
	{
		while (ix < map->columns)
		{
			if ((ix + 1) < map->columns)
				ft_draw_line_ab(&map->dot[iy][ix], &map->dot[iy][ix + 1], map);
			if ((iy + 1) < map->rows)
				ft_draw_line_ab(&map->dot[iy][ix], &map->dot[iy + 1][ix], map);
			ix++;
		}
		iy++;
		ix = 0;
	}
	ft_img_to_win(map);
	ft_clean_buffer(map);
	ft_guide(map);
}
