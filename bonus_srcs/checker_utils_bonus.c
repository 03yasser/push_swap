/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:24:28 by yboutsli          #+#    #+#             */
/*   Updated: 2024/01/31 15:42:43 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = nb * 10 + str[i++] - 48;
		len++;
	}
	nb = nb * sign;
	if (len > 12 || nb > INT_MAX || nb < INT_MIN
		|| (str[i] != ' ' && str[i] != '\0'))
		return (0);
	return (1);
}

static int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9' ) || c == ' ')
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
		if (!argv[i][0])
			return (0);
		j = -1;
		while (argv[i][++j])
		{
			while (argv[i][j] == ' ' && argv[i][j + 1])
				j++;
			if (((argv[i][j] == '+' || argv[i][j] == '-')
				&& ft_isdigit(argv[i][j + 1])))
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (0);
			while (argv[i][j] == ' ' && argv[i][j + 1])
				j++;
			if (argv[i][j] == ' ' && !argv[i][j + 1])
				break ;
		}
	}
	return (1);
}

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

int	stack_fill(char **argv, t_node **a)
{
	int		i;
	int		j;
	char	**new;

	i = 0;
	while (argv[++i])
	{
		new = ft_split(argv[i], ' ');
		j = -1;
		while (new[++j])
		{
			if (!is_integer(new[j]) || !exist_in_lst(a, ft_atoi(new[j])))
				return (0);
			ft_lstadd_back(a, ft_lstnew(ft_atoi(new[j])));
			free(new[j]);
		}
		free(new);
	}
	return (1);
}
