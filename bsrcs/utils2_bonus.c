/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:42:29 by hcho2             #+#    #+#             */
/*   Updated: 2023/07/12 15:27:03 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		i++;
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s3;
	unsigned char	*s4;
	size_t			i;

	i = 0;
	s3 = (unsigned char *)s1;
	s4 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((s3[i] || s4[i]) && i < n)
	{
		if (s3[i] - s4[i])
			return (s3[i] - s4[i]);
		i++;
	}
	return (0);
}
