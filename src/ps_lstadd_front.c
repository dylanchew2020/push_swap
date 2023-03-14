/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:44:18 by lchew             #+#    #+#             */
/*   Updated: 2023/03/04 18:03:16 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Adds the node 'new' at the beginning of the list.
*/
void	ps_lstadd_front(t_node **node, t_node *new)
{
	new->next = *node;
	*node = new;
}
