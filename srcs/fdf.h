/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:19:49 by hcho2             #+#    #+#             */
/*   Updated: 2023/06/29 18:10:27 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	char	*line;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_vars;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_point;

typedef struct s_map
{
	int		height;
	int		width;
	char	*line;
	t_point	**table;
}	t_map;

typedef struct s_dvar
{
	double	dx;
	double	dy;
	double	xinc;
	double	yinc;
	double	step;
} t_dvar;


char	**ft_split(char const *str, char c);
char	**ft_free_split(char **list);
int		ft_atoi(const char *str);
void	parse_map(char *filename, t_map *map);
void	scaling(t_map *map);
void	ft_isometric(t_map *map);
void	scaling(t_map *map);
void	draw(t_map *map, t_vars *vars);
int		ft_strchr_idx(const char *s, char c);
int		ft_htoi(char *str);
void	*ft_memset(void *b, int c, size_t n);

#endif
