/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:11:05 by lchew             #+#    #+#             */
/*   Updated: 2023/03/14 18:13:22 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
	Swap the first 2 elements at the top of stack a.
	Do nothing if there is only one or no elements.
 */
void	sa(t_stack *stack)
{
	int	tmp;

	if (stack->a != NULL && stack->a != NULL && stack->a->next != NULL)
	{
		tmp = stack->a->data;
		stack->a->data = stack->a->next->data;
		stack->a->next->data = tmp;
	}
	ft_printf("sa\n");
}

/* 
	Swap the first 2 elements at the top of stack b.
	Do nothing if there is only one or no elements.
 */
void	sb(t_stack *stack)
{
	int	tmp;

	if (stack->b != NULL && stack->b != NULL && stack->b->next != NULL)
	{
		tmp = stack->b->data;
		stack->b->data = stack->b->next->data;
		stack->b->next->data = tmp;
	}
	ft_printf("sb\n");
}

/* 
	sa and sb at the same time.
 */
void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
	ft_printf("ss\n");
}
