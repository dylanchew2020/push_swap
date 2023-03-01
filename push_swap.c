/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:49:38 by lchew             #+#    #+#             */
/*   Updated: 2023/03/01 18:59:50 by lchew            ###   ########.fr       */
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
	stack.a = ft_lstnew(argv[i]);
	printf("%s\n", stack.a->content);
	return (0);
}

void	stack_init(t_stack *stack)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->size = 0;
}
