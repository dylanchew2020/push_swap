/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:49:36 by lchew             #+#    #+#             */
/*   Updated: 2023/03/07 21:08:51 by lchew            ###   ########.fr       */
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
	int		size_total;
	int		size_a;
	int		size_b;
	int		pivot;
	char	**tmp_array;
	int		*num_array;
}				t_stack;

typedef struct s_partition
{
	int		partition_size;
	char	**array_of_median;
	int		*partition;
	int		n;
	int		i;
	int		j;
}				t_partition;

void	stack_init(t_stack *stack);
void	insert_arg(t_stack *stack);
void	print_stack(t_node *a, t_node *b);
int		medianofmedian(char **array);
char	**get_array_of_median(int size, char **array);
int		get_median(int *array, int size);
void	free2d(int **array, int size);
void	push(t_stack *stack, char **array, int	size);

// LINKED LIST FUNCTIONS

t_node	*ps_lstnew(int data);
int		ps_lstsize(t_node *node);
t_node	*ps_lstlast(t_node *node);
void	ps_lstdelone(t_node *node, void (*del)(int));
void	ps_lstclear(t_node **node, void (*del)(int));
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