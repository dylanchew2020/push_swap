/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:49:36 by lchew             #+#    #+#             */
/*   Updated: 2023/03/17 17:10:01 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include "libft/includes/ft_printf.h"

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
}				t_node;

/* 
	t_node *a - stores the address of the first node (HEAD) in stack a.
	t_node *b - stores the address of the first node (HEAD) in stack b.
	int size_a - total number of nodes in stack a.
	int size_a - total number of nodes in stack b.
 */
typedef struct s_stack
{
	t_node	*a;
	t_node	*b;
	int		size_a;
	int		size_b;
	char	**str_arg;
}				t_stack;

typedef struct s_index
{
	int		n;
	int		count;
	t_node	*node;
	t_node	*tmp;
	int		limit;
	int		i;
}				t_index;

// MAIN FUNCTIONS

void	stack_init(t_stack *stack);
void	insert_arg(t_stack *stack, int code, char **tmp);
void	free2d(char **array);

// GET MEDIAN FUNCTIONS

int		get_median(t_stack *stack, t_node *head, int size);
void	index_stack(t_stack *stack, t_node *node, int size);

// SORT FUNCTIONS

void	sort_a(t_stack *stack, int size);
void	sort_b(t_stack *stack, int size);
void	sort_two(t_stack *stack, char input);
void	sort_three_a(t_stack *stack);
void	sort_three_b(t_stack *stack);
int		push_a(t_stack *stack, int size, int pivot);
int		push_b(t_stack *stack, int size, int pivot);
int		check_sort_a(t_node *tmp, int size);
int		check_sort_b(t_stack *stack, t_node *tmp, int size);

// ERROR FUNCTIONS

void	exit_with_error(int code, t_stack *stack);
void	error_non_integer(char *arg, int code, t_stack *stack);

// LINKED LIST FUNCTIONS

t_node	*ps_lstnew(int data);
int		ps_lstsize(t_node *node);
t_node	*ps_lstlast(t_node *node);
void	ps_lstdelone(t_node *node);
void	ps_lstclear(t_node **node);
void	ps_lstadd_back(t_node **node, t_node *new);
void	ps_lstadd_front(t_node **node, t_node *new);

// SWAP FUNCTIONS

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);

// PUSH FUNCTIONS

void	pa(t_stack *stack);
void	pb(t_stack *stack);

// ROTATE FUNCTIONS

void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);

//REVERSE ROTATE FUNCTIONS

void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

// CHECKER FUNCTIONS

void	operation(t_stack *stack);
int		checker_sort(t_stack *stack, char *stdin);
int		checker_rotate(t_stack *stack, char *stdin);
int		checker_sa(t_stack *stack);
int		checker_sb(t_stack *stack);
int		checker_ss(t_stack *stack);
int		checker_pa(t_stack *stack);
int		checker_pb(t_stack *stack);
int		checker_ra(t_stack *stack);
int		checker_rb(t_stack *stack);
int		checker_rr(t_stack *stack);
int		checker_rra(t_stack *stack);
int		checker_rrb(t_stack *stack);
int		checker_rrr(t_stack *stack);

#endif