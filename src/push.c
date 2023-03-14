/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:45:30 by lchew             #+#    #+#             */
/*   Updated: 2023/03/14 20:44:45 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
	Take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty.
 */
void	pa(t_stack *stack)
{
	t_node	*tmp;

	if (stack->b != NULL)
	{
		tmp = stack->b->next;
		ps_lstadd_front(&(stack->a), stack->b);
		stack->b = tmp;
	}
	++stack->size_a;
	--stack->size_b;
	ft_printf("pa\n");
}

/* 
	Take the first element at the top of a and put it at the top of b.
	Do nothing if a is empty.
 */
void	pb(t_stack *stack)
{
	t_node	*tmp;

	if (stack->a != NULL)
	{
		tmp = stack->a->next;
		ps_lstadd_front(&(stack->b), stack->a);
		stack->a = tmp;
	}
	--stack->size_a;
	++stack->size_b;
	ft_printf("pb\n");
}

int	push_a(t_stack *stack, int push_size, int pivot)
{
	int	push;
	int	rotate;

	push = 0;
	rotate = 0;
	while (push < push_size / 2)
	{
		if (stack->a->data < pivot)
		{
			pb(stack);
			++push;
		}
		else
		{
			ra(stack);
			++rotate;
		}
	}
	while (rotate-- > 0)
		rra(stack);
	return (push);
}

int	push_b(t_stack *stack, int push_size, int pivot)
{
	int	push;
	int	rotate;

	push = 0;
	rotate = 0;
	if (push_size % 2 == 0)
		push_size = push_size / 2;
	else if (push_size % 2 == 1)
		push_size = (push_size / 2) + 1;
	while (push < push_size)
	{
		if (stack->b->data >= pivot)
		{
			pa(stack);
			++push;
		}
		else
		{
			rb(stack);
			++rotate;
		}
	}
	while (rotate-- > 0)
		rrb(stack);
	return (push);
}
