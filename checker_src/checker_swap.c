/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:11:05 by lchew             #+#    #+#             */
/*   Updated: 2023/03/16 00:35:50 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
	Swap the first 2 elements at the top of stack a.
	Do nothing if there is only one or no elements.
 */
int	checker_sa(t_stack *stack)
{
	int	tmp;

	if (stack->a != NULL && stack->a != NULL && stack->a->next != NULL)
	{
		tmp = stack->a->data;
		stack->a->data = stack->a->next->data;
		stack->a->next->data = tmp;
	}
	return (1);
}

/* 
	Swap the first 2 elements at the top of stack b.
	Do nothing if there is only one or no elements.
 */
int	checker_sb(t_stack *stack)
{
	int	tmp;

	if (stack->b != NULL && stack->b != NULL && stack->b->next != NULL)
	{
		tmp = stack->b->data;
		stack->b->data = stack->b->next->data;
		stack->b->next->data = tmp;
	}
	return (1);
}

/* 
	sa and sb at the same time.
 */
int	checker_ss(t_stack *stack)
{
	checker_sa(stack);
	checker_sb(stack);
	return (1);
}
