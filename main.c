/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:00:43 by yboutsli          #+#    #+#             */
/*   Updated: 2024/01/28 17:22:51 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}


int	arg_is_numbers(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		if (!argv[i][0])
			return (0);
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] == ' ' && argv[i][j + 1])
				j++;
			if (argv[i][j])
				break ;
			if (((argv[i][j] == '+' || argv[i][j] == '-') && argv[i][j + 1]))
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
	}
	return (1);
}
int	exist_in_lst(t_stack_node **a, int nb)
{
	t_stack_node	*current;
	current = *a;
	while (current)
	{
		if (current -> value == nb)
			return (0);
		current = current -> next;
	}
	return (1);
}

int	stack_fill(char **argv, t_stack_node **a)
{
	int		i;
	int		j;
	char	**new;

	i = 0;
	while (argv[++i])
	{
		new = ft_split(argv[i], ' ');
		j = -1;
		while (new[++j])
		{
			if (ft_strlen(new[j]) > 19 || ft_atoi(new[j]) > INT_MAX
				|| ft_atoi(new[j]) < INT_MIN
				|| !exist_in_lst(a, ft_atoi(new[j])))
			{
				write(1, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			ft_lstadd_back(a, ft_lstnew(ft_atoi(new[j])));
			free(new[j]);
		}
		free(new);
	}
	return (1);
}

void	check(void)
{
	system("leaks push_swap");
}


void	indexing(t_stack_node **tmp)
{
	t_stack_node	*current;

	current = *tmp;
	while (current)
	{
		current -> s_index = -1;
		current -> moves = -1;
		current = current -> next;
	}
}
void swap(t_stack_node **tmp , int i, int nb)
{
	t_stack_node	*current;

	current = *tmp;
	while (current)
	{
		if (current -> s_index == i)
			current -> s_index = nb;
		current = current -> next;
	}
	
}
void	sort_s_index(t_stack_node **tmp)
{
	t_stack_node	*current;
	int				i;
	int				min;
	int				len;

	indexing(tmp);
	len = lst_len(*tmp);
	i = 0;
	while (len)
	{
		min = INT_MAX;
		current = *tmp;
		while (current)
		{
			if (current -> value < min && current -> s_index < 0)
				min = current -> value;
			current = current -> next;
		}
		current = *tmp;
		while ((current) && current -> value != min)
			current = current -> next;
		current -> s_index = i++;
		len--;
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	if (argc == 1 || !argv[1][0] || !arg_is_numbers(argv)
		|| !stack_fill(argv, &a))
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	sort_s_index(&a);
	if (is_sorted(a))
		exit(EXIT_SUCCESS);
	if (lst_len(a) <= 3)
		sort3(&a);
	else
	{
		a_2_b(&a, &b);
		b_2_a(&a, &b);
		while (!is_sorted(a))
		{
			if (lst_len(a) / 2 <  (a)-> s_index)
				ra(&a);
			else
				rra(&a);
		}
	}
	if (is_sorted(a))
		exit(EXIT_SUCCESS);
}
