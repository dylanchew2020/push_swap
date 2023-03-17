/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:45:30 by lchew             #+#    #+#             */
/*   Updated: 2023/03/17 17:25:10 by lchew            ###   ########.fr       */
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

/*
** This function pushes all elements from the top of stack A that are LESS THAN
** the specified pivot value to stack B. It returns the number of elements that
** were successfully pushed.
**
** Parameters:
** - stack: a pointer to the stack structure
** - size: the number of nodes to consider, starting from the top of stack A
** - pivot: the value to compare against for determining which elements to push
*/
int	push_a(t_stack *stack, int size, int pivot)
{
	int	push;
	int	rotate;

	push = 0;
	rotate = 0;
	while (push < size)
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
	while (stack->size_a > 5 && rotate-- > 0)
		rra(stack);
	return (push);
}

/*
** This function pushes all elements from the top of stack B that are GREATER
** THAN or EQUAL TO the specified pivot value to stack A. It returns the number
** of elements that were successfully pushed.
**
** Parameters:
** - stack: a pointer to the Stack structure
** - size: the number of nodes to consider, starting from the top of stack B
** - pivot: the value to compare against for determining which elements to push
*/
int	push_b(t_stack *stack, int size, int pivot)
{
	int	push;
	int	rotate;

	push = 0;
	rotate = 0;
	while (push < size)
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
	while (stack->size_a > 5 && rotate-- > 0)
		rrb(stack);
	return (push);
}
