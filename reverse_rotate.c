/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:48:06 by lchew             #+#    #+#             */
/*   Updated: 2023/03/07 18:42:53 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
	Shift down all elements of stack a by 1.
	The last element becomes the first one.
 */
void	rra(t_stack *stack)
{
	t_node	*second_last;
	t_node	*last;

	second_last = stack->a;
	if (!second_last || !second_last->next)
		return ;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = stack->a;
	stack->a = last;
	write(1, "rra\n", 5);
}

/* 
	Shift down all elements of stack b by 1.
	The last element becomes the first one.
 */
void	rrb(t_stack *stack)
{
	t_node	*second_last;
	t_node	*last;

	second_last = stack->b;
	if (!second_last || !second_last->next)
		return ;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = stack->b;
	stack->b = last;
	write(1, "rrb\n", 5);
}

/* 
	rra and rrb at the same time.
 */
void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
	write(1, "rrr\n", 5);
}
