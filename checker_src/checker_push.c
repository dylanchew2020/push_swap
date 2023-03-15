/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:45:30 by lchew             #+#    #+#             */
/*   Updated: 2023/03/15 23:52:14 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
	Take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty.
 */
int	checker_pa(t_stack *stack)
{
	t_node	*tmp;

	if (stack->b != NULL)
	{
		tmp = stack->b->next;
		ps_lstadd_front(&(stack->a), stack->b);
		stack->b = tmp;
	}
	++stack->size_a;
	--stack->size_b;
	return (1);
}

/* 
	Take the first element at the top of a and put it at the top of b.
	Do nothing if a is empty.
 */
int	checker_pb(t_stack *stack)
{
	t_node	*tmp;

	if (stack->a != NULL)
	{
		tmp = stack->a->next;
		ps_lstadd_front(&(stack->b), stack->a);
		stack->a = tmp;
	}
	--stack->size_a;
	++stack->size_b;
	return (1);
}
