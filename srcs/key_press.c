/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:23:05 by hcho2             #+#    #+#             */
/*   Updated: 2023/07/06 17:10:23 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_translate(int keycode, t_env *env)
{
	if (keycode == LEFT)
		env->x_offset -= 10;
	else if (keycode == RIGHT)
		env->x_offset += 10;
	else if (keycode == DOWN)
		env->y_offset += 10;
	else if (keycode == UP)
		env->y_offset -= 10;
}

void	ft_zoom(int keycode, t_env *env)
{
	int	i;
	int	j;

	if (keycode == PLUS)
		env->zoom = 1.03;
	else if (keycode == MINUS)
		env->zoom = 0.97;
	i = -1;
	while (++i < env->map->height)
	{
		j = -1;
		while (++j < env->map->width)
		{
			env->map->table[i][j].x *= env->zoom;
			env->map->table[i][j].y *= env->zoom;
			env->map->table[i][j].z *= env->zoom;
		}
	}
}

void	ft_reset(t_env *env)
{
	env->x_offset = 500;
	env->y_offset = 500;
	mapcpy(env->map->table, env->map->input, env->map);
	ft_isometric(env->map);
	scaling(env->map);
}

int	key_press(int keycode, t_env *env)
{
	if (keycode == LEFT || keycode == RIGHT
		|| keycode == DOWN || keycode == UP)
		ft_translate(keycode, env);
	else if (keycode == PLUS || keycode == MINUS)
		ft_zoom(keycode, env);
	else if (keycode == SPACE)
		ft_reset(env);
	else if (keycode == ESCAPE)
		exit(0);
	draw(env->map, env);
	return (0);
}
