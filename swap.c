/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:11:05 by lchew             #+#    #+#             */
/*   Updated: 2023/03/01 18:54:44 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	char	*tmp;

	if (stack->a != NULL && stack->a != NULL && stack->a->next != NULL)
	{
		tmp = stack->a->content;
		stack->a->content = stack->a->next->content;
		stack->a->next->content = tmp;
	}
}

void	sb(t_stack *stack)
{
	char	*tmp;

	if (stack->b != NULL && stack->b != NULL && stack->b->next != NULL)
	{
		tmp = stack->b->content;
		stack->b->content = stack->b->next->content;
		stack->b->next->content = tmp;
	}
}

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
}
