/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.f...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:58:07 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/01/22 18:17:19 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		press_keyboard(int key, void *param)
{
	if (key == 53)
		exit(0);
	param = 0;
	ft_putnbr(key);
	return (0);
}

/*
int				read_and_validate(char *file, t_point *xyz_array)
{

}
*/

int		main(int argc, char **argv)
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_point		*xyz_array;
	int			x;
	int			y;

	
/*	if (read_and_validate != 1)
		return (0);
*/
	x = 10;
	y = 10;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 800, "Heikki's Fdf");
	mlx_key_hook(win_ptr, press_keyboard, (void *)0);
	while (x < 200)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x++, y++, 255255255);
	}
	mlx_loop(mlx_ptr);

	argv[0][0] = 'a';
	if (argc != 2)
		ft_putendl("fdf source.file");
	return (0);
}
