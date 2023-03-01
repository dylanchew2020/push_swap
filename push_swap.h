/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:49:36 by lchew             #+#    #+#             */
/*   Updated: 2023/03/01 18:56:06 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include "libft/includes/ft_printf.h"
# include <stdio.h>

/* typedef struct s_node
{
	void			*data;
	struct s_node	*next;
}				t_node; */

/* 
	t_node *a - stores the address of the first node (HEAD) in stack a.
	t_node *b - stores the address of the first node (HEAD) in stack b.
	int size - total number of nodes in stack a & b.
 */
typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
	int		size;
}				t_stack;

void	stack_init(t_stack *stack);

// SWAP
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);

// PUSH
void	pa(t_stack *stack);
void	pb(t_stack *stack);

// ROTATE
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);

//REVERSE ROTATE
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

#endif