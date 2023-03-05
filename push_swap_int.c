/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:49:38 by lchew             #+#    #+#             */
/*   Updated: 2023/03/05 19:49:49 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	t_stack	stack;

	i = 1;
	if (argc < 2)
		return (1);
	stack_init(&stack);
	if (argc == 2)
		stack.tmp_array = ft_split(*(++argv), ' ');
	else
		stack.tmp_array = ++argv;
	insert_arg(&stack);
	stack.num_array = ft_calloc(stack.size, sizeof(char));
	while (stack.a)
	{
		printf("a: %i ", stack.a->data);
		*stack.num_array = stack.a->data;
		printf("list: %i\n", *stack.num_array);
		++stack.num_array;
		stack.a = stack.a->next;
	}
	printf("%i\n", stack.size);
	printf("%i\n", medianofmedian(stack.num_array, stack.size));
	return (0);
}

void	stack_init(t_stack *stack)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->size = 1;
	stack->tmp_array = NULL;
}

void	insert_arg(t_stack *stack)
{
	t_node	*head;

	head = ps_lstnew(ft_atoi(*stack->tmp_array++));
	stack->a = head;
	while (*stack->tmp_array)
	{
		head->next = ps_lstnew(ft_atoi(*stack->tmp_array++));
		head = head->next;
	}
	stack->size = ps_lstsize(stack->a);
}

int	medianofmedian(int *num_array, int size)
{
	int		median;
	int		*tmp;
	int		**partition;
	int		partition_size;
	int		*n;
	int		i;
	int		j;

	median = 0;
	tmp = NULL;
	partition = NULL;
	partition_size = 0;
	if (size <= M_SIZE)
	{
		median = get_median(num_array, size);
		free(num_array);
		return (median);
	}
	partition_size = size / M_SIZE + (size % M_SIZE != 0);
	partition = ft_calloc(partition_size, sizeof(int *));
	n = ft_calloc(partition_size, sizeof(int *));
	i = 0;
	while (size > 0)
	{
		j = 0;
		partition[i] = ft_calloc(M_SIZE, sizeof(int));
		while (j < M_SIZE && size > 0)
		{
			partition[i][j++] = *num_array++;
			--size;
		}
		n[i] = j;
		++i;
	}
	tmp = ft_calloc(partition_size, sizeof(int));
	i = 0;
	while (i < partition_size)
	{
		tmp[i] = get_median(partition[i], n[i]);
		++i;
	}
	free2d(partition, i);
	free(n);
	medianofmedian(tmp, i);
	free(tmp);
	return (median);
}

int	get_median(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	if (size == 1)
		return (array[i]);
	while (i < size)
	{
		j = i;
		while (array[j] > array [j + 1])
		{
			ft_swap(&array[j], &array[j + 1]);
			if (j > 0)
				--j;
		}
		++i;
	}
	if (size % 2 == 0)
		return ((array[(size - 1) / 2] + array[size / 2]) / 2);
	else
		return (array[size / 2]);
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
