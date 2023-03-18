/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:49:38 by lchew             #+#    #+#             */
/*   Updated: 2023/03/18 15:57:49 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_stack	stack;

	printf("test\n");
	if (argc < 2)
		return (0);
	stack_init(&stack);
	if (argc == 2)
	{
		if (argv[1][0] == '\0')
		{
			system("leaks push_swap");
			return (0);
		}
		stack.str_arg = ft_split(*(++argv), ' ');
		insert_arg(&stack, 1, stack.str_arg);
		free2d(stack.str_arg);
	}
	else
		insert_arg(&stack, 0, ++argv);
	get_median(&stack, stack.a, stack.size_a);
	sort_a(&stack, stack.size_a);
	ps_lstclear(&stack.a);
	return (0);
}
