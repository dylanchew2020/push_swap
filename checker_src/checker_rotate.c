/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:38:39 by lchew             #+#    #+#             */
/*   Updated: 2023/03/16 00:35:37 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
	Shift up all elements of stack a by 1.
	The first element becomes the last one.
 */
int	checker_ra(t_stack *stack)
{
	t_node	*second;
	t_node	*last;

	second = stack->a->next;
	last = ps_lstlast(stack->a);
	stack->a->next = NULL;
	last->next = stack->a;
	stack->a = second;
	return (1);
}

/* 
	Shift up all elements of stack b by 1.
	The first element becomes the last one.
 */
int	checker_rb(t_stack *stack)
{
	t_node	*second;
	t_node	*last;

	second = stack->b->next;
	last = ps_lstlast(stack->b);
	stack->b->next = NULL;
	last->next = stack->b;
	stack->b = second;
	return (1);
}

/* 
	ra and rb at the same time.
 */
int	checker_rr(t_stack *stack)
{
	checker_ra(stack);
	checker_rb(stack);
	return (1);
}
