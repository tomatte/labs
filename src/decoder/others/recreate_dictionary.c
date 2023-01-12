/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recreate_dictionary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:30:28 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/12 09:59:45 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../decoder.h"

static int	get_position(unsigned char *data)
{
	int	position;

	ft_memmove(&position, data, sizeof(int));
	position += sizeof(int);
	return (position);
}

static t_lst	*get_letters(unsigned char *data)
{
	t_lst	*dictionary;
	char	*letters;
	int		i;
	int		position;

	position = get_position(data);
	letters = data + position;
	i = 0;
	dictionary = lst_new(letters[i]);
	while (letters[++i])
		lst_push(dictionary, lst_new(letters[i]));
	return (dictionary);
}

static void	asign_codes(unsigned char *data, t_lst *dictionary)
{
	int	position;
	int	num;
	int	i;

	position = get_position(data);
	data += position;
	num = strlen(data);
	data += strlen(data) + 1;
	i = 0;
	while (i < num)
	{
		dictionary->code = ft_strdup(data);
		dictionary = dictionary->next;
		data += ft_strlen(data) + 1;
		i++;
	}
}

t_lst	*recreate_dictionary(unsigned char *data)
{
	t_lst	*dictionary;

	dictionary = get_letters(data);
	asign_codes(data, dictionary);
	return (dictionary);
}
