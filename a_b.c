/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_b.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:58:57 by yboutsli          #+#    #+#             */
/*   Updated: 2024/01/28 17:55:40 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void	a_2_b1(int part, t_stack_node **a, t_stack_node **b)
{
	int lenb;
	int count;

	count = part;
	lenb = lst_len(*b);
	while (count > 0)
	{
		if (lst_len(*a) == 2)
			return ;
		if ((*a)-> s_index <= (part / 2) + lenb)
		{
			pb(a, b);
			count--;
		}
		else if ((*a) -> s_index < part + lenb)
		{
			pb(a, b);
			rb(b);
			count--;
		}
		else if ((*a)-> s_index >= part + lenb)
			ra(a);
	}
}

void	a_2_b(t_stack_node **a, t_stack_node **b)
{
	int	part;

	if (lst_len(*a) > 3)
	{
		part = (lst_len(*a) / 4);
		a_2_b1(part, a, b);
	}
	if (lst_len(*a) > 3)
		a_2_b(a, b);
}

static void	operation_init(t_stack_node **tmp)
{
	if (tmp == NULL)
		return ;
	(*tmp) -> ra = 0;
	(*tmp) -> rb = 0;
	(*tmp) -> rra = 0;
	(*tmp) -> rrb = 0;
	(*tmp) -> pa = 0;
}
 

int	moves_sum(t_stack_node *c)
{
	return (c -> ra + c -> rb + c -> rra + c -> rrb + c -> pa);
}

static void move_execute1(t_stack_node **a, t_stack_node **b, t_stack_node **current)
{
	while ((*current) -> ra > 0 && (*current)  -> rb > 0)
	{
		(*current)  -> ra--;
		(*current)  -> rb--;
		rr(a, b);
	}
	while ((*current)  -> rra > 0 && (*current)  -> rrb > 0)
	{
		(*current)  -> rra--;
		(*current)  -> rrb--;
		rrr(a, b);
	}
	while ((*current)  && (*current)  -> ra > 0)
	{
		(*current)  -> ra--;
		ra(a);
	}
}

static void	move_execute(t_stack_node **a, t_stack_node **b, int min)
{
	t_stack_node	*current;

	current = *b;
	while (current && current -> moves != min)
		current = current -> next;
	move_execute1(a, b, &current);
	while (current && current -> rb > 0)
	{
		current -> rb--;
		rb(b);
	}
	while (current && current -> rra > 0)
	{
		current -> rra--;
		rra(a);
	}
	while (current && current -> rrb > 0)
	{
		current -> rrb--;
		rrb(b);
	}
	pa(a, b);
}
static void cal_moves1(t_stack_node **current, int index, int *nb_moves)
{
	while((*current) && (*current) -> s_index != index)
	{
		(*nb_moves)++;
		(*current) = (*current) -> next;
	}
}
int	cal_moves(t_stack_node **a, t_stack_node **b, int a_index, int b_index)
{
	t_stack_node	*current;
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
		current -> rra = a_move;
	}
	else
		current -> ra = a_move;
	if (b_move > lst_len(*b) / 2)
	{
		b_move = lst_len(*b) - b_move;
		current -> rrb = b_move;
	}
	else
		current -> rb = b_move;
	return (current -> pa = 1, moves_sum(current));
}

int min_moves(t_stack_node **b)
{
	t_stack_node *current;
	int min;

	min = INT_MAX;
	current = *b;
	while (current)
	{
		if (current -> moves < min)
			min = current -> moves;
		current = current -> next;
	}
	return (min);
}

static  int a_index_best(t_stack_node **a, int index)
{
	t_stack_node	*current;
	int				min_index;

	min_index = INT_MAX;
	current = *a;
	while (current)
	{
		if (current -> s_index > index && current -> s_index < min_index)
			min_index = current -> s_index;
		current = current -> next;
	}
	return (min_index);
}

void	b_2_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*current;
	int				a_index;
	int 			min_move;

	current = *b;
	sort3(a);
	while (current)
	{
		operation_init(&current);
		a_index = a_index_best(a,current -> s_index);
		current -> moves = cal_moves(a, b, a_index, current -> s_index);
		current = current -> next;
	}
	min_move = min_moves(b);
	move_execute(a, b, min_move);
	if (lst_len(*b) > 0)
		b_2_a(a, b);
}
