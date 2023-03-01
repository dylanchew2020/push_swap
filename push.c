/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:45:30 by lchew             #+#    #+#             */
/*   Updated: 2023/03/01 18:53:54 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack)
{
	t_list	*tmp;

	if (stack->b != NULL)
	{
		tmp = stack->b->next;
		ft_lstadd_front(&(stack->a), stack->b);
		stack->b = tmp;
	}
}

void	pb(t_stack *stack)
{
	t_list	*tmp;

	if (stack->a != NULL)
	{
		tmp = stack->a->next;
		ft_lstadd_front(&(stack->b), stack->a);
		stack->a = tmp;
	}
}
