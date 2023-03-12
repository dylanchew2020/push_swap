/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:38:39 by lchew             #+#    #+#             */
/*   Updated: 2023/03/12 20:16:47 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
	Shift up all elements of stack a by 1.
	The first element becomes the last one.
 */
void	ra(t_stack *stack)
{
	t_node	*second;
	t_node	*last;

	second = stack->a->next;
	last = ps_lstlast(stack->a);
	stack->a->next = NULL;
	last->next = stack->a;
	stack->a = second;
	// write(1, "ra\n", 4);
	ft_printf("ra\n");
}

/* 
	Shift up all elements of stack b by 1.
	The first element becomes the last one.
 */
void	rb(t_stack *stack)
{
	t_node	*second;
	t_node	*last;

	second = stack->b->next;
	last = ps_lstlast(stack->b);
	stack->b->next = NULL;
	last->next = stack->b;
	stack->b = second;
	// write(1, "rb\n", 4);
	ft_printf("rb\n");
}

/* 
	ra and rb at the same time.
 */
void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
	// write(1, "rr\n", 4);
	ft_printf("rr\n");
}
