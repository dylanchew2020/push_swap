/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:30:00 by lchew             #+#    #+#             */
/*   Updated: 2023/03/07 13:30:40 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	medianofmedian(char **array)
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
}