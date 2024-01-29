/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:29:41 by yboutsli          #+#    #+#             */
/*   Updated: 2024/01/29 16:44:44 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	sign;

	i = 0;
	sign = 1;
	n = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		n = n * 10 + str[i] - 48;
		i++;
	}
	return ((n) * sign);
}


int	is_integer(const char *str)
{
	long		nb;
	int			i;
	int			sign;
	int			len;

	len = 0;
	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '0')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] >= 48 && str[i] <= 57 )
	{
		nb = nb * 10 + str[i++] - 48;
		len++;
	}
	nb = nb * sign;
	if (len > 12 || nb > INT_MAX || nb < INT_MIN)
		return (0);
	return (1);
}
