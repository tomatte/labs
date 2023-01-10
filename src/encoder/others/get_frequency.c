/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_frequency.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:39:19 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/10 10:22:58 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../encoder.h"

static char	*get_text(char *filename)
{
	int		fd;
	char	*text;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	text = read_file(fd);
	return (text);
}

t_lst	*get_frequency(char *filename)
{
	char	*text;
	int		i;
	t_lst	*frequency;
	t_lst	*node;

	text = get_text(filename);
	if (!text || !*text)
		return (NULL);
	frequency = lst_new(*text);
	i = 1;
	while (text[i])
	{
		node = lst_find(frequency, text[i]);
		if (!node)
			lst_push(frequency, lst_new(text[i]));
		else
			node->times++;
		i++;
	}
	free(text);
	return (frequency);
}
