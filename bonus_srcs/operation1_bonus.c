/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation1_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 02:15:21 by yboutsli          #+#    #+#             */
/*   Updated: 2024/01/31 15:38:08 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	sa(t_node **a)
{
	t_node	*tmp;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = (*a)->next ;
	(*a)->next = tmp->next;
	tmp->next = *a;
	(*a) = tmp;
}

void	sb(t_node **b)
{
	t_node	*tmp;

	if (!(*b) || !(*b)->next)
		return ;
	tmp = (*b)->next ;
	(*b)->next = tmp->next;
	tmp->next = *b;
	(*b) = tmp;
}

void	ss(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = (*a)->next ;
	(*a)->next = tmp->next;
	tmp->next = *a;
	(*a) = tmp;
	if (!(*b) || !(*b)->next)
		return ;
	tmp = (*b)->next ;
	(*b)->next = tmp->next;
	tmp->next = *b;
	(*b) = tmp;
}

void	pa(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (*b == NULL)
		return ;
	tmp = *b;
	(*b) = (*b)->next;
	tmp->next = NULL;
	ft_lstadd_front(a, tmp);
}

void	pb(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (*a == NULL)
		return ;
	tmp = *a;
	(*a) = (*a)->next;
	tmp->next = NULL;
	ft_lstadd_front(b, tmp);
}
