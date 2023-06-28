/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:25:52 by hcho2             #+#    #+#             */
/*   Updated: 2023/06/28 20:46:01 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scaling(t_map *map)
{
	int	i;
	int	j;
	int	ratio;

	ratio = WINDOW_HEIGHT / map->height * 4 / 10;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			map->table[i][j].x *= ratio;
			map->table[i][j].y *= ratio;
			map->table[i][j].z *= ratio;
		}
	}
}