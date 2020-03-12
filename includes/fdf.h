/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.f...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:11:29 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/03/12 16:27:25 by hhuhtane         ###   ########.fr       */
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
# define ROTATE_X_R 83
# define ROTATE_X_L 92
# define ROTATE_Y_R 86
# define ROTATE_Y_L 88
# define ROTATE_Z_R 84
# define ROTATE_Z_L 91
# define COLOR_R 6
# define COLOR_G 7
# define COLOR_B 8

# define WIN_X 1400
# define WIN_Y 1200
# define START_COLOR 0x0000FF
# define END_COLOR 16777215
# define BACKGROUND 0x000000

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
	int					min_z;
	int					max_z;
	int					bg_color;
	int					size;
	int					x_disp;
	int					y_disp;
	int					z_disp;
	int					perspective;
	int					anglez;
	int					anglex;
	int					angley;
	float				angle_z;
	float				angle_x;
	float				angle_y;
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	int					*buffer;
}						t_fdf;

void					ft_read_file(int fd, char *file, t_fdf *map);
void					ft_read_rows(int fd, t_fdf *map);
void					ft_perspective(t_fdf *map);

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
void					ft_press_rotz_l(t_fdf *map);
void					ft_press_rotz_r(t_fdf *map);
void					ft_press_rotx_l(t_fdf *map);
void					ft_press_rotx_r(t_fdf *map);
void					ft_press_roty_l(t_fdf *map);
void					ft_press_roty_r(t_fdf *map);
void					ft_press_red(t_fdf *map);
void					ft_press_green(t_fdf *map);
void					ft_press_blue(t_fdf *map);

void					ft_rotate_x_axis(t_point *a, t_fdf *map);
void					ft_rotate_y_axis(t_point *a, t_fdf *map);
void					ft_rotate_z_axis(t_point *a, t_fdf *map);

int						get_pct(int a, int b, int c);
void					ft_clean_buffer(t_fdf *map);
void					ft_check_move(int *index, int *move);

int						ft_use_mouse(int button, int x, int y, void *param);
int						ft_exit_properly(int button, void *param);

void					ft_current_color(t_point *a, t_point *b, t_point *c);
void					ft_bresenham_map(t_fdf *map);
void					ft_guide(t_fdf *map);
void					ft_img_to_win(t_fdf *map);
void					ft_draw_to_img(int x, int y, int color, t_fdf *map);

void					int_to_rgb(int color, int *rgb);
int						rgb_to_int(int *rgb);

#endif
