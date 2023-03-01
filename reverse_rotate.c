/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:48:06 by lchew             #+#    #+#             */
/*   Updated: 2023/03/01 18:54:16 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack)
{
	t_list	*second_last;
	t_list	*last;

	second_last = stack->a;
	if (!second_last || !second_last->next)
		return ;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = stack->a;
	stack->a = last;
}

void	rrb(t_stack *stack)
{
	t_list	*second_last;
	t_list	*last;

	second_last = stack->b;
	if (!second_last || !second_last->next)
		return ;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = stack->b;
	stack->b = last;
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
}
