/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:07:52 by lchew             #+#    #+#             */
/*   Updated: 2022/06/01 14:07:52 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Deletes and frees the given node and every successor of that node, 
**	using the function 'del' and free(3).
**
**	Finally, the pointer to the list must be set to NULL.
*/
void	ps_lstclear(t_node **node)
{
	t_node	*temp;
	t_node	*current;

	if (!node)
		return ;
	current = *node;
	while (current)
	{
		temp = current;
		current = current->next;
		ps_lstdelone(temp);
	}
	*node = NULL;
}
