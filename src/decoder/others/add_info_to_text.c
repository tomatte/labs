/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_info_to_text.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:40:12 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/13 13:58:57 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../decoder.h"

static void	join_and_free(char **text, char *str)
{
	char	*new;

	new = ft_strjoin(*text, str);;
	free(*text);
	free(str);
	*text = new;
}

void	add_info_to_text(char **text, unsigned char *data)
{
	char	*info;
	int		size_compressed;
	int		size_text;

	ft_memmove(&size_compressed, data, sizeof(int));
	size_text = strlen(*text);
	info = strdup("\n\n-------- INFORMATION ABOUT DECODING PROCESS --------\nText full size: ");
	join_and_free(&info, ft_itoa(size_text));
	join_and_free(&info, strdup("\nCompressed size: "));
	join_and_free(&info, ft_itoa(size_compressed));
	join_and_free(&info, strdup("\n-------------------------------------------------------\n"));
	join_and_free(text, info);
}
