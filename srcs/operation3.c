/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:35:00 by yboutsli          #+#    #+#             */
/*   Updated: 2024/01/31 15:35:34 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a)
{
	t_node	*tmp;
	t_node	*last;

	if ((*a)->next != NULL)
	{
		tmp = *a;
		(*a) = (*a)->next;
		tmp->next = NULL;
		last = ft_lstlast(*a);
		last->next = tmp;
		write(1, "ra\n", 3);
	}
}
