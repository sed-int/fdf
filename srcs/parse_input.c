/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:55:13 by hcho2             #+#    #+#             */
/*   Updated: 2023/06/29 20:35:35 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strchr_idx(const char *s, char c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*p;

	p = b;
	while (n--)
		*p++ = (unsigned char)c;
	return (b);
}

int	is_space(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

void	get_width(t_map *map)
{
	int		i;
	int		w;

	i = 0;
	w = 0;
	while (map->line[i])
	{
		while (map->line[i] && !is_space(map->line[i]))
			i++;
		if (map->line[i] && is_space(map->line[i]))
			w++;
		while (map->line[i] && is_space(map->line[i]))
			i++;
	}
	if (map->width == 0)
		map->width = w;
// 	else if (map->width != w)
// 		exit(1);
}

void	parse_map(char *filename, t_map *map)
{
	int		fd;
	char	**tmp;
	char	**tmp2;
	int		i;
	int		j;

	fd = open(filename, O_RDONLY);
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
	fd = open(filename, O_RDONLY);
	printf("--%d--\n", map->height);
	printf("--%lu--\n", sizeof(t_point *) * map->height);
	map->table = malloc(sizeof(t_point *) * map->height);
	i = -1;
	while (++i < map->height)
	{
		map->table[i] = malloc(sizeof(t_point) * map->width);
		tmp = ft_split(get_next_line(fd), ' ');
		j = -1;
		while (++j < map->width - 1)
		{
			map->table[i][j].x = j;
			map->table[i][j].y = i;
			map->table[i][j].z = ft_atoi(tmp[j]);
			map->table[i][j].color = 0x00FFFFFF;
			if (ft_strchr_idx(tmp[j], ',') != -1)
			{
				tmp2 = ft_split(tmp[j], ',');
				map->table[i][j].color = ft_htoi(tmp2[1]);
				// printf("parse_map, color dec: %d\n", map->table[i][j].color);
				// printf("parse_map, color hex: %s\n", tmp2[1]);
				ft_free_split(tmp2);
			}
		}
		// ft_free_split(tmp);
	}
	close(fd);
}
