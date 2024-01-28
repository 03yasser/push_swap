/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 02:15:21 by yboutsli          #+#    #+#             */
/*   Updated: 2024/01/27 21:38:21 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node **a)
{
	t_stack_node	*tmp;

	if (!(*a) || !(*a) -> next)
		return ;
	tmp = (*a) -> next ;
	(*a) -> next = tmp -> next;
	tmp -> next = *a;
	(*a) = tmp;
	write(1,"sa\n",3);
}

void	sb(t_stack_node **b)
{
	t_stack_node	*tmp;

	if (!(*b) || !(*b) -> next)
		return ;
	tmp = (*b) -> next ;
	(*b) -> next = tmp -> next;
	tmp -> next = *b;
	(*b) = tmp;
	write(1,"sb\n",3);
}
void ss(t_stack_node **a, t_stack_node **b)
{
	sa(a);
	sb(b);
	write(1,"ss\n",3);
}
void pa(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*tmp;

	if (*b == NULL)
		return ;
	tmp = *b;
	(*b) = (*b) -> next;
	tmp -> next = NULL;
	ft_lstadd_front(a,tmp);
	write(1,"pa\n",3);
}
void pb(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*tmp;

	if (*a == NULL)
		return ;
	tmp = *a;
	(*a) = (*a) -> next;
	tmp -> next = NULL;
	ft_lstadd_front(b,tmp);
	write(1,"pb\n",3);
}

void ra(t_stack_node **a)
{
	t_stack_node *tmp;
	t_stack_node *last;
	
	if ((*a) -> next != NULL)
	{
		tmp = *a;
		(*a) = (*a) -> next;
		tmp  -> next = NULL;
		last = ft_lstlast(*a);
		last -> next = tmp;
		write(1,"ra\n",3);
	}
}

void	rb(t_stack_node **b)
{
	t_stack_node *tmp;
	t_stack_node *last;
	
	if ((*b) -> next != NULL)
	{
		tmp = *b;
		(*b) = (*b) -> next;
		tmp  -> next = NULL;
		last = ft_lstlast(*b);
		last -> next = tmp;
		write(1,"rb\n",3);
	}
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *tmp;
	t_stack_node *last;

	if ((*a) -> next != NULL)
	{
		tmp = *a;
		(*a) = (*a) -> next;
		tmp  -> next = NULL;
		last = ft_lstlast(*a);
		last -> next = tmp;
	}
	if ((*b) -> next != NULL)
	{
		tmp = *b;
		(*b) = (*b) -> next;
		tmp  -> next = NULL;
		last = ft_lstlast(*b);
		last -> next = tmp;
	}
	write(1,"rr\n",3);
}

void	rra(t_stack_node **a)
{
	t_stack_node *tmp;
	
	if (!(*a) || !(*a) -> next)
		return ;
	tmp = *a;
	while (tmp -> next -> next)
		tmp = tmp -> next;
	ft_lstadd_front(a,tmp -> next);
	tmp -> next = NULL;
	write(1,"rra\n",4);
}

void	rrb(t_stack_node **b)
{
	t_stack_node *tmp;
	
	if (!(*b) || !(*b) -> next)
		return ;
	tmp = *b;
	while (tmp -> next -> next)
		tmp = tmp -> next;
	ft_lstadd_front(b,tmp -> next);
	tmp -> next = NULL;
	write(1,"rrb\n",4);
}

void rrr(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *tmp;
	
	if (!(*a) || !(*a) -> next)
		return ;
	tmp = *a;
	while (tmp -> next -> next)
		tmp = tmp -> next;
	ft_lstadd_front(a,tmp -> next);
	tmp -> next = NULL;
	if (!(*b) || !(*b) -> next)
		return ;
	tmp = *b;
	while (tmp -> next -> next)
		tmp = tmp -> next;
	ft_lstadd_front(b,tmp -> next);
	tmp -> next = NULL;
	write(1, "rrr\n", 4);
}
