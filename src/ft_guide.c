/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_guide.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.f...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:04:27 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/03/12 16:13:41 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_write_win(t_fdf *map, char *str, int x, int y)
{
	mlx_string_put(map->mlx_ptr, map->win_ptr, x, y, 0xFFFFFF, str);
}

void			ft_draw_to_img(int x, int y, int color, t_fdf *map)
{
	int		pixel;

	pixel = (y * map->size_line / 4) + x;
	map->buffer[pixel] = color;
}

void			ft_img_to_win(t_fdf *map)
{
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);
}

void			ft_guide(t_fdf *map)
{
	ft_write_win(map, "GUIDE:", 50, 50);
	ft_write_win(map, "- Move image with ARROW keys.", 50, 80);
	ft_write_win(map, "- Zoom image with + and - keys.", 50, 100);
	ft_write_win(map, "- Modify altitude with [ and ] keys.", 50, 120);
	ft_write_win(map, "- ROTATE: with numpads 4, 6, 2, 8, 1, 9", 50, 140);
	ft_write_win(map, "- PERSPECTIVE: Parallel = 1 | Isometric = 2", 50, 160);
	ft_write_win(map, "- BACKGROUND: Z = Red, X = Green, C = Blue:", 50, 180);
	ft_write_win(map, "MOUSE:", 50, 210);
	ft_write_win(map, "- ZOOM: scroll with wheel button", 50, 230);
}
