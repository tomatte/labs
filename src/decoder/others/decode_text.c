/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:22:04 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/11 19:05:51 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../decoder.h"

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

char	*decode_text(char *data, t_lst *dictionary)
{
	char	*binary;
	char	*text;
	int		i;
	int		size;
	int		min;

	binary = ft_strdup(data);
	text = strdup("");
	min = get_minimum_size(dictionary);
	i = 0;
	size = min;
	printf("min: %d\n", min);
	while (*binary)
	{
		while (!find_letter(dictionary, binary, &size))
			size++;
		ft_str_push_char(&text, find_letter(dictionary, binary, &size));
		binary += size;
		size = min;
	}
	return (text);
}
