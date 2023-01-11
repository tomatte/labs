/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:17:06 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/10 21:20:17 by dbrandao         ###   ########.fr       */
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

char	*encode_to_char(t_lst *frequency, char *text)
{
	char			*binary;
	unsigned char	*bits;
	unsigned char	n;
	int		size;
	int		i;
	int		len;
	int		j;

	binary = encode_text(frequency, text);
	size = strlen(binary) - 1;
	i = size + 1;
	while (i >= 8)
		i -= 8;
	bits = NULL;
	i = 0;
	n = 0;
	len = 0;
	while (size >= 0)
	{
		if (binary[size] == '1')
		{
			n = n | (1 << i);
		}
		i++;
		if (i >= 8)
		{
			add_char(&bits, n, len);
			len++;
			i = 0;
			n = 0;
		}
		size--;
	}
	printf("N: %d\n", n);
	i = 0;
	while (i < len)
	{
		printf("bit: %d\n", bits[i]);
		i++;
	}
	i = 0;
	while (i < len)
	{
		n = 0;
		while (n < 8)
		{
			if (bits[i] & (1 << n))
				printf("1");
			else
				printf("0");
			n++;
		}
		i++;
	}
	printf("\n%s\n", binary);
}
