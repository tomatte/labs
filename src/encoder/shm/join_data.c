/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:40:21 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/12 09:44:40 by dbrandao         ###   ########.fr       */
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

void	join_data(unsigned char *compressed, t_lst *frequency, unsigned char **data, int *size_data)
{
	char	**codes;
	char	*letters;
	int		size_codes;
	int		size_letters;
	int		size_compressed;
	int		position;

	codes = create_code_array(frequency);
	size_codes = get_codes_size(codes, lst_size(frequency));
	size_letters = lst_size(frequency) + 1;
	size_compressed = get_size_compressed(compressed); //testar
	letters = create_letter_array(frequency);
	*data = alloc_or_die(size_compressed + size_letters + size_codes);
	ft_memmove((*data), compressed, size_compressed);
	position = size_compressed;
	ft_memmove((*data) + position, letters, size_letters);
	position += size_letters;
	add_codes_to_data(data, codes, lst_size(frequency), position);
	*size_data = size_codes + size_letters + size_compressed;
}
