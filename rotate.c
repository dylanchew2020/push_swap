/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:38:39 by lchew             #+#    #+#             */
/*   Updated: 2023/03/04 18:37:47 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	t_node	*second;
	t_node	*last;

	second = stack->a->next;
	last = ps_lstlast(stack->a);
	stack->a->next = NULL;
	last->next = stack->a;
	stack->a = second;
	ft_printf("%i\n", ra);
}

void	rb(t_stack *stack)
{
	t_node	*second;
	t_node	*last;

	second = stack->b->next;
	last = ps_lstlast(stack->b);
	stack->b->next = NULL;
	last->next = stack->b;
	stack->b = second;
	ft_printf("%i\n", rb);
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
	ft_printf("%i\n", rr);
}
