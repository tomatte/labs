/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:17:06 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/12 08:30:30 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../encoder.h"

static char	*join_and_free(char *s1, char *s2)
{
	char	*big;

	if (!s1 || !s2)
		return (NULL);
	big = ft_strjoin(s1, s2);
	free(s1);
	return (big);
}

char	*encode_text(t_lst *frequency, char *text)
{
	char	*encoded;

	encoded = strdup("");
	while (*text)
	{
		encoded = join_and_free(encoded, lst_find(frequency, *text)->code);
		text++;
	}
	return (encoded);
}

static void	ft_str_push_uchar(unsigned char **str, unsigned char c)
{
	size_t	len;
	unsigned char	*s;
	unsigned char	*new;

	s = *str;
	if (!str)
		return ;
	if (!s)
		s = ft_strdup("");
	len = ft_strlen(s);
	new = (unsigned char *) malloc(len + 2);
	if (!new)
		return ;
	ft_strlcpy(new, s, len + 1);
	new[len] = c;
	new[len + 1] = '\0';
	free(s);
	*str = new;
}

static void	init_vars(unsigned char **bits, int *i, unsigned char *n, int *size)
{
	*bits = NULL;
	*i = 0;
	*n = 0;
	*size = 0;
}

static void	get_first_char(unsigned char **bits, char *binary)
{
	int	i;

	i = strlen(binary);
	while (i >= 8)
		i -= 8;
	ft_str_push_uchar(bits, (unsigned char) i);
}

static void	print_compressed_bin(unsigned char *bits, int size)
{
	int	i;
	int	j;

	//printing compressed binary
	//this structure can be used to read the compressed binary
	i = 1;
	printf("compressed: ");
	while (i <= size)
	{
		j = 7;
		while (j >= 0)
		{
			if (bits[0] == 0 && i == size)
				break ;
			if (i == size)
				bits[0]--;
			if (bits[i] & (1 << j))
				printf("1");
			else
				printf("0");
			j--;
		}
		if (bits[0] == 0 && i == size)
			break ;
		i++;
	}
}

static char	*encapsulate_compressed_data(unsigned char *bits, int size)
{
	char	*encapsulated;

	encapsulated =(char *) malloc(sizeof(char) * size + sizeof(int));
	if (!encapsulated)
	{
		printf("Encapsulated malloc failed.\n");
		exit(1);
	}
	ft_memmove(encapsulated, &size, sizeof(int));
	ft_memmove(encapsulated + sizeof(int),  bits, size);
	return (encapsulated);
}

char	*encode_to_char(t_lst *frequency, char *text)
{
	char			*binary;
	unsigned char	*bits;
	unsigned char	n;
	int				size;
	int				i;
	int				j;

	binary = encode_text(frequency, text);
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
	return (encapsulate_compressed_data(bits, size + 1));
}
