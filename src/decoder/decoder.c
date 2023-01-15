/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:15:34 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/15 13:41:30 by dbrandao         ###   ########.fr       */
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

static void	print_tree(t_tree *tree)
{
	if (!tree)
		return ;
	if (tree->c > 0)
	{
		printf("%c\t(%d)\n", tree->c, tree->times);
	}
	print_tree(tree->left);
	print_tree(tree->right);
}

int	main(void)
{
	unsigned char	*data;
	t_tree			*tree;
	char			*text;
	t_lst			*dictionary;
	int				shmid;
	t_time			mtime;

	shmid = read_memory(&data);
	dictionary = recreate_dictionary(data);
	tree = recreate_tree((void *) data);

	print_tree(tree);
	shmdt(data);
	shmctl(shmid, IPC_RMID, NULL);

	mtime.start = clock();
	text = decode_text(data, dictionary);
	mtime.end = clock();
	add_info_to_text(&text, data, mtime);
	finalize_shm(data, text, shmid);
	clear_all(dictionary, (void *) text);
	return (0);
}
