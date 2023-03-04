/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:00:27 by lchew             #+#    #+#             */
/*   Updated: 2022/06/01 14:00:27 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Takes as a parameter a node and frees the memory of the node’s content 
**	using the function 'del' given as a parameter and free the node. 
**
**	The memory of 'next' must not be freed.
*/
void	ps_lstdelone(t_node *node, void (*del)(int))
{
	if (!node)
		return ;
	del(node->data);
	free(node);
}
