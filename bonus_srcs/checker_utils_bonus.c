/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:24:28 by yboutsli          #+#    #+#             */
/*   Updated: 2024/02/04 22:08:49 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	is_integer(long nb)
{
	if (nb > INT_MAX || nb < INT_MIN)
		return (0);
	return (1);
}

static int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9' ))
		return (1);
	else
		return (0);
}

int	arg_is_numbers(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		if (!argv[i][0] || !nb_exist(argv[i]))
			return (0);
		j = -1;
		while (argv[i][++j])
		{
			while (argv[i][j] == ' ' && argv[i][j + 1])
				j++;
			if (argv[i][j] == '+' || argv[i][j] == '-')
			{
				if (j > 0 && argv[i][j - 1] != ' ')
					return (0);
				if (!ft_isdigit(argv[i][j++ + 1]))
					return (0);
			}
			if (!ft_isdigit(argv[i][j]))
				return (0);
		}
	}
	return (1);
}

long	ft_atoi(const char *str)
{
	int		i;
	long	n;
	int		sign;

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
	while (str[i] >= 48 && str[i] <= 57 && n < (long)INT_MAX + 1)
	{
		n = n * 10 + str[i] - 48;
		i++;
	}
	return ((n) * sign);
}

int	stack_fill(char **argv, t_node **a)
{
	int		i;
	int		j;
	char	**new;
	long	tmp;

	i = 0;
	while (argv[++i])
	{
		new = ft_split(argv[i], ' ');
		j = -1;
		while (new[++j])
		{
			tmp = ft_atoi(new[j]);
			if (!is_integer(tmp) || !exist_in_lst(a, tmp))
				return (0);
			ft_lstadd_back(a, ft_lstnew(tmp));
			free(new[j]);
		}
		free(new);
	}
	return (1);
}
