/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:11:35 by lchew             #+#    #+#             */
/*   Updated: 2023/03/16 12:32:41 by lchew            ###   ########.fr       */
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
		printf("test %s\n", *argv);
		stack.str_arg = ft_split(*(++argv), ' ');
		if (stack.str_arg == NULL)
			return (2);
		insert_arg(&stack, 1, stack.str_arg);
		free2d(stack.str_arg);
	}
	else
		insert_arg(&stack, 0, ++argv);
	get_median(&stack, stack.a, stack.size_a);
	operation(&stack);
	if (check_sort_a(stack.a, stack.size_a) == 0 && stack.b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ps_lstclear(&stack.a);
	return (0);
}

void	operation(t_stack *stack)
{
	char	*stdin;
	int		cs;
	int		cr;

	cs = 0;
	cr = 0;
	stdin = get_next_line(0);
	while (1)
	{
		if (stdin == NULL || *stdin == '\n')
			break ;
		if (ft_strncmp(stdin, "Error!\n", 8) == 0)
			exit_with_error(0, stack);
		cs = checker_sort(stack, stdin);
		cr = checker_rotate(stack, stdin);
		if (cs == 0 && cr == 0)
			exit_with_error(0, stack);
		free(stdin);
		stdin = get_next_line(0);
	}
	free(stdin);
}

int	checker_sort(t_stack *stack, char *stdin)
{
	int	i;

	i = 0;
	if (ft_strncmp(stdin, "sa\n", 4) == 0)
		i = checker_sa(stack);
	else if (ft_strncmp(stdin, "sb\n", 4) == 0)
		i = checker_sb(stack);
	else if (ft_strncmp(stdin, "ss\n", 4) == 0)
		i = checker_ss(stack);
	else if (ft_strncmp(stdin, "pa\n", 4) == 0)
		i = checker_pa(stack);
	else if (ft_strncmp(stdin, "pb\n", 4) == 0)
		i = checker_pb(stack);
	return (i);
}

int	checker_rotate(t_stack *stack, char *stdin)
{
	int	i;

	i = 0;
	if (ft_strncmp(stdin, "ra\n", 4) == 0)
		i = checker_ra(stack);
	else if (ft_strncmp(stdin, "rb\n", 4) == 0)
		i = checker_rb(stack);
	else if (ft_strncmp(stdin, "rr\n", 4) == 0)
		i = checker_rr(stack);
	else if (ft_strncmp(stdin, "rra\n", 4) == 0)
		i = checker_rra(stack);
	else if (ft_strncmp(stdin, "rrb\n", 4) == 0)
		i = checker_rrb(stack);
	else if (ft_strncmp(stdin, "rrr\n", 4) == 0)
		i = checker_rrr(stack);
	return (i);
}
