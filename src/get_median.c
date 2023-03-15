/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:30:00 by lchew             #+#    #+#             */
/*   Updated: 2023/03/16 00:33:42 by lchew            ###   ########.fr       */
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
