/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:21:04 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/09 23:17:19 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../encoder.h"

t_tree	*new_node(char c, int times)
{
	t_tree	*node;

	node = (t_tree *) malloc(sizeof(t_tree));
	if (!node)
		return (NULL);
	node->c = c;
	node->times = times;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
