/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b2a1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:32:16 by yboutsli          #+#    #+#             */
/*   Updated: 2024/01/29 16:35:06 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_moves(t_node **b)
{
	t_node	*current;
	int		min;

	min = INT_MAX;
	current = *b;
	while (current)
	{
		if (current->moves < min)
			min = current->moves;
		current = current->next;
	}
	return (min);
}

void	operation_init(t_node **tmp)
{
	if (tmp == NULL)
		return ;
	(*tmp)->ra = 0;
	(*tmp)->rb = 0;
	(*tmp)->rra = 0;
	(*tmp)->rrb = 0;
	(*tmp)->pa = 0;
}

int	moves_sum(t_node *c)
{
	return (c->ra + c->rb + c->rra + c->rrb + c->pa);
}

void	cal_moves1(t_node **current, int index, int *nb_moves)
{
	while ((*current) && (*current)->s_index != index)
	{
		(*nb_moves)++;
		(*current) = (*current)->next;
	}
}
