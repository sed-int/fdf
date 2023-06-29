/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 50023/06/28 14:58:00 by hcho2             #+#    #+#             */
/*   Updated: 50023/06/29 19:01:02 by hcho2            ###   ########.fr       */
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

int	oob(int x, int y)
{
	return (x > WINDOW_WIDTH || x < 0 || y > WINDOW_HEIGHT || y < 0);
}

void	dda(t_vars *vars, t_point p1, t_point p2)
{
	t_dvar	line;
	int		i;

	line.dx = p2.x - p1.x;
	line.dy = p2.y - p1.y;

	if (fabs(line.dx) > fabs(line.dy))
		line.step = fabs(line.dx);
	else
		line.step = fabs(line.dy);

	line.xinc = line.dx / line.step;
	line.yinc = line.dy / line.step;
	i = 0;
	while (i <= line.step)
	{
		if (!oob(p1.x + 500, p1.y + 500))
			put_pixel(vars, p1.x + 500, p1.y + 500, p1.color);
		p1.x += line.xinc;
		p1.y += line.yinc;
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
