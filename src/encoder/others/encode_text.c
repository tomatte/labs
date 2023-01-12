/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:17:06 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/11 23:19:30 by dbrandao         ###   ########.fr       */
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

static void	add_char(unsigned char **bits, char n, int size)
{
	unsigned char	*new;

	if (!*bits)
	{
		*bits = (unsigned char *) malloc(sizeof(unsigned char));
		**bits = n;
		return ;
	}
	new = (unsigned char *) malloc(sizeof(unsigned char) * (size + 1));
	if (!new)
		return ;
	ft_memcpy(new, *bits, size);
	new[size] = n;
	free(*bits);
	*bits = new;
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


char	*encode_to_char(t_lst *frequency, char *text)
{
	char			*binary;
	unsigned char	*bits;
	unsigned char	n;
	int				size;
	int				i;
	int				j;

	binary = encode_text(frequency, text);
	size = strlen(binary) - 1;
	bits = NULL;
	i = size + 1;
	while (i >= 8)
		i -= 8;
	printf("enquanto i: %d\n", i);
	ft_str_push_uchar(&bits, i);
	i = 0;
	n = 0;
	size = 0;
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


	//printing unsigned chars
	i = 0;
	while (bits[i])
	{
		printf("%d\t", bits[i]);
		i++;
	}
	printf("\n");
	printf("size: %d\n", size);
	//printing compressed binary
	//this structure can be used to read the compressed binary
	i = 1;
	printf("first byte: %d\n", bits[0]);
	while (bits[i])
	{
		size--;
		j = 7;
		while (j >= 0)
		{
			if (bits[0] == 0)
				break ;
			if (size == 0)
				bits[0]--;
			if (bits[i] & (1 << j))
				printf("1");
			else
				printf("0");
			j--;
		}
		if (bits[0] == 0)
			break ;
		i++;
	}

	printf("\nbinary: %s\n", binary);
	printf("N: %d\n", n);
}

/* 

 01010100
 */