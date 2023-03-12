/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:44:07 by lchew             #+#    #+#             */
/*   Updated: 2023/03/12 19:59:09 by lchew            ###   ########.fr       */
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

/* 
456
465 2 456
546 1 456
564 2 546 3 456
645 1 465 2 456
654 1 564 2 546 3 456
*/

void	sort_three(t_stack *stack, char input)
{
	int		i;

	i = 0;
	if (input == 'a')
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
	else if (input == 'b')
	{
		// print_stack(stack->a, stack->b);
		if (stack->b->data < stack->b->next->data)
			sb(stack);
		// print_stack(stack->a, stack->b);
		if (stack->b->next->data < stack->b->next->next->data)
		{
			rb(stack);
			sb(stack);
			rrb(stack);
		}
		// print_stack(stack->a, stack->b);
		if (stack->b->data < stack->b->next->data)
			sb(stack);
		// print_stack(stack->a, stack->b);
		while (i++ < 3)
			pa(stack);
	}
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
	if (push_size == 3)
		sort_three(stack, 'a');
	else if (push_size > 3)
	{
		pivot = get_median(stack->a, push_size);
		// print(stack, 1, 'a', pivot, push_size);
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
		// print(stack, 2, 'a', pivot, push_size);
		sort_a(stack, push_size - push);
		sort_b(stack, push);
	}
}

void	sort_b(t_stack *stack, int push_size)
{
	int	pivot;
	int	push;
	int	rotate;

	push = 0;
	rotate = 0;
	if (push_size == 2)
		sort_two(stack, 'b');
	if (push_size == 3)
		sort_three(stack, 'b');
	else if (push_size > 3)
	{
		pivot = get_median(stack->b, push_size);
		// print(stack, 1, 'b', pivot, push_size);
		while (push < (push_size % 2 == 0 ? push_size / 2 : (push_size / 2) + 1))
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
		// print(stack, 2, 'b', pivot, push_size);
		sort_a(stack, push);
		sort_b(stack, push_size - push);
	}
}
