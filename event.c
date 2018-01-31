/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 10:39:04 by alamy             #+#    #+#             */
/*   Updated: 2018/01/31 16:58:30 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void ft_create_new_image(t_map *map, t_env *tmp)
{
	mlx_destroy_image(tmp->mlx, tmp->img.img_ptr);
	tmp->img.img_ptr = mlx_new_image(tmp->mlx, WINDOW_L, WINDOW_H);
	tmp->img.data = (int*)mlx_get_data_addr(tmp->img.img_ptr, &tmp->img.bpp, &tmp->img.size_bits, &tmp->img.endian);
	ft_draw_line_horiz(map, tmp);
	ft_draw_line_vertical(map, tmp);
 	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->img.img_ptr, 0, 0);
}

int my_key_funct(int keycode, t_env *tmp, t_map *map)
{
	printf("key event %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_image(tmp->mlx, tmp->img.img_ptr);
		exit(0);
	}
	if (keycode == UP)
	{	
		tmp->new_move_y += 20;
		ft_create_new_image(map, tmp);
	}
	if (keycode == RIGHT)
	{	
		tmp->new_move_x += 20;
		ft_create_new_image(map, tmp);
	}
	if (keycode == DOWN)
	{	
		tmp->new_move_y -= 20;
		ft_create_new_image(map, tmp);
	}
	if (keycode == LEFT)
	{	
		tmp->new_move_x -= 20;
		ft_create_new_image(map, tmp);
	}
	return(0);
}