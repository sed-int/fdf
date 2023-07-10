/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:50:34 by hcho2             #+#    #+#             */
/*   Updated: 2023/07/10 21:28:20 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_trp(long color)
{
	return (color >> 24);
}

int	get_red(long color)
{
	unsigned int	t;

	t = color >> 24;
	return (color >> 16 ^ t << 8);
}

int	get_green(long color)
{
	unsigned int	tr;

	tr = color >> 16;
	return (color >> 8 ^ tr << 8);
}

int	get_blue(long color)
{
	unsigned int	trg;

	trg = color >> 8;
	return (color ^ trg << 8);
}

void	get_color(t_point *p1, t_point *p2, int dx, int dy)
{
	int	t;
	int	r;
	int	g;
	int	b;

	if
	t = get_blue(p1.color) +
}

if (cur.color == f.color)
		return (f.color);
	if (wdt_hgt[0] > wdt_hgt[1])
		ratio = get_ratio(cur.x, s.x, f.x);
	else
		ratio = get_ratio(cur.y, s.y, f.y);
	red = ft_lerp(get_r(s.color), get_r(f.color), ratio);
	green = ft_lerp(get_g(s.color), get_g(f.color), ratio);
	blue = ft_lerp(get_b(s.color), get_b(f.color), ratio);
	color = create_trgb(0, red, green, blue);
	return (color);
