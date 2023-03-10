/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:49:38 by lchew             #+#    #+#             */
/*   Updated: 2023/03/14 18:12:53 by lchew            ###   ########.fr       */
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
	{
		stack.str_arg = ft_split(*(++argv), ' ');
		insert_arg(&stack, 1, stack.str_arg);
		free2d(stack.str_arg);
	}
	else
		insert_arg(&stack, 0, ++argv);
	sort_a(&stack, stack.size_a);
	ps_lstclear(&stack.a);
	return (0);
}

void	stack_init(t_stack *stack)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->size_a = 0;
	stack->size_b = 0;
	stack->str_arg = NULL;
	stack->multi_arg = NULL;
}

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
		if (n > INT_MAX)
			exit_with_error(code, stack);
		head->next = ps_lstnew(n);
		head = head->next;
	}
	stack->size_a = ps_lstsize(stack->a);
}

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
