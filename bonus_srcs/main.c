/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:43:20 by yboutsli          #+#    #+#             */
/*   Updated: 2024/01/31 15:55:38 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	is_sorted(t_node *a)
{
	t_node	*current;

	current = a;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	*str;
	char	**operations;
	int		i;
	t_node	*a;
	t_node	*b;

	b = NULL;
	parcing_check(argc, argv, &a);
	str = operation_str();
	operations = ft_split(str, '\n');
	free(str);
	i = 0;
	while (operations[i])
	{
		execute(operations[i], &a, &b);
		free(operations[i]);
		if (is_sorted(a) && !b)
		{
			write(1, "OK\n", 3);
			exit(1);
		}
		i++;
	}
	write(1, "KO\n", 3);
	exit(0);
}
