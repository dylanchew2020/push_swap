/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:44:07 by lchew             #+#    #+#             */
/*   Updated: 2023/03/14 17:50:22 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack, char input)
{
	if (input == 'a' && stack->a->data > stack->a->next->data)
		sa(stack);
	if (input == 'b')
	{
		if (stack->b->data < stack->b->next->data)
			sb(stack);
		pa(stack);
		pa(stack);
	}
}

void	sort_three_a(t_stack *stack)
{
	if (stack->a->data > stack->a->next->data)
		sa(stack);
	if (stack->a->next->data > stack->a->next->next->data)
	{
		ra(stack);
		sa(stack);
		rra(stack);
	}
	if (stack->a->data > stack->a->next->data)
		sa(stack);
}

void	sort_three_b(t_stack *stack)
{
	int		i;

	i = 0;
	if (stack->b->data < stack->b->next->data)
		sb(stack);
	if (stack->b->next->data < stack->b->next->next->data)
	{
		rb(stack);
		sb(stack);
		rrb(stack);
	}
	if (stack->b->data < stack->b->next->data)
		sb(stack);
	while (i++ < 3)
		pa(stack);
}

void	sort_a(t_stack *stack, int push_size)
{
	int	pivot;
	int	push;
	int	rotate;

	push = 0;
	rotate = 0;
	if (push_size == 2)
		sort_two(stack, 'a');
	else if (push_size == 3)
		sort_three_a(stack);
	else if (push_size > 3)
	{
		pivot = get_median(stack, stack->a, push_size);
		push = push_a(stack, push_size, pivot);
		sort_a(stack, push_size - push);
		sort_b(stack, push);
	}
}

void	sort_b(t_stack *stack, int push_size)
{
	int	pivot;
	int	push;

	if (push_size == 2)
		sort_two(stack, 'b');
	else if (push_size == 3)
		sort_three_b(stack);
	else if (push_size > 3)
	{
		pivot = get_median(stack, stack->b, push_size);
		push = push_b(stack, push_size, pivot);
		sort_a(stack, push);
		sort_b(stack, push_size - push);
	}
}
