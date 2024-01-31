/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:10:51 by yboutsli          #+#    #+#             */
/*   Updated: 2024/01/31 15:55:10 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*next;

}	t_node;
t_node	*ft_lstlast(t_node *lst);
void	ft_lstadd_back(t_node **lst, t_node *new);
void	ft_lstadd_front(t_node **lst, t_node *new);
char	*get_next_line(int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
int		arg_is_numbers(char **argv);
int		stack_fill(char **argv, t_node **a);
char	**ft_split(char const *s, char c);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
int		exist_in_lst(t_node **a, int nb);
t_node	*ft_lstnew(int value);
char	*operation_str(void);
void	execute(char *str, t_node **a, t_node **b);
void	parcing_check(int argc, char **argv, t_node **a);
#endif