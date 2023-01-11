/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:40:21 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/11 18:17:47 by dbrandao         ###   ########.fr       */
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

static void	add_codes_to_data(char **data, char **codes, int size, int position)
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

void	join_data(char *binary, t_lst *frequency, char **data, int *data_size)
{
	char	**codes;
	char	*letters;
	int		size_codes;
	int		size_letters;
	int		size_binary;
	int		position;

	codes = create_code_array(frequency);
	size_codes = get_codes_size(codes, lst_size(frequency));
	size_letters = lst_size(frequency) + 1;
	size_binary = ft_strlen(binary) + 1;
	letters = create_letter_array(frequency);
	*data = (char *) malloc(size_binary + size_letters + size_codes);
	if (!*data)
		return ;
	position = 0;
	ft_memmove((*data) + position, binary, size_binary);
	position += size_binary;
	ft_memmove((*data) + position, letters, size_letters);
	position += size_letters;
	add_codes_to_data(data, codes, lst_size(frequency), position);
	*data_size = size_codes + size_letters + size_binary;
}
