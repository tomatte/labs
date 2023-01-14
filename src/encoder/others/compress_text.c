/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:17:06 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/14 10:29:19 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../encoder.h"

static void	ft_str_push_uchar(unsigned char **str, unsigned char c)
{
	size_t	len;
	unsigned char	*s;
	unsigned char	*new;

	s = *str;
	if (!str)
		return ;
	if (!s)
		s = (unsigned char *) ft_strdup("");
	len = ft_strlen((char *) s);
	new = (unsigned char *) malloc(len + 2);
	if (!new)
		return ;
	ft_memmove(new, s, len + 1);
	new[len] = c;
	new[len + 1] = '\0';
	free(s);
	*str = new;
}

static void	get_first_char(unsigned char **bits, char *binary)
{
	int	i;

	i = strlen(binary);
	while (i >= 8)
		i -= 8;
	if (i == 0)
		i = 255;
	ft_str_push_uchar(bits, (unsigned char) i);
}

void	print_compressed_bin(unsigned char *compressed)
{
	unsigned char	*bits;
	int				size;
	int				i;
	int				j;

	ft_memmove(&size, compressed, sizeof(int));
	bits = (unsigned char *) malloc(sizeof(char) * (size));
	ft_memmove(bits, compressed + sizeof(int), size);
	printf("\nsize: %d\n", size);
	i = 1;
	printf("compressed: ");
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

static unsigned char	*encapsulate_compressed_data(unsigned char *bits, int size)
{
	unsigned char	*encapsulated;

	encapsulated = (unsigned char *) malloc(sizeof(char) * size + sizeof(int));
	if (!encapsulated)
	{
		printf("Encapsulated malloc failed.\n");
		exit(1);
	}
	ft_memmove(encapsulated, &size, sizeof(int));
	ft_memmove(encapsulated + sizeof(int),  bits, size);
	free(bits);
	return (encapsulated);
}

static void	init_vars(unsigned char **bits, int *i, unsigned char *n, int *size)
{
	*bits = NULL;
	*i = 0;
	*n = 0;
	*size = 0;
}

unsigned char	*compress_text(t_lst *frequency, char *text)
{
	char			*binary;
	unsigned char	*bits;
	unsigned char	n;
	int				size;
	int				i;
	int				j;

	binary = encode_to_binary(frequency, text);
	init_vars(&bits, &i, &n, &size);
	get_first_char(&bits, binary);
	while (binary[i])
	{
		j = 7;
		while (j >= 0 && binary[i])
		{
			if (binary[i] == '1')
				n = n | (1 << j);
			j--;
			i++;
		}
		ft_str_push_uchar(&bits, n);
		size++;
		n = 0;
	}
	free(binary);
	return (encapsulate_compressed_data(bits, size + 1));
}
