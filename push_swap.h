/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:17:50 by yboutsli          #+#    #+#             */
/*   Updated: 2024/01/29 10:28:19 by yboutsli         ###   ########.fr       */
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

}	t_stack_node;

int				is_integer(const char *str);
char			**ft_split(char const *s, char c);
void			ft_lstadd_back(t_stack_node **lst, t_stack_node *new);
t_stack_node	*ft_lstnew(int value);
int				ft_atoi(const char *str);
void			ft_lstclear(t_stack_node **lst);
size_t			ft_strlen(char *str);
void 			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			ft_lstadd_front(t_stack_node **lst, t_stack_node *new);
t_stack_node	*ft_lstlast(t_stack_node *lst);
int				is_sorted(t_stack_node	*a);
int				max_linkedlst(int nb, t_stack_node	*lst);
unsigned int	max_index(int nb, t_stack_node	*lst);
int				min_nb_operation(t_stack_node	*a, t_stack_node	*b);
int				lst_len(t_stack_node	*lst);
int				lst_max(t_stack_node	*lst);
int				lst_min(t_stack_node	*lst);
void			a_2_b(t_stack_node **a, t_stack_node **b);
void			indexing(t_stack_node **tmp);
void			sort_s_index(t_stack_node **tmp);
void			b_2_a(t_stack_node **a, t_stack_node **b);
void			sort3(t_stack_node **tmp);
void			sort5(t_stack_node **a, t_stack_node **b);
#endif