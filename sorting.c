/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c c)                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:27:19 by yboutsli          #+#    #+#             */
/*   Updated: 2024/01/24 18:47:31 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void two_func(void f1(t_stack_node **), void f2(t_stack_node **), t_stack_node **a)
{
	f1(a);
	f2(a);
}

int	is_sorted(t_stack_node	*a)
{
	t_stack_node	*current;
	int				i;

	i = 0;
	current = a;
	while (current)
	{
		if (current -> s_index != i)
			return (0);
		current = current -> next;
		i++;
	}
	return(1);
}

void sort3(t_stack_node **tmp)
{
	int	a;
	int	b;
	int	c;

	a = (*tmp)->value;
	b = (*tmp)->next->value;
	if ((*tmp)->next->next != NULL)
		c = (*tmp)->next->next -> value;
	if ((*tmp)->next->next == NULL && a > b)
		sa(tmp);
	else if (a > b && b < c && a < c)
		sa(tmp);
	else if (a > b && b > c && a > c)
		two_func(sa,rra, tmp);
	else if (a > b && b < c && a > c) 
		ra(tmp);
	else if (a < b && b > c && a < c) 
		two_func(sa, ra, tmp);
	else if (a < b && b > c && a > c)
		rra(tmp);
}

void sort5(t_stack_node **a, t_stack_node **b)
{
	while (lst_len(*a) > 3)
	{
		if ((*a) -> s_index == 1 || (*a) -> s_index == 0)
			pb(a, b);
		else
			ra(a);
	}
	if ((*b) -> s_index < (*b) -> next -> s_index)
		sb(b);
	sort3(a);
	pa(a, b);
	pa(a, b);
}

