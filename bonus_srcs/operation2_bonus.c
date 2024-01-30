/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:19:05 by yboutsli          #+#    #+#             */
/*   Updated: 2024/01/30 18:30:39 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rb(t_node **b)
{
	t_node	*tmp;
	t_node	*last;

	if ((*b)->next != NULL)
	{
		tmp = *b;
		(*b) = (*b)->next;
		tmp->next = NULL;
		last = ft_lstlast(*b);
		last->next = tmp;
	}
}

void	rr(t_node **a, t_node **b)
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
	if ((*b)->next != NULL)
	{
		tmp = *b;
		(*b) = (*b)->next;
		tmp->next = NULL;
		last = ft_lstlast(*b);
		last->next = tmp;
	}
}

void	rra(t_node **a)
{
	t_node	*tmp;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	ft_lstadd_front(a, tmp->next);
	tmp->next = NULL;
}

void	rrb(t_node **b)
{
	t_node	*tmp;

	if (!(*b) || !(*b)->next)
		return ;
	tmp = *b;
	while (tmp->next->next)
		tmp = tmp->next;
	ft_lstadd_front(b, tmp->next);
	tmp->next = NULL;
}

void	rrr(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	ft_lstadd_front(a, tmp->next);
	tmp->next = NULL;
	if (!(*b) || !(*b)->next)
		return ;
	tmp = *b;
	while (tmp->next->next)
		tmp = tmp->next;
	ft_lstadd_front(b, tmp->next);
	tmp->next = NULL;
}
