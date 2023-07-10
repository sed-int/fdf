/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:35:46 by hcho2             #+#    #+#             */
/*   Updated: 2023/07/10 19:11:33 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(fd, str, i);
}

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*p;

	p = b;
	while (n--)
		*p++ = (unsigned char)c;
	return (b);
}

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

int	is_space(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}
