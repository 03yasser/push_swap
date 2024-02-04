/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:09:59 by yboutsli          #+#    #+#             */
/*   Updated: 2024/02/03 10:11:30 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1)
		return (1);
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (s1[i] != s2[i])
		return (0);
	return (1);
}

int	operation_check(char *str)
{
	if (ft_strcmp(str, "sa\n") || ft_strcmp(str, "sb\n")
		|| ft_strcmp(str, "ss\n") || ft_strcmp(str, "pa\n")
		|| ft_strcmp(str, "pb\n") || ft_strcmp(str, "ra\n")
		|| ft_strcmp(str, "rb\n") || ft_strcmp(str, "rr\n")
		|| ft_strcmp(str, "rra\n") || ft_strcmp(str, "rrb\n")
		|| ft_strcmp(str, "rrr\n"))
		return (1);
	else
		return (0);
}

void	parcing_check(int argc, char **argv, t_node **a)
{
	if (argc == 1)
		exit(1);
	if (!argv[1][0] || !arg_is_numbers(argv)
		|| !stack_fill(argv, a))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

char	*operation_str(void)
{
	char	*str;
	char	*operations;
	char	*tmp;

	operations = ft_strdup("");
	str = get_next_line(0);
	while (str)
	{
		if (!operation_check(str))
		{
			free(str);
			free(operations);
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		tmp = operations;
		operations = ft_strjoin(tmp, str);
		free(tmp);
		free(str);
		str = get_next_line(0);
	}
	free(str);
	return (operations);
}

void	execute(char *str, t_node **a, t_node **b)
{
	if (ft_strcmp(str, "sa"))
		sa(a);
	else if (ft_strcmp(str, "sb"))
		sb(b);
	else if (ft_strcmp(str, "ss"))
		ss(a, b);
	else if (ft_strcmp(str, "pa"))
		pa(a, b);
	else if (ft_strcmp(str, "pb"))
		pb(a, b);
	else if (ft_strcmp(str, "ra"))
		ra(a);
	else if (ft_strcmp(str, "rb"))
		rb(b);
	else if (ft_strcmp(str, "rr"))
		rr(a, b);
	else if (ft_strcmp(str, "rra"))
		rra(a);
	else if (ft_strcmp(str, "rrb"))
		rrb(b);
	else if (ft_strcmp(str, "rrr"))
		rrr(a, b);
}
