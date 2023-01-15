/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:40:21 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/15 14:32:38 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../encoder.h"

int	get_codes_size(char **codes, int size)
{
	int	i;
	int	codes_size;

	i = 0;
	codes_size = 0;
	while (i < size)
	{
		codes_size += strlen(codes[i]) + 1;
		i++;
	}
	return (codes_size);
}

static unsigned char	*alloc_or_die(int size)
{
	unsigned char	*data;
	
	data = (unsigned char *) malloc(size);
	if (!data)
	{
		printf("Failed to alloc data in join_data.c\n");
		exit(1);
	}
	return (data);
}

static int	get_size_compressed(unsigned char *compressed)
{
	int	size_compressed;

	ft_memmove(&size_compressed, compressed, sizeof(int));
	size_compressed += sizeof(int);
	return (size_compressed);
}

void	join_data(unsigned char *compressed, t_lst *frequency, unsigned char **data, int *size_data, t_tree *nodes_copy)
{
	int		size_compressed;
	int		size_nodes;
	int		position;
	int		len_nodes;

	len_nodes = lst_size(frequency);
	size_nodes = sizeof(t_tree) * len_nodes;
	size_compressed = get_size_compressed(compressed); //testar
	*data = alloc_or_die(size_compressed + size_nodes + sizeof(int));
	ft_memmove((*data), compressed, size_compressed);
	position = size_compressed;
	ft_memmove((*data) + position, &len_nodes, sizeof(int));
	position += sizeof(int);
	ft_memmove((*data) + position, nodes_copy, size_nodes);
	*size_data = size_nodes + size_compressed + sizeof(int);
	free(nodes_copy);
}
