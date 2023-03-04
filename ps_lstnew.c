/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:04:24 by lchew             #+#    #+#             */
/*   Updated: 2023/03/04 18:12:01 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Allocates (with malloc(3)) and returns a new node. The member variable 
**	'content' is initialized with the value of the parameter 'content'. 
**	The variable 'next' is initialized to NULL.
*/
t_node	*ps_lstnew(int data)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}
