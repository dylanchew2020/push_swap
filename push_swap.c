/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:49:38 by lchew             #+#    #+#             */
/*   Updated: 2023/03/04 18:56:27 by lchew            ###   ########.fr       */
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
	insert_arg(&stack, argc, argv);
	while (stack.a)
	{
		printf("%i\n", stack.a->data);
		stack.a = stack.a->next;
	}
	printf("%i\n", stack.size);
	return (0);
}

void	stack_init(t_stack *stack)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->size = 1;
	stack->tmp_array = NULL;
}

void	insert_arg(t_stack *stack, int argc, char **argv)
{
	t_node	*head;

	if (argc == 2)
	{
		stack->tmp_array = ft_split(*(++argv), ' ');
		head = ps_lstnew(ft_atoi(*stack->tmp_array++));
		stack->a = head;
		while (*stack->tmp_array)
		{
			++stack->size;
			head->next = ps_lstnew(ft_atoi(*stack->tmp_array++));
			head = head->next;
		}
	}
	else
	{
		++argv;
		head = ps_lstnew(ft_atoi(*argv++));
		stack->a = head;
		while (*argv)
		{
			++stack->size;
			head->next = ps_lstnew(ft_atoi(*argv++));
			head = head->next;
		}
	}
}
