/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:45:30 by lchew             #+#    #+#             */
/*   Updated: 2023/03/04 18:36:17 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack)
{
	t_node	*tmp;

	if (stack->b != NULL)
	{
		tmp = stack->b->next;
		ps_lstadd_front(&(stack->a), stack->b);
		stack->b = tmp;
	}
	ft_printf("%i\n", pa);
}

void	pb(t_stack *stack)
{
	t_node	*tmp;

	if (stack->a != NULL)
	{
		tmp = stack->a->next;
		ps_lstadd_front(&(stack->b), stack->a);
		stack->a = tmp;
	}
	ft_printf("%i\n", pb);
}