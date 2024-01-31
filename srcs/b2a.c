/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b2a.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:28:37 by yboutsli          #+#    #+#             */
/*   Updated: 2024/01/31 15:36:11 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_execute1(t_node **a, t_node **b, t_node **current)
{
	while ((*current)->ra > 0 && (*current)->rb > 0)
	{
		(*current)->ra--;
		(*current)->rb--;
		rr(a, b);
	}
	while ((*current)->rra > 0 && (*current)->rrb > 0)
	{
		(*current)->rra--;
		(*current)->rrb--;
		rrr(a, b);
	}
	while ((*current) && (*current)->ra > 0)
	{
		(*current)->ra--;
		ra(a);
	}
}

static void	move_execute(t_node **a, t_node **b, int min)
{
	t_node	*current;

	current = *b;
	while (current && current->moves != min)
		current = current->next;
	move_execute1(a, b, &current);
	while (current && current->rb > 0)
	{
		current->rb--;
		rb(b);
	}
	while (current && current->rra > 0)
	{
		current->rra--;
		rra(a);
	}
	while (current && current->rrb > 0)
	{
		current->rrb--;
		rrb(b);
	}
	pa(a, b);
}

static int	cal_moves(t_node **a, t_node **b, int a_index, int b_index)
{
	t_node			*current;
	int				a_move;
	int				b_move;

	current = *a;
	a_move = 0;
	cal_moves1(&current, a_index, &a_move);
	current = *b;
	b_move = 0;
	cal_moves1(&current, b_index, &b_move);
	if (a_move > lst_len(*a) / 2)
	{
		a_move = lst_len(*a) - a_move;
		current->rra = a_move;
	}
	else
		current->ra = a_move;
	if (b_move > lst_len(*b) / 2)
	{
		b_move = lst_len(*b) - b_move;
		current->rrb = b_move;
	}
	else
		current->rb = b_move;
	return (current->pa = 1, moves_sum(current));
}

static int	a_index_best(t_node **a, int index)
{
	t_node	*current;
	int		min_index;

	min_index = INT_MAX;
	current = *a;
	while (current)
	{
		if (current->s_index > index && current->s_index < min_index)
			min_index = current->s_index;
		current = current->next;
	}
	return (min_index);
}

void	b_2_a(t_node **a, t_node **b)
{
	t_node			*current;
	int				a_index;
	int				min_move;

	current = *b;
	sort3(a);
	while (current)
	{
		operation_init(&current);
		a_index = a_index_best(a, current->s_index);
		current->moves = cal_moves(a, b, a_index, current->s_index);
		current = current->next;
	}
	min_move = min_moves(b);
	move_execute(a, b, min_move);
	if (lst_len(*b) > 0)
		b_2_a(a, b);
	while (!is_sorted(*a))
	{
		if (lst_len(*a) / 2 < (*a)->s_index)
			ra(a);
		else
			rra(a);
	}
}
