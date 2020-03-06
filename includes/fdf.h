/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.f...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:11:29 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/03/06 16:17:21 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "/usr/local/include/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define ESC 53
# define PARALLEL 18
# define ISO 19
# define PLUS 24
# define MINUS 27
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define LOWER 33
# define HIGHER 30
// IS IT IMPORTANT?
# define ROTATE_R 29
# define ROTATE_L 25

# define WIN_X 1400
# define WIN_Y 1200
# define START_COLOR 0x0000FF
# define END_COLOR 16777215

typedef struct			s_point
{
	float				x;
	float				y;
	float				z;
	int					ix;
	int					iy;
	int					iz;
	int					color;
}						t_point;

typedef struct			s_fdf
{
	t_point				**dot;
	size_t				rows;
	size_t				columns;
	int					min_height;
	int					max_height;
	int					size;
	int					x_disp;
	int					y_disp;
	int					z_disp;
	int					perspective;
	float				angle_xy;
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	void				*img_guide_ptr;
}						t_fdf;

void					ft_read_file(int fd, char *file, t_fdf *map);
void					ft_read_rows(int fd, t_fdf *map);
void					ft_bresenham_map(t_fdf *map);
void					ft_perspective(t_fdf *map);
void					rotate_x(int x, int y, t_point *a, t_fdf *map);
void					rotate_y(int x, int y, t_point *a, t_fdf *map);

int						press_keyboard(int key, void *param);
void					ft_press_parallel(t_fdf *map);
void					ft_press_iso(t_fdf *map);
void					ft_press_plus(t_fdf *map);
void					ft_press_minus(t_fdf *map);
void					ft_press_left(t_fdf *map);
void					ft_press_right(t_fdf *map);
void					ft_press_up(t_fdf *map);
void					ft_press_down(t_fdf *map);
void					ft_press_lower(t_fdf *map);
void					ft_press_higher(t_fdf *map);
void					ft_press_rotate_l(t_fdf *map);
void					ft_press_rotate_r(t_fdf *map);
void					ft_current_color(t_point *a, t_point *b, t_point *c);
void					ft_read_rows(int fd, t_fdf *map);

int						get_pct(int a, int b, int c);
int						ft_color(int start, int end, int percent);

#endif
