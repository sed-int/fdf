/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:55:58 by hcho2             #+#    #+#             */
/*   Updated: 2023/06/28 20:08:46 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = -1;
	while (s[++i])
		;
	write(fd, s, i);
}

void	ft_error(char *str)
{
	perror(str);
	exit(1);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	t_map	map;

	if (ac < 2)
		return (1);
	parse_map(av[1], &map);
	ft_isometric(&map);
	scaling(&map);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WINDOW_HEIGHT, WINDOW_WIDTH, av[1]);
	vars.img = mlx_new_image(vars.mlx, WINDOW_HEIGHT, WINDOW_WIDTH);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel,
			&vars.line_length, &vars.endian);
	draw(&map, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_loop(vars.mlx);
}
