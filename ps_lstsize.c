/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:13:13 by lchew             #+#    #+#             */
/*   Updated: 2023/03/04 18:00:31 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Counts the number of nodes in a list.
**
**	Returns the length of the list.
*/
int	ps_lstsize(t_node *node)
{
	unsigned int	count;

	count = 0;
	if (!node)
		return (0);
	while (node)
	{
		node = node->next;
		++count;
	}
	return (count);
}
