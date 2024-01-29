/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a2b.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:58:57 by yboutsli          #+#    #+#             */
/*   Updated: 2024/01/29 16:32:54 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	a_2_b1(int part, t_node **a, t_node **b)
{
	int	lenb;
	int	count;

	count = part;
	lenb = lst_len(*b);
	while (count > 0)
	{
		if (lst_len(*a) == 2)
			return ;
		if ((*a)->s_index <= (part / 2) + lenb)
		{
			pb(a, b);
			count--;
		}
		else if ((*a)->s_index < part + lenb)
		{
			pb(a, b);
			rb(b);
			count--;
		}
		else if ((*a)->s_index >= part + lenb)
			ra(a);
	}
}

void	a_2_b(t_node **a, t_node **b)
{
	int	part;

	if (lst_len(*a) > 3)
	{
		part = (lst_len(*a) / 2);
		a_2_b1(part, a, b);
	}
	if (lst_len(*a) > 3)
		a_2_b(a, b);
}
