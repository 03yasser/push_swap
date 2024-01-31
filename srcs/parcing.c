/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:46:02 by yboutsli          #+#    #+#             */
/*   Updated: 2024/01/31 22:58:08 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
static int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || c == ' ')
		return (1);
	else
		return (0);
}

static int	exist_in_lst(t_node **a, int nb)
{
	t_node	*current;

	current = *a;
	while (current)
	{
		if (current -> value == nb)
			return (0);
		current = current -> next;
	}
	return (1);
}
static int nb_exist(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (1);
		i++;
	}
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
				if (ft_isdigit(argv[i][j + 1]))
					j++;
				else
					return (0);
			}
			if (!ft_isdigit(argv[i][j]))
				return (0);
		}
	}
	return (1);
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
