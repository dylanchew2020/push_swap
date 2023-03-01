/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:11:05 by lchew             #+#    #+#             */
/*   Updated: 2023/03/01 15:43:00 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	int	tmp;

	if (stack->a != NULL && stack->a != NULL && stack->a->next != NULL)
	{
		tmp = stack->a->data;
		stack->a->data = stack->a->next->data;
		stack->a->next->data = tmp;
	}
}

void	sb(t_stack *stack)
{
	int	tmp;

	if (stack->b != NULL && stack->b != NULL && stack->b->next != NULL)
	{
		tmp = stack->b->data;
		stack->b->data = stack->b->next->data;
		stack->b->next->data = tmp;
	}
}

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
}
