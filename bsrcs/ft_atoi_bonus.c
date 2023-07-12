/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:57:54 by hcho2             #+#    #+#             */
/*   Updated: 2023/07/12 15:26:43 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	ft_atoi(const char *str)
{
	long long	ret;
	int			sign;
	int			digit_check;
	int			i;

	i = 0;
	ret = 0;
	digit_check = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + str[i++] - '0';
		if (ret > 0)
			digit_check++;
	}
	if ((str[i] != '\0' && str[i] != '\n' && str[i] != ',')
		|| (digit_check > 8 || ret > 1000000))
		ft_error("Invalid value.");
	return ((int)(ret * sign));
}

void	to_lower(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
}

int	ft_atoh(char *str)
{
	char	*hex;
	int		i;
	int		ret;

	hex = "0123456789abcdef";
	to_lower(str);
	ret = 0;
	if (!ft_strncmp(str, "0x", 2))
	{
		i = 2;
		while (ft_strchr_idx(hex, str[i]) != -1)
		{
			ret = ret * 16 + ft_strchr_idx(hex, str[i]);
			i++;
		}
		if ((str[i] == '\0' || str[i] == '\n') && i <= 10 && i % 2 == 0)
			return (ret);
		else
			ft_error("Invalid value.");
	}
	ft_error("Invalid value.");
	return (0);
}
