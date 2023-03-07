/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:45:30 by lchew             #+#    #+#             */
/*   Updated: 2023/03/07 19:23:05 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
	Take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty.
 */
void	pa(t_stack *stack)
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
	write(1, "pa\n", 4);
}

/* 
	Take the first element at the top of a and put it at the top of b.
	Do nothing if a is empty.
 */
void	pb(t_stack *stack)
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
	write(1, "pb\n", 4);
}
