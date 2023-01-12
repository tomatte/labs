/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recreate_dictionary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:30:28 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/12 09:50:06 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../decoder.h"

static t_lst	*get_letters(char *data)
{
	t_lst	*dictionary;
	char	*letters;
	int		i;

	letters = data + strlen(data) + 1;
	i = 0;
	dictionary = lst_new(letters[i]);
	while (letters[++i])
		lst_push(dictionary, lst_new(letters[i]));
	return (dictionary);
}

static void	asign_codes(char *data, t_lst *dictionary)
{
	int	num;
	int	i;

	data += strlen(data) + 1;
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
