/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:19:49 by hcho2             #+#    #+#             */
/*   Updated: 2023/07/12 15:37:51 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# define WIDTH			1920
# define HEIGHT			1080
# define WHITE			0x00FFFFFF

# define LEFT			123
# define RIGHT			124
# define DOWN			125
# define UP				126
# define MINUS			27
# define PLUS			24
# define SPACE			49
# define ESCAPE			53

# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	long	color;
}	t_point;

typedef struct s_map
{
	int		height;
	int		width;
	char	*line;
	t_point	**table;
	t_point	**input;
}	t_map;

typedef struct s_dvar
{
	double	dx;
	double	dy;
	double	xinc;
	double	yinc;
	double	step;
}	t_dvar;

typedef struct s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	char	*line;
	int		bpp;
	int		line_length;
	int		endian;
	double	zoom;
	int		x_offset;
	int		y_offset;
	t_map	*map;
}	t_env;

char	**ft_split(char const *str, char c);
char	**ft_free_split(char **list);
int		ft_atoi(const char *str);
void	parse_map(char *filename, t_map *map);
void	scaling(t_map *map);
void	draw(t_map *map, t_env *env);
int		ft_strchr_idx(const char *s, char c);
int		ft_atoh(char *str);
int		key_press(int keycode, t_env *env);
void	mapcpy(t_point	**arr1, t_point	**arr2, t_map *map);
void	*ft_memset(void *b, int c, size_t n);
int		ft_strchr_idx(const char *s, char c);
int		is_space(char c);
void	ft_putstr_fd(char *str, int fd);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_error(char *str);
void	ft_isometric(t_map *map);

#endif
