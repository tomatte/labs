/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:11:26 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/09 23:18:04 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../encoder.h"

static t_tree	**get_nodes_from_lst(t_lst *lst)
{
	t_tree	**nodes;
	int		size;
	int		i;
	t_tree	*test;

	size = lst_size(lst);
	nodes = (t_tree **) malloc(sizeof(t_tree *) * size);
	i = 0;
	while (i < size)
	{
		nodes[i] = new_node(lst->c, lst->times);
		i++;
		lst = lst->next;
	}
	return (nodes);
}

static void	order_nodes(t_tree **nodes, int size)
{
	t_tree	*aux;
	int		i;
	int		z;

	i = 0;
	while (i < size - 1)
	{
		z = i + 1;
		while (z < size)
		{
			if (nodes[i]->times > nodes[z]->times)
			{
				aux = nodes[i];
				nodes[i] = nodes[z];
				nodes[z] = aux;
			}
			z++;
		}
		i++;
	}
}

t_tree	**get_nodes(t_lst *frequency)
{
	t_tree	**nodes;
	int		size;

	size = lst_size(frequency);
	nodes = get_nodes_from_lst(frequency);
	order_nodes(nodes, size);
	return (nodes);
}
