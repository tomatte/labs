/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:21:02 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/09 23:49:58 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../encoder.h"

t_tree	*create_tree(t_tree **nodes, int size)
{
	t_tree	*node;
	int		i;

	while (size >= 2)
	{
		node = new_node(0, nodes[0]->times + nodes[1]->times);
		node->left = nodes[0];
		node->right = nodes[1];
		nodes++;
		nodes[0] = node;
		size--;
		order_nodes(nodes, size);
	}
	return (nodes[0]);
}
