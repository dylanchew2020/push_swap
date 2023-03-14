/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:48:06 by lchew             #+#    #+#             */
/*   Updated: 2023/03/14 18:13:53 by lchew            ###   ########.fr       */
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
	ft_printf("rra\n");
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
	ft_printf("rrb\n");
}

/* 
	rra and rrb at the same time.
 */
void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
	ft_printf("rrr\n");
}
