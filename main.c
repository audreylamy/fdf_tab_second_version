/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:09:40 by alamy             #+#    #+#             */
/*   Updated: 2018/01/31 16:52:45 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map *parse;
	t_env tmp;

	if (argc != 2)
		ft_putstr("too many or too few arguments\n");
	tmp.mlx = mlx_init();
	tmp.win = mlx_new_window(tmp.mlx, WINDOW_L, WINDOW_H, "mlx 42");
	parse = ft_begin_parse(argv);
	// ft_print_tab(parse);
	ft_create_image(parse, &tmp);
	mlx_key_hook(tmp.win, my_key_funct, &tmp);
	mlx_loop(tmp.mlx);
	return (0);
}
