/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:49:38 by lchew             #+#    #+#             */
/*   Updated: 2023/03/12 20:00:31 by lchew            ###   ########.fr       */
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
	// print_stack(stack.a, stack.b);
	sort_a(&stack, stack.size_a);
	// print_stack(stack.a, stack.b);
	return (0);
}

void	stack_init(t_stack *stack)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->size_total = 0;
	stack->size_a = 0;
	stack->size_b = 0;
	stack->tmp_array = NULL;
	stack->recursion_count = 0;
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

void	print(t_stack *stack, int num, char c, int pivot, int push_size)
{
	printf("%c%i - Size_a: %i, Size_b: %i, Median: %i, PS = %i\n", c, num, stack->size_a, stack->size_b, pivot, push_size);
	print_stack(stack->a, stack->b);
	printf("=======================\n");
}

void	print_stack(t_node *a, t_node *b)
{
	printf("a: ");
	while (a)
	{
		printf("%i ", a->data);
		a = a->next;
	}
	printf("\n");
	printf("b: ");
	while (b)
	{
		printf("%i ", b->data);
		b = b->next;
	}
	printf("\n");
}
