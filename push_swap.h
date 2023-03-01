/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:49:36 by lchew             #+#    #+#             */
/*   Updated: 2023/03/01 15:55:01 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include "libft/includes/ft_printf.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}				t_node;

/* 
	t_node *a - stores the address of the first node (HEAD) in stack a.
	t_node *b - stores the address of the first node (HEAD) in stack b.
	int size - total number of nodes in stack a & b.
 */
typedef struct s_stack
{
	t_node	*a;
	t_node	*b;
	int		size;
}				t_stack;

#endif