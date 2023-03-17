/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:49:38 by lchew             #+#    #+#             */
/*   Updated: 2023/03/17 16:51:30 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
	Initialise the variables declared in struct s_stack.
	stack->a - variable for stack a linked list;
	stack->b - variable for stack b linked list;
	stack->size_a - real-time record the numbers of nodes in stack a;
	stack->size_b - real-time record the numbers of nodes in stack b;
	
 */
void	stack_init(t_stack *stack)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->size_a = 0;
	stack->size_b = 0;
	stack->str_arg = NULL;
}

/* 
	This function take in a 'tmp' double pointer/array of strings, and
	- checks and return error if there are non integers in each string,
	- converts string of numbers into integers (E.g char* "123" ->int 123),
	- checks and return error if any numbers exceeded INT_MAX or INT_MIN,
	- create a new nodes in stack->a list and store the numbers into 
	  stack->a->data. 
	- finally, store the total number of nodes in stack->a into stack->size_a.
 */
void	insert_arg(t_stack *stack, int code, char **tmp)
{
	t_node	*head;
	long	n;

	error_non_integer(*tmp, code, stack);
	n = ft_atoi(*tmp++);
	if (n > INT_MAX || n < INT_MIN)
		exit_with_error(code, stack);
	head = ps_lstnew(n);
	stack->a = head;
	while (*tmp)
	{
		error_non_integer(*tmp, code, stack);
		n = ft_atoi(*tmp++);
		if (n > INT_MAX || n < INT_MIN)
			exit_with_error(code, stack);
		head->next = ps_lstnew(n);
		head = head->next;
	}
	stack->size_a = ps_lstsize(stack->a);
}

/* 
	This function free the memories allocated for a double pointer/array.
 */
void	free2d(char **array)
{
	char	**temp;

	temp = array;
	while (temp != NULL && *temp != NULL)
	{
		free(*temp);
		++temp;
	}
	free(array);
}
