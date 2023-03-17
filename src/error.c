/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:31:27 by lchew             #+#    #+#             */
/*   Updated: 2023/03/17 18:11:52 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Checks if the given argument is a valid integer, and exits with an error if it
** is not. Specifically, the function checks if the argument contains only digits
** or a single leading negative sign, and if the argument is not empty.
**
** Parameters:
** - arg: the argument to be checked
** - code: to pass in to error to free stack-><str_arg if code is greater than 1.
** - stack: a pointer to the stack structure
*/
void	error_non_integer(char *arg, int code, t_stack *stack)
{
	int	i;

	i = 0;
	if (*arg == '\0')
		exit_with_error(code, stack);
	if (arg[i] == '-' && arg[i + 1] == '\0')
		exit_with_error(code, stack);
	while (arg[i] != '\0')
	{
		if ((arg[i] < '0' || arg[i] > '9') && arg[i] != '-')
			exit_with_error(code, stack);
		++i;
		if (arg[i] == '-')
			exit_with_error(code, stack);
	}
}

/*
** Prints an error message and exits the program with a specified error code.
** Frees the allocated memory before exiting.
**
** Parameters:
** - code: free stack-><str_arg if code is greater than 1.
** - stack: a pointer to the stack structure containing the allocated memory
*/
void	exit_with_error(int code, t_stack *stack)
{
	ft_putstr_fd("Error\n", 2);
	if (code >= 1)
		free2d(stack->str_arg);
	ps_lstclear(&stack->a);
	exit(0);
}
