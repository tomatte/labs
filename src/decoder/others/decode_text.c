/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:22:04 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/13 09:31:28 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../decoder.h"

static void	str_bit_cmp(char *str, unsigned char *bits)
{

}

static char	find_letter(t_lst *dictionary, char *str, int *size)
{
	while (dictionary)
	{
		if (!ft_strncmp(str, dictionary->code, strlen(dictionary->code)))
		{
			*size = strlen(dictionary->code);
			return (dictionary->c);
		}
		dictionary = dictionary->next;
	}
	return ('\0');
}

int	get_minimum_size(t_lst *dictionary)
{
	int	size;

	if (!dictionary)
		return (0);
	size = strlen(dictionary->code);
	dictionary = dictionary->next;
	while (dictionary)
	{
		if (strlen(dictionary->code) < size)
			size = strlen(dictionary->code);
		dictionary = dictionary->next;
	}
	return (size);
}

static void	print_compressed_binary(unsigned char *compressed, int size)
{
	unsigned char	*bits;
	int				i;
	int				j;

	bits = (unsigned char *) malloc(sizeof(char) * (size));
	ft_memmove(bits, compressed, size);
	printf("\nsize: %d\n", size);
	i = 1;
	printf("Xcompressed: ");
	while (i < size)
	{
		j = 7;
		while (j >= 0)
		{
			if (bits[0] == 0 && i == size - 1)
				break ;
			if (i == size - 1)
				bits[0]--;
			if (bits[i] & (1 << j))
				printf("1");
			else
				printf("0");
			j--;
		}
		if (bits[0] == 0 && i == size - 1)
			break ;
		i++;
	}
	printf("\n");
}

static int	extract_compressed_data(unsigned char **compressed, unsigned char *data)
{
	int	size;

	ft_memmove(&size, data, sizeof(int));
	data += sizeof(int);
	*compressed = (unsigned char *) malloc(sizeof(char) * size);
	if (!*compressed)
	{
		printf("Failed to malloc compressed in decode_text.c\n");
		exit(1);
	}
	ft_memmove(*compressed, data, size);
}

static void	recreate_binary(char **binary, unsigned char *data)
{
	int	size;
	int	i;
	int	j;

	*binary = ft_strdup("");
	ft_memmove(&size, data, sizeof(int));
	data += sizeof(int);
	i = 1;
	while (i < size)
	{
		j = 7;
		while (j >= 0)
		{
			if (data[0] == 0 && i == size - 1)
				break ;
			if (i == size - 1)
				data[0]--;
			if (data[i] & (1 << j))
				ft_str_push_char(binary, '1');
			else
				ft_str_push_char(binary, '0');
			j--;
		}
		if (data[0] == 0 && i == size - 1)
			break ;
		i++;
	}
}

char	*decode_text(unsigned char *data, t_lst *dictionary)
{
	char			*binary;
	char			*ref;
	char			*text;
	int				i;
	int				size;
	int				min;

	text = strdup("");
	recreate_binary(&binary, data);
	ref = binary;
	min = get_minimum_size(dictionary);
	i = 0;
	size = min;
	while (*binary)
	{
		while (!find_letter(dictionary, binary, &size))
			size++;
		ft_str_push_char(&text, find_letter(dictionary, binary, &size));
		binary += size;
		size = min;
	}
	free(ref);
	return (text);
}
