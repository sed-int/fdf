/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:57:54 by hcho2             #+#    #+#             */
/*   Updated: 2023/06/29 20:00:46 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	ret;

	i = 0;
	ret = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		ret = ret * 10 + str[i++] - '0';
	if (str[i] == '\0' || str[i] == '\n' || str[i] == ',')
		return (sign * ret);
	else
	{
		printf("ft_atoi: %c\n", str[i]);
		exit(1);
	}
}

int	ft_atoh(char *str)
{
	char	*hex1;
	int		i;
	int		ret;

	hex1 = "0123456789abcdef";
	i = 0;
	while (str[i])
	{
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	ret = 0;
	if (!ft_strncmp(str, "0X", 2) || !ft_strncmp(str, "0x", 2))
	{
		i = 2;
		while (ft_strchr_idx(hex1, str[i]) != -1)
		{
			ret = ret * 16 + ft_strchr_idx(hex1, str[i]);
			i++;
		}
		if ((str[i] == '\0' || str[i] == '\n') && i <= 10 && i % 2 == 0)
			return (ret);
		else
		{
			exit(1);
		}
	}
	exit(1);
	return (0);
}
