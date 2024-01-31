/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 02:15:21 by yboutsli          #+#    #+#             */
/*   Updated: 2024/01/31 15:37:52 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
	}
}
