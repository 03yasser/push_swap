/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:04:08 by yboutsli          #+#    #+#             */
/*   Updated: 2024/01/29 16:37:46 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstlast(t_node *lst)
{
	t_node	*p;

	if (!lst)
		return (NULL);
	p = lst;
	while (p -> next)
		p = p -> next;
	return (p);
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*p;

	p = NULL;
	if (!lst || !new)
		return ;
	if (! *lst)
		*lst = new;
	else
	{
		p = ft_lstlast(*lst);
		p -> next = new;
	}
}

t_node	*ft_lstnew(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

void	ft_lstclear(t_node **lst)
{
	t_node	*p;
	t_node	*next;

	if (!lst)
		return ;
	p = *lst;
	while (p)
	{
		next = p -> next;
		free(p);
		p = next;
	}
	*lst = NULL;
}

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (!new)
		return ;
	new -> next = *lst;
	*lst = new;
}

int lst_len(t_node	*lst)
{
	int				i;
	t_node	*current;

	i = 0;
	current = lst;
	while (current)
	{
		i++;
		current = current -> next;
	}
	return (i);
}

int lst_max(t_node	*lst)
{
	int				max;
	t_node	*current;

	max = INT_MIN;
	current = lst;
	while (current)
	{
		if (current -> value > max)
			max = current -> value;
		current = current -> next;
	}
	return (max);
}
