/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:55:58 by hcho2             #+#    #+#             */
/*   Updated: 2023/07/10 17:05:12 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_env	*init_env(void)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	env->x_angle = 1;
	env->y_angle = 1;
	env->z_angle = 1;
	env->zoom = 1;
	env->x_offset = 500;
	env->y_offset = 500;
	return (env);
}

void	file_check(char *filename)
{
	int		i;
	char	**check;

	check = ft_split(filename, '.');
	i = -1;
	while (check[++i])
		;
	if (i < 2)
		ft_error("Invalid file name.");
	if (ft_strcmp(check[--i], ".fdf") != 0)
		ft_error("Invalid file name.");
	ft_free_split(check);
}

int	main(int ac, char **av)
{
	t_env	*env;
	t_map	map;

	if (ac < 2)
		return (1);
	env = init_env();
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, av[1]);
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->addr = mlx_get_data_addr(env->img, &env->bpp,
			&env->line_length, &env->endian);
	parse_map(av[1], &map);
	ft_isometric(&map);
	scaling(&map);
	env->map = &map;
	draw(&map, env);
	mlx_hook(env->win, 2, 1L << 0, key_press, env);
	mlx_loop(env->mlx);
}
