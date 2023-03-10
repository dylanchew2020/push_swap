/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:49:36 by lchew             #+#    #+#             */
/*   Updated: 2023/03/14 19:41:21 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include "libft/includes/ft_printf.h"
# include <stdio.h>

# define M_SIZE 5

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
}				t_node;

/* 
	t_node *a - stores the address of the first node (HEAD) in stack a.
	t_node *b - stores the address of the first node (HEAD) in stack b.
	int size - total number of nodes in stack a & b.
 */
typedef struct s_stack
{
	t_node	*a;
	t_node	*b;
	int		size_a;
	int		size_b;
	char	**str_arg;
	char	**multi_arg;
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

void	stack_init(t_stack *stack);
void	insert_arg(t_stack *stack, int code, char **tmp);
int		get_median(t_stack *stack, t_node *head, int size);
void	index_stack(t_stack *stack, t_node *node, int size);
void	free2d(char **array);

// SORT FUNCTIONS

void	sort_a(t_stack *stack, int push_size);
void	sort_b(t_stack *stack, int push_size);
void	sort_two(t_stack *stack, char input);
void	sort_three_a(t_stack *stack);
void	sort_three_b(t_stack *stack);
int		push_a(t_stack *stack, int push_size, int pivot);
int		push_b(t_stack *stack, int push_size, int pivot);
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

#endif