/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_reverse_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:48:06 by lchew             #+#    #+#             */
/*   Updated: 2023/03/16 00:35:44 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
	Shift down all elements of stack a by 1.
	The last element becomes the first one.
 */
int	checker_rra(t_stack *stack)
{
	t_node	*second_last;
	t_node	*last;

	second_last = stack->a;
	if (!second_last || !second_last->next)
		return (0);
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = stack->a;
	stack->a = last;
	return (1);
}

/* 
	Shift down all elements of stack b by 1.
	The last element becomes the first one.
 */
int	checker_rrb(t_stack *stack)
{
	t_node	*second_last;
	t_node	*last;

	second_last = stack->b;
	if (!second_last || !second_last->next)
		return (0);
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = stack->b;
	stack->b = last;
	return (1);
}

/* 
	rra and rrb at the same time.
 */
int	checker_rrr(t_stack *stack)
{
	checker_rra(stack);
	checker_rrb(stack);
	return (1);
}
