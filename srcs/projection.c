/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:08:19 by hcho2             #+#    #+#             */
/*   Updated: 2023/07/06 16:26:52 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(double *x, double *y, double *z)
{
	double	prev_x;
	double	prev_y;
	double	prev_z;
	double	theta;

	prev_x = *x;
	prev_y = *y;
	prev_z = *z;
	theta = M_PI / 3;
	*x = prev_x;
	*y = prev_y * cos(theta) - prev_z * sin(theta);
	*z = prev_y * sin(theta) + prev_z * cos(theta);
}

void	rotate_y(double *x, double *y, double *z)
{
	double	prev_x;
	double	prev_y;
	double	prev_z;
	double	theta;

	prev_x = *x;
	prev_y = *y;
	prev_z = *z;
	theta = M_PI / 3;
	*x = prev_x * cos(theta) - prev_z * sin(theta);
	*y = prev_y;
	*z = prev_x * sin(theta) + prev_z * cos(theta);
}

void	rotate_z(double *x, double *y, double *z)
{
	double	prev_x;
	double	prev_y;
	double	prev_z;
	double	theta;

	prev_x = *x;
	prev_y = *y;
	prev_z = *z;
	theta = M_PI / -4;
	*x = prev_x * cos(theta) - prev_y * sin(theta);
	*y = prev_x * sin(theta) + prev_y * cos(theta);
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
				&map->table[i][j].z);
			rotate_x(&map->table[i][j].x, &map->table[i][j].y,
				&map->table[i][j].z);
		}
	}
}
