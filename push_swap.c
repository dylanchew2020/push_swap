/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:49:38 by lchew             #+#    #+#             */
/*   Updated: 2023/03/05 21:30:08 by lchew            ###   ########.fr       */
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
	while (stack.a)
	{
		printf("a: %i \n", stack.a->data);
		stack.a = stack.a->next;
	}
	printf("Stack_size: %i\n", stack.size);
	printf("median: %i\n", medianofmedian(stack.tmp_array));
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
	char	**tmp;

	tmp = stack->tmp_array;
	head = ps_lstnew(ft_atoi(*tmp++));
	stack->a = head;
	while (*tmp)
	{
		head->next = ps_lstnew(ft_atoi(*tmp++));
		head = head->next;
	}
	stack->size = ps_lstsize(stack->a);
}

int	medianofmedian(char **array)
{
	int		median;
	int		size;
	char	**array_of_median;
	int		*partition;
	int		partition_size;
	int		n;
	int		i;
	int		j;

	median = 0;
	array_of_median = NULL;
	partition = NULL;
	partition_size = 0;
	size = 0;
	n = 0;
	i = 0;
	while (array[size] != NULL)
		++size;
	if (size <= M_SIZE)
	{
		partition = ft_calloc(size, sizeof(int));
		while (array[i] != NULL)
		{
			partition[i] = ft_atoi(array[i]);
			++i;
		}
		median = get_median(partition, size);
		return (median);
	}
	partition_size = size / M_SIZE + (size % M_SIZE != 0);
	array_of_median = ft_calloc(partition_size + 1, sizeof(char *));
	partition = ft_calloc(M_SIZE, sizeof(int));
	while (array[i] != NULL)
	{
		j = 0;
		while (j < M_SIZE && array[i] != NULL)
			partition[j++] = ft_atoi(array[i++]);
		array_of_median[n] = ft_itoa(get_median(partition, j));
		++n;
	}
	median = medianofmedian(array_of_median);
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
		while (j + 1 < size && array[j] > array [j + 1])
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
