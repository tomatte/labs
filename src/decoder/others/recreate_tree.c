/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recreate_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:58:30 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/15 14:28:39 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../decoder.h"

static int	get_size_compressed(unsigned char *compressed)
{
	int	size_compressed;

	ft_memmove(&size_compressed, compressed, sizeof(int));
	size_compressed += sizeof(int);
	return (size_compressed);
}

static t_tree	**get_nodes_from_data(void *data, int *len)
{
	t_tree	*nodes;
	t_tree	**nodes_array;
	int		size_nodes;
	int		i;

	data += get_size_compressed((unsigned char *) data);
	ft_memmove(len, data, sizeof(int));
	data += sizeof(int);
	size_nodes = sizeof(t_tree) * (*len);
	nodes = (t_tree *) malloc(size_nodes);
	ft_memmove(nodes, data, size_nodes);
	nodes_array = (t_tree **) malloc(sizeof(t_tree *) * (*len));
	if (!nodes_array)
		return (NULL);
	i = 0;
	while (i < *len)
	{
		nodes_array[i] = &nodes[i];
		i++;
	}
	return (nodes_array);
}

t_tree	*recreate_tree(void *data)
{
	t_tree	**nodes;
	t_tree	*node;

	int		len_nodes;

	nodes = get_nodes_from_data(data, &len_nodes);
	while (len_nodes >= 2)
	{
		node = new_node(0, nodes[0]->times + nodes[1]->times);
		node->left = nodes[0];
		node->right = nodes[1];
		nodes++;
		nodes[0] = node;
		len_nodes--;
		order_nodes(nodes, len_nodes);
	}
	return (nodes[0]);
}
