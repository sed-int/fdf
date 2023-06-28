/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:58:00 by hcho2             #+#    #+#             */
/*   Updated: 2023/06/28 20:37:04 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_vars *vars, int x, int y, int color)
{
	char	*dest;

	dest = vars->addr + (y * vars->line_length + x
			* (vars->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

void	dda(t_vars *vars, t_point p1, t_point p2)
{
	double	dx;
	double	dy;
	double	xinc;
	double	yinc;
	double	step;
	int	i;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;

	if (fabs(dx) > fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);

	xinc = dx / step;
	yinc = dy / step;
	i = 0;
	while (i <= step)
	{
		put_pixel(vars, p1.x + 500, p1.y + 500, 0x00FFFFFF);
		p1.x += xinc;
		p1.y += yinc;
		i++;
	}
}

void	draw(t_map *map, t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width - 1)
		{
			dda(vars, map->table[i][j], map->table[i][j + 1]);
		}
	}
	i = -1;
	while (++i < map->height - 1)
	{
		j = -1;
		while (++j < map->width)
		{
			dda(vars, map->table[i][j], map->table[i + 1][j]);
		}
	}
}
