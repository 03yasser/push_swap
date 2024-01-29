/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:58:37 by yboutsli          #+#    #+#             */
/*   Updated: 2024/01/29 21:00:01 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	two_func(void f1(t_node **), void f2(t_node **), t_node **a)
{
	f1(a);
	f2(a);
}

int	is_sorted(t_node	*a)
{
	t_node	*current;
	int		i;

	i = 0;
	current = a;
	while (current)
	{
		if (current -> s_index != i)
			return (0);
		current = current -> next;
		i++;
	}
	return (1);
}

void	sort3(t_node **tmp)
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
		two_func(sa, rra, tmp);
	else if (a > b && b < c && a > c)
		ra(tmp);
	else if (a < b && b > c && a < c)
		two_func(sa, ra, tmp);
	else if (a < b && b > c && a > c)
		rra(tmp);
}
