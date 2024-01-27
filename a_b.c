/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_b.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:58:57 by yboutsli          #+#    #+#             */
/*   Updated: 2024/01/26 23:37:20 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int mini_rb(int *i, t_stack_node **b)
{
	if (*i == 1)
	{
		rb(b);
		*i = 0;
		return (1);
	}
	return (0);
}

static void	a_2_b1(int part, int *i,t_stack_node **a, t_stack_node **b)
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
			mini_rb(i,b);
			pb(a, b);
			count--;
		}
		else if ((*a) -> s_index < part + lenb)
		{
			mini_rb(i,b);
			pb(a, b);
			*i = 1;
			count--;
		}
		else if ((*a)-> s_index >= part + lenb)
			if (mini_rb(i, b) == 0)
				ra(a);
	}
}

void	a_2_b(t_stack_node **a, t_stack_node **b)
{
	int	part;
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (lst_len(*a) > 3)
	{
		part = (lst_len(*a) / 4);
		count = part;
		a_2_b1(part, &i, a, b);
	}
	if (i == 1)
		ra(a);
	if (lst_len(*a) > 3)
		a_2_b(a, b);
}

int	max_s_index(t_stack_node **tmp)
{
	t_stack_node	*current;
	int				max;

	max = INT_MIN;
	current = *tmp;
	while (current)
	{
		if (current -> s_index > max)
			max = current -> s_index;
		current = current -> next;
	}
	return (max);
}

static void	b_2_a1(int i, int lenb, t_stack_node **a, t_stack_node **b)
{
	if (--i <= lenb / 2)
	{
		while (i-- > 0)
			rb(b);
		pa(a, b);
	}
	else if (i > lenb / 2)
	{
		while (i++ < lenb)
			rrb(b);
		pa(a, b);
	}
}

void	b_2_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*current;
	int				i;
	int				lenb;

	while (*b != NULL)
	{
		while ((*a)-> s_index - 1 == ft_lstlast(*a)-> s_index)
			rra(a);
		while ((ft_lstlast(*a)-> s_index == max_s_index(a)
				|| ft_lstlast(*a)-> s_index < (*b)-> s_index)
			&& (*b)-> s_index != (*a)-> s_index - 1)
		{
			pa(a, b);
			ra(a);
		}
		lenb = lst_len(*b);
		i = 1;
		current = *b;
		while (current && current -> s_index != (*a)-> s_index - 1 && i++)
			current = current -> next;
		b_2_a1(i, lenb, a, b);
	}
	while (!is_sorted(*a))
		rra(a);
}
