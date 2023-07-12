/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:08:19 by hcho2             #+#    #+#             */
/*   Updated: 2023/07/12 15:26:56 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	rotate_x(double *x, double *y, double *z, double ratio)
{
	double	prev_x;
	double	prev_y;
	double	prev_z;

	prev_x = *x;
	prev_y = *y;
	prev_z = *z;
	*x = prev_x;
	*y = prev_y * cos(ratio) - prev_z * sin(ratio);
	*z = prev_y * sin(ratio) + prev_z * cos(ratio);
}

void	rotate_y(double *x, double *y, double *z, double ratio)
{
	double	prev_x;
	double	prev_y;
	double	prev_z;

	prev_x = *x;
	prev_y = *y;
	prev_z = *z;
	*x = prev_x * cos(ratio) - prev_z * sin(ratio);
	*y = prev_y;
	*z = prev_x * sin(ratio) + prev_z * cos(ratio);
}

void	rotate_z(double *x, double *y, double *z, double ratio)
{
	double	prev_x;
	double	prev_y;
	double	prev_z;

	prev_x = *x;
	prev_y = *y;
	prev_z = *z;
	*x = prev_x * cos(ratio) - prev_y * sin(ratio);
	*y = prev_x * sin(ratio) + prev_y * cos(ratio);
	*z = prev_z;
}

void	ft_isometric(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			rotate_z(&map->table[i][j].x, &map->table[i][j].y,
				&map->table[i][j].z, M_PI / -4);
			rotate_x(&map->table[i][j].x, &map->table[i][j].y,
				&map->table[i][j].z, M_PI / 3);
		}
	}
}
