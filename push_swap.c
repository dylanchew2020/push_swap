/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:49:38 by lchew             #+#    #+#             */
/*   Updated: 2023/03/07 21:10:57 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	stack;

	if (argc < 2)
		return (1);
	stack_init(&stack);
	if (argc == 2)
		stack.tmp_array = ft_split(*(++argv), ' ');
	else
		stack.tmp_array = ++argv;
	insert_arg(&stack);
	push(&stack, stack.tmp_array, stack.size_a);
	return (0);
}

// void	swap_two(t_stack *stack)
// {
// 	if (ps_lstsize())
// }

void	push(t_stack *stack, char **array, int size)
{
	int		i;
	char	**tmp_array;
	t_node	*tmp;

	i = 0;
	if (stack->size_a > 2)
	{
		stack->pivot = medianofmedian(array);
		printf("1 - Size_a: %i, Size_b: %i, Pivot: %i\n", stack->size_a, stack->size_b, stack->pivot);
		print_stack(stack->a, stack->b);
		while (stack->a && i++ < size)
		{
			printf("2 - Size_a: %i, Size_b: %i, Pivot: %i\n", stack->size_a, stack->size_b, stack->pivot);
			print_stack(stack->a, stack->b);
			if (stack->a->data < stack->pivot)
				pb(stack);
			else
				ra(stack);
			printf("3 - Size_a: %i, Size_b: %i, Pivot: %i\n", stack->size_a, stack->size_b, stack->pivot);
			print_stack(stack->a, stack->b);
		}
		printf("4 - Size_a: %i, Size_b: %i, Pivot: %i\n", stack->size_a, stack->size_b, stack->pivot);
		print_stack(stack->a, stack->b);
		tmp = stack->a;
		i = 0;
		tmp_array = ft_calloc(stack->size_a, sizeof(char *));
		while (tmp)
		{
			tmp_array[i++] = ft_itoa(tmp->data);
			tmp = tmp->next;
		}
		push(stack, tmp_array, stack->size_a);
	}
}

void	stack_init(t_stack *stack)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->size_total = 0;
	stack->size_a = 0;
	stack->size_b = 0;
	stack->tmp_array = NULL;
}

void	print_stack(t_node *a, t_node *b)
{
	while (a || b)
	{
		if (a)
		{
			printf("a: %i   |   ", a->data);
			a = a->next;
		}
		else
			printf("a: %p   |   ", a);
		if (b)
		{
			printf("b: %i\n", b->data);
			b = b->next;
		}
		else
			printf("b: %p\n", b);
	}
}
void	insert_arg(t_stack *stack)
{
	t_node	*head;
	char	**tmp;

	tmp = stack->tmp_array;
	head = ps_lstnew(ft_atoi(*tmp++));
	stack->a = head;
	while (*tmp)
	{
		head->next = ps_lstnew(ft_atoi(*tmp++));
		head = head->next;
	}
	stack->size_total = ps_lstsize(stack->a);
	stack->size_a = stack->size_total;
}

void	free2d(int **array, int size)
{
	int	**temp;
	int	i;

	temp = array;
	i = 0;
	while (i < size)
	{
		free(*temp);
		++i;
	}
	free(array);
}
