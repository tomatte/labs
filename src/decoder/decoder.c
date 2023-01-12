/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:15:34 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/12 18:42:31 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./decoder.h"

static void	print_dic(t_lst *dic)
{
	while (dic)
	{
		printf("%c\t(%s)\n", dic->c, dic->code);
		dic = dic->next;
	}
}

static void	clear_all(t_lst *lst, void *text)
{
	lst_clear(lst);
	free(text);
}

int	main(void)
{
	unsigned char	*data;
	char			*text;
	t_lst			*dictionary;

	read_memory(&data);
	dictionary = recreate_dictionary(data);
	text = decode_text(data, dictionary);
	finalize_shm(data, text);
	clear_all(dictionary, (void *) text);
	return (0);
}
