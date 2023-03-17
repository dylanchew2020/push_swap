/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:30:00 by lchew             #+#    #+#             */
/*   Updated: 2023/03/17 17:58:22 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** This function finds the median value of a stack.
** It does this by first calling the index_stack function to assign index 
** values to each node in the stack, based on the number of nodes with a 
** smaller data value. Then it iterates through the stack until it finds 
** the node with the median index.
**
** Parameters:
** - stack: a pointer to the stack structure
** - head: a pointer to the head node of the stack
** - size: the number of nodes to consider, starting from the top of stack A
** Returns:
** - the median value of the stack
*/
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

/*
** This function assigns an index to each node in the stack based on its 
** position in a sorted version. It counts the number of nodes with smaller
** data values by iterating over each node and then assigns the count value 
** as the index. If there are nodes with the same data value, the function 
** exits with an error.
**
** Parameters:
** - stack: a pointer to the stack structure
** - head: a pointer to the head node of the stack
** - size: the number of nodes to consider, starting from the top of stack A
*/
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

/*
** Checks if the given stack is sorted in ascending order.
** Compares each node's data value to its next node's data value.
** Returns 1 if the stack is not sorted, 0 otherwise.
**
** Parameters:
** - tmp: a pointer to the head of the stack to be checked
** - size: the number of nodes to consider
** Return:
** - 1 if the stack is not sorted
** - 0 if the stack is sorted
*/

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

/*
** Checks if the given stack is sorted in descending order.
** Compares each node's data value to its next node's data value.
** Returns 1 if the stack is not sorted, 0 otherwise.
** If the stack is not sorted, it empties the stack B by pushing its nodes 
** onto stack A.
**
** Parameters:
** - stack: a pointer to the stack structure
** - tmp: a pointer to the head of the stack to be checked
** - size: the number of nodes to consider
** Return:
** - 1 if the stack is not sorted
** - 0 if the stack is sorted
*/
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
