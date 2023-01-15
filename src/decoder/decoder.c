/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:15:34 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/15 14:37:40 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./decoder.h"

int	main(void)
{
	unsigned char	*data;
	t_tree			*tree;
	char			*text;
	int				shmid;
	t_time			mtime;

	shmid = read_memory(&data);
	mtime.start = clock();
	tree = recreate_tree((void *) data);
	text = recreate_text(tree, data);
	mtime.end = clock();
	add_info_to_text(&text, data, mtime);
	finalize_shm(data, text, shmid);
	free(text);
	return (0);
}
