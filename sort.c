/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:44:07 by lchew             #+#    #+#             */
/*   Updated: 2023/03/11 20:32:07 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack, char input)
{
	if (input == 'a' && stack->a->data > stack->a->next->data)
		sa(stack);
	else if (input == 'b' && stack->b->data < stack->b->next->data)
		sb(stack);
}

void	sort_a(t_stack *stack)
{
	int	size;
	int	pivot;
	
	if (stack->size_a % 2 == 0)
		size = stack->size_a / 2;
	else
		size = (stack->size_a / 2) + 1;
	if (stack->size_a == 2)
		sort_two(stack, 'a');
	else if (stack->size_a > 2)
	{
		pivot = get_median(stack->a);
		print(stack, 1, 'a', pivot);
		while (size > 0)
		{
			print(stack, 2, 'a', pivot);
			if (stack->a->data <= pivot)
			{
				pb(stack);
				--size;
			}
			else
				ra(stack);
			print(stack, 3, 'a', pivot);
		}
		print(stack, 4, 'a', pivot);
		sleep(1);
		printf("========FROM A ENTER A==========\n");
		sort_a(stack);
		printf("========EXIT A BACK A==========\n");
		// printf("========FROM A ENTER B==========\n");
		// sort_b(stack);
		// printf("========EXIT B END A==========\n");
	}
}

void	sort_b(t_stack *stack)
{
	int	size;
	int	pivot;
	
	if (stack->size_b % 2 == 0)
		size = stack->size_b / 2;
	else
		size = (stack->size_b / 2) + 1;
	if (stack->size_b == 2)
		sort_two(stack, 'b');
	else if (stack->size_b > 2)
	{
		pivot = get_median(stack->b);
		print(stack, 1, 'b', pivot);
		while (stack->b)
		{
			print(stack, 2, 'b', pivot);
			if (stack->b->data >= pivot)
			{
				pa(stack);
			}
			else
				rrb(stack);
			print(stack, 3, 'b', pivot);
		}
		print(stack, 4, 'b', pivot);
		sleep(1);
		printf("========FROM B ENTER B==========\n");
		sort_b(stack);
		printf("========EXIT B BACK B==========\n");
		// printf("========FROM B ENTER A==========\n");
		// sort_a(stack, tmp_array_a, i);
		// printf("========EXIT A END B==========\n");
	}
}