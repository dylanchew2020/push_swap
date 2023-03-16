/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:49:38 by lchew             #+#    #+#             */
/*   Updated: 2023/03/16 12:57:11 by lchew            ###   ########.fr       */
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
		if (argv[1][0] == '\0')
			return (2);
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
