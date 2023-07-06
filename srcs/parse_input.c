/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:55:13 by hcho2             #+#    #+#             */
/*   Updated: 2023/07/06 17:18:42 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_width(t_map *map)
{
	int		i;
	int		w;

	i = 0;
	w = 0;
	while (map->line[i])
	{
		while (map->line[i] && is_space(map->line[i]))
			i++;
		if (map->line[i] && !is_space(map->line[i]))
			w++;
		while (map->line[i] && !is_space(map->line[i]))
			i++;
	}
	if (map->width == 0)
		map->width = w;
	else if (map->width != w)
	{
		exit(1);
	}
}

void	get_size(char *filename, t_map *map)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		perror(filename);
	ft_memset(map, 0, sizeof(t_map));
	map->line = get_next_line(fd);
	while (map->line)
	{
		map->height++;
		get_width(map);
		free(map->line);
		map->line = get_next_line(fd);
	}
	close(fd);
}

void	map_init(t_map *map)
{
	int	i;

	map->table = malloc(sizeof(t_point *) * map->height);
	map->input = malloc(sizeof(t_point *) * map->height);
	i = -1;
	while (++i < map->height)
	{
		map->table[i] = malloc(sizeof(t_point) * map->width);
		map->input[i] = malloc(sizeof(t_point) * map->width);
	}
	if (!map->table || !map->input)
	{
		perror("malloc error: ");
		exit(1);
	}
}

void	get_color(t_map *map, char *str, int i, int j)
{
	char	**tmp;

	map->table[i][j].color = WHITE;
	if (ft_strchr_idx(str, ',') != -1)
	{
		tmp = ft_split(str, ',');
		if (!tmp)
		{
			perror("split error: ");
			exit(1);
		}
		map->table[i][j].color = ft_atoh(tmp[1]);
		ft_free_split(tmp);
	}
}

void	parse_map(char *filename, t_map *map)
{
	char	**z_values;
	int		fd;
	int		i;
	int		j;

	get_size(filename, map);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		perror(filename);
	map_init(map);
	i = -1;
	while (++i < map->height)
	{
		z_values = ft_split(get_next_line(fd), ' ');
		if (!z_values)
		{
			perror("split error: ");
			exit(1);
		}
		j = -1;
		while (++j < map->width)
		{
			map->table[i][j].x = j;
			map->table[i][j].y = i;
			map->table[i][j].z = ft_atoi(z_values[j]);
			get_color(map, z_values[j], i, j);
		}
		ft_free_split(z_values);
	}
	mapcpy(map->input, map->table, map);
	close(fd);
}
