/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:44:07 by lchew             #+#    #+#             */
/*   Updated: 2023/03/17 18:07:56 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Sorts stack A in ascending order using the quicksort algorithm.
** First, if the stack size is 2 or 3, it is sorted using the corresponding
** functions. Otherwise, a pivot is chosen as the median of the current stack,
** and nodes with data values less than or equal to the pivot are pushed to
** stack B. Then, sort_a is recursively called on stack A with the updated size
** and sort_b is called with the number of nodes pushed to stack B. Finally,
** the nodes are pushed back to stack A in ascending order.
**
** Parameters:
** - stack: a pointer to the stack structure
** - size: the number of nodes to consider, starting from the top of stack A
*/
void	sort_a(t_stack *stack, int size)
{
	int	pivot;
	int	push;

	push = 0;
	if (size == 2)
		sort_two(stack, 'a');
	else if (size == 3)
		sort_three_a(stack);
	else if (size > 3)
	{
		pivot = get_median(stack, stack->a, size);
		if (check_sort_a(stack->a, size))
		{
			push = push_a(stack, (size / 2), pivot);
			sort_a(stack, size - push);
			sort_b(stack, push);
		}
	}
}

/*
** Sorts stack B in ascending order using the quicksort algorithm.
** First, if the stack size is 2 or 3, it is sorted using the corresponding
** functions. Otherwise, a pivot is chosen as the median of the current stack,
** and nodes with data values greater than the pivot are pushed to stack A.
** Then, sort_b is recursively called on stack B with the updated size and sort_a
** is called with the number of nodes pushed to stack A. Finally, the nodes are
** pushed back to stack B in ascending order.
**
** Parameters:
** - stack: a pointer to the stack structure
** - size: the number of nodes to consider, starting from the top of stack B
*/
void	sort_b(t_stack *stack, int size)
{
	int	pivot;
	int	push;

	push = 0;
	if (size == 2)
		sort_two(stack, 'b');
	else if (size == 3)
		sort_three_b(stack);
	else if (size > 3)
	{
		pivot = get_median(stack, stack->b, size);
		if (check_sort_b(stack, stack->b, size))
		{
			if (size % 2 == 0)
				push = push_b(stack, size / 2, pivot);
			else if (size % 2 == 1)
				push = push_b(stack, (size / 2) + 1, pivot);
			sort_a(stack, push);
			sort_b(stack, size - push);
		}
	}
}

/*
** Sorts a pair of nodes in the given stack based on their data values.
** For stack A, swaps the nodes if the first node has a greater value.
** For stack B, if the first two nodes are not sorted, it swaps them
** and moves both nodes to stack A.
**
** Parameters:
** - stack: a pointer to the stack structure
** - input: determines which stack to sort (A or B)
*/
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
** Sorts the top three nodes in stack A in ascending order.
** The function starts by comparing the first and second nodes, swaps them if
** necessary. It then compares the second and third nodes, and swaps them if
** necessary. Finally, it compares the first and second nodes again, and swaps
** them if necessary. The result is a sorted stack.
**
** Parameters:
** - stack: a pointer to the stack structure
*/
void	sort_three_a(t_stack *stack)
{
	if (stack->a->data > stack->a->next->data)
		sa(stack);
	if (stack->a->next->data > stack->a->next->next->data)
	{
		if (stack->size_a == 3)
			rra(stack);
		else
		{
			ra(stack);
			sa(stack);
			rra(stack);
		}
	}
	if (stack->a->data > stack->a->next->data)
		sa(stack);
}

/*
** Sorts the top three nodes in stack B in ascending order.
** The function starts by comparing the first and second nodes, swaps them if
** necessary. It then compares the second and third nodes, and swaps them if
** necessary. Finally, it compares the first and second nodes again, and swaps
** them if necessary. The result is a sorted stack.
** Finally, it pushes 3 nodes back into stack A
**
** Parameters:
** - stack: a pointer to the stack structure
*/
void	sort_three_b(t_stack *stack)
{
	int		i;

	i = 0;
	if (stack->b->data < stack->b->next->data)
		sb(stack);
	if (stack->b->next->data < stack->b->next->next->data)
	{
		if (stack->size_a == 3)
			rrb(stack);
		else
		{
			rb(stack);
			sb(stack);
			rrb(stack);
		}
	}
	if (stack->b->data < stack->b->next->data)
		sb(stack);
	while (i++ < 3)
		pa(stack);
}
