/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:25:54 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/09 23:27:25 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../encoder.h"

void	order_nodes(t_tree **nodes, int size)
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
