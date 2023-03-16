/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:31:27 by lchew             #+#    #+#             */
/*   Updated: 2023/03/16 12:41:06 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_non_integer(char *arg, int code, t_stack *stack)
{
	int	i;

	i = 0;
	if (*arg == '\0')
		exit_with_error(code, stack);
	while (arg[i] != '\0')
	{
		if ((arg[i] < '0' || arg[i] > '9') && arg[i] != '-')
			exit_with_error(code, stack);
		++i;
	}
}

void	exit_with_error(int code, t_stack *stack)
{
	ft_putstr_fd("Error!\n", 1);
	if (code >= 1)
		free2d(stack->str_arg);
	ps_lstclear(&stack->a);
	exit(0);
}
