/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nodes_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:25:27 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/15 14:32:07 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../encoder.h"

t_tree	*get_nodes_copy(t_tree **nodes, int size)
{
	t_tree	*nodes_copy;
	int		i;

	nodes_copy = (t_tree *) malloc(sizeof(t_tree) * size);
	if (!nodes_copy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ft_memmove(&nodes_copy[i], nodes[i], sizeof(t_tree));
		i++;
	}
	return (nodes_copy);
}
