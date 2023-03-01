/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:38:39 by lchew             #+#    #+#             */
/*   Updated: 2023/03/01 18:54:06 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	t_list	*second;
	t_list	*last;

	second = stack->a->next;
	last = ft_lstlast(stack->a);
	stack->a->next = NULL;
	last->next = stack->a;
	stack->a = second;
}

void	rb(t_stack *stack)
{
	t_list	*second;
	t_list	*last;

	second = stack->b->next;
	last = ft_lstlast(stack->b);
	stack->b->next = NULL;
	last->next = stack->b;
	stack->b = second;
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
}