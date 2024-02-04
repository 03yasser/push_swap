/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:00:43 by yboutsli          #+#    #+#             */
/*   Updated: 2024/02/04 22:06:45 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_node **tmp)
{
	t_node	*current;

	current = *tmp;
	while (current)
	{
		current -> s_index = -1;
		current -> moves = -1;
		current = current -> next;
	}
}

void	sort_s_index(t_node **tmp)
{
	t_node			*current;
	int				i;
	int				min;
	int				len;

	indexing(tmp);
	len = lst_len(*tmp);
	i = 0;
	while (len)
	{
		min = INT_MAX;
		current = *tmp;
		while (current)
		{
			if (current -> value < min && current -> s_index < 0)
				min = current -> value;
			current = current -> next;
		}
		current = *tmp;
		while ((current) && current -> value != min)
			current = current -> next;
		current -> s_index = i++;
		len--;
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	if (argc == 1)
		exit(1);
	if (!argv[1][0] || !arg_is_numbers(argv)
		|| !stack_fill(argv, &a))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	sort_s_index(&a);
	if (is_sorted(a))
		exit(EXIT_SUCCESS);
	if (lst_len(a) <= 3)
		sort3(&a);
	else
	{
		a_2_b(&a, &b);
		b_2_a(&a, &b);
	}
	if (is_sorted(a))
		exit(EXIT_SUCCESS);
}
