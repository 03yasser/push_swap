/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:24:28 by yboutsli          #+#    #+#             */
/*   Updated: 2024/01/31 15:42:23 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

int	exist_in_lst(t_node **a, int nb)
{
	t_node	*current;

	current = *a;
	while (current)
	{
		if (current -> value == nb)
			return (0);
		current = current -> next;
	}
	return (1);
}
