/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 10:39:04 by alamy             #+#    #+#             */
/*   Updated: 2018/01/31 18:39:27 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void ft_create_new_image(t_env *tmp)
{
	mlx_destroy_image(tmp->mlx, tmp->img.img_ptr);
	tmp->img.img_ptr = mlx_new_image(tmp->mlx, WINDOW_L, WINDOW_H);
	tmp->img.data = (int*)mlx_get_data_addr(tmp->img.img_ptr, &tmp->img.bpp, &tmp->img.size_bits, &tmp->img.endian);
	ft_draw_line_horiz(tmp);
	ft_draw_line_vertical(tmp);
 	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->img.img_ptr, 0, 0);
}

int my_key_funct(int keycode, t_env *tmp)
{
	printf("key event %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_image(tmp->mlx, tmp->img.img_ptr);
		exit(0);
	}
	if (keycode == UP)
	{	
		tmp->new_move_y -= 20;
		ft_print_tab(tmp);
		ft_create_new_image(tmp);
	}
	if (keycode == RIGHT)
	{	
		tmp->new_move_x += 20;
		ft_create_new_image(tmp);
	}
	if (keycode == DOWN)
	{	
		tmp->new_move_y += 20;
		ft_create_new_image(tmp);
	}
	if (keycode == LEFT)
	{	
		tmp->new_move_x -= 20;
		ft_create_new_image(tmp);
	}
	if (keycode == 84) // 2
	{	
		ft_transformation_event(tmp);
		ft_create_new_image(tmp);
	}
	return(0);
}

int my_mouse_funct(int keycode, t_env *tmp)
{
	printf("key event %d\n", keycode);
	if (keycode == CLIC_LEFT)
	{	
		ft_transformation_event(tmp);
		ft_create_new_image(tmp);
	}
	return(0);
}

// t_vecteur4 ft_translation_event(int x, int y, int z, int w, int i)
// {
// 	t_vecteur4 	vecteur_trans;
// 	matrix4_t 	m_translation;
// 	t_vecteur4 resultat;
	
// 	vecteur_trans = create_vecteur4(20, 20, 0, 1);
// 	m_translation = matrix_translation_center(vecteur_trans);

// 	resultat = create_vecteur4(x, y, z, w);

// 	resultat = ft_cal_translation(resultat, m_translation);
// 	return(resultat);
// }


t_vecteur4 ft_homothetie_event(int x, int y, int z, int w, int i)
{
	t_vecteur4 	vecteur_homothetie;
	matrix4_t 	m_homothetie;
	t_vecteur4 resultat;
	
	vecteur_homothetie = create_vecteur4(2, 2, 1, 1);
	m_homothetie = matrix_homothetie(vecteur_homothetie);

	resultat = create_vecteur4(x, y, z, w);

	resultat = ft_cal_homothetie(resultat, m_homothetie);
	return(resultat);
}

void ft_transformation_event(t_env *tmp)
{
	int i;
	int j;
	int x0;
	int y0;
	int z0;
	int w0;
	t_vecteur4 	resultat;

	i = 0;
	while (i < tmp->map->nb_line)
	{
		j = 0;
		while (j < tmp->map->lines[i]->lenght)
		{
			x0 = tmp->map->lines[i]->points[j]->x;
			y0 = tmp->map->lines[i]->points[j]->y;
			z0 = tmp->map->lines[i]->points[j]->z;
			w0 = tmp->map->lines[i]->points[j]->w;
			resultat = ft_homothetie_event(x0, y0, z0, w0, i);
			tmp->map->lines[i]->points[j]->x = resultat.x1;
			tmp->map->lines[i]->points[j]->y = resultat.y1;
			tmp->map->lines[i]->points[j]->z = resultat.z1;
			tmp->map->lines[i]->points[j]->w = resultat.w1;
			j++;
		}
		i++;
	}
}
