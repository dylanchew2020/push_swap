/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:30:00 by lchew             #+#    #+#             */
/*   Updated: 2023/03/14 19:51:51 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_median(t_stack *stack, t_node *head, int size)
{
	int		n;

	if (head == NULL)
		return (0);
	if (head->next == NULL)
		return (head->data);
	index_stack(stack, head, size);
	n = (size / 2) + 1;
	while (head != NULL)
	{
		if (head->index == n)
			break ;
		head = head->next;
	}
	return (head->data);
}

void	index_stack(t_stack *stack, t_node *head, int size)
{
	t_index	id;

	id.n = 0;
	id.node = head;
	id.tmp = head;
	id.limit = size;
	while (id.tmp != NULL && size-- > 0)
	{
		id.count = 1;
		id.i = 0;
		id.n = id.tmp->data;
		while (id.node != NULL && id.i++ < id.limit)
		{
			if (id.n > id.node->data)
				++id.count;
			else if (id.tmp != id.node && id.n == id.node->data)
				exit_with_error(0, stack);
			id.node = id.node->next;
		}
		id.tmp->index = id.count;
		id.tmp = id.tmp->next;
		id.node = head;
	}
}

int	check_sort_a(t_node *tmp, int size)
{
	while (tmp != NULL && --size > 0)
	{
		if (tmp->data > tmp->next->data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_sort_b(t_stack *stack, t_node *tmp, int size)
{
	int	i;

	i = 1;
	while (tmp != NULL && i++ < size)
	{
		if (tmp->data < tmp->next->data)
			return (1);
		tmp = tmp->next;
	}
	while (size-- > 0)
		pa(stack);
	return (0);
}
/* int	medianofmedian(char **array)
{
	int		pivot;
	int		size;
	int		*partition;
	int		i;

	pivot = 0;
	size = 0;
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
		pivot = get_median(partition, size);
		return (pivot);
	}
	pivot = medianofmedian(get_array_of_median(size, array));
	return (pivot);
}

char	**get_array_of_median(int size, char **array)
{
	t_partition	pt;

	pt.n = 0;
	pt.i = 0;
	pt.partition_size = size / M_SIZE + (size % M_SIZE != 0);
	pt.array_of_median = ft_calloc(pt.partition_size + 1, sizeof(char *));
	pt.partition = ft_calloc(M_SIZE, sizeof(int));
	while (array[pt.i] != NULL)
	{
		pt.j = 0;
		while (pt.j < M_SIZE && array[pt.i] != NULL)
			pt.partition[pt.j++] = ft_atoi(array[pt.i++]);
		pt.array_of_median[pt.n] = ft_itoa(get_median(pt.partition, pt.j));
		++pt.n;
	}
	return (pt.array_of_median);
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
} */