/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:17:50 by yboutsli          #+#    #+#             */
/*   Updated: 2024/01/29 16:34:46 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
typedef struct s_stack_node
{
	int					value;
	int 				s_index;
	int 				moves;
	int					ra;
	int					rb;
	int					rra;
	int					rrb;
	int					pa;
	struct s_stack_node	*next;

}	t_node;

int				is_integer(const char *str);
char			**ft_split(char const *s, char c);
void			ft_lstadd_back(t_node **lst, t_node *new);
t_node			*ft_lstnew(int value);
int				ft_atoi(const char *str);
void			ft_lstclear(t_node **lst);
size_t			ft_strlen(char *str);
void 			sa(t_node **a);
void			sb(t_node **b);
void			ss(t_node **a, t_node **b);
void			pa(t_node **a, t_node **b);
void			pb(t_node **a, t_node **b);
void			ra(t_node **a);
void			rb(t_node **b);
void			rr(t_node **a, t_node **b);
void			rra(t_node **a);
void			rrb(t_node **b);
void			rrr(t_node **a, t_node **b);
void			ft_lstadd_front(t_node **lst, t_node *new);
t_node			*ft_lstlast(t_node *lst);
int				is_sorted(t_node	*a);
int				lst_len(t_node	*lst);
int				lst_max(t_node	*lst);
void			a_2_b(t_node **a, t_node **b);
void			b_2_a(t_node **a, t_node **b);
void			sort3(t_node **tmp);
int				arg_is_numbers(char **argv);
int				stack_fill(char **argv, t_node **a);
void			operation_init(t_node **tmp);
int				moves_sum(t_node *c);
int				min_moves(t_node **b);
void			cal_moves1(t_node **current, int index, int *nb_moves);
#endif