/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:57:54 by lchew             #+#    #+#             */
/*   Updated: 2023/03/04 17:57:54 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Adds the node 'new' at the end of the list.
*/
void	ps_lstadd_back(t_node **node, t_node *new)
{
	t_node	*temp;

	if (!new)
		return ;
	if (!*node)
		*node = new;
	else
	{
		temp = *node;
		temp = ps_lstlast(temp);
		temp->next = new;
	}
}
