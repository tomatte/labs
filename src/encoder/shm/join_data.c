/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:40:21 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/15 14:07:11 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../encoder.h"

static void	print_codes(char **codes, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("codes[%d]: %s\n", i, codes[i]);
	}
	printf("array size: %d\n", size);
}

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

static void	add_codes_to_data(unsigned char **data, char **codes, int size, int position)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_memmove((*data) + position, codes[i], strlen(codes[i]) + 1);
		position += strlen(codes[i]) + 1;
		i++;
	}
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

static void	clear_data(char *letters, char **codes, int size)
{
	int	i;

	free(letters);
	i = 0;
	while (i < size)
	{
		free(codes[i]);
		i++;
	}
	free(codes);
}

static void	print_nodes_copy(t_tree *nodes_copy, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("node_copy: %c\t(%d)\n", nodes_copy[i].c, nodes_copy[i].times);
		i++;
	}
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
