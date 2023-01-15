/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:44:58 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/15 12:42:17 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./encoder.h"

static void	exit_error(void)
{
	printf("Needs a filename!\n");
	exit(1);
}

static void	print_lst(t_lst *lst)
{
	while (lst)
	{
		printf("%c\t(%d)\tcode: %s\n", lst->c, lst->times, lst->code);
		lst = lst->next;
	}
}

static void	print_nodes(t_tree **nodes, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%c\t(%d)\n", nodes[i]->c, nodes[i]->times);
		i++;
	}
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

static void	clear_all(t_lst *lst, t_tree *tree, t_tree **nodes, char *text, void *compressed)
{
	free(text);
	free(nodes);
	lst_clear(lst);
	clear_tree(tree);
	free(compressed);
}

int	main(int argc, char **argv)
{
	unsigned char	*compressed;
	unsigned char	*text;
	t_segment		segment;
	t_lst			*frequency;
	t_tree			**nodes;
	t_tree			*master;
	t_tree			*nodes_copy;

	if (argc <= 1)
		exit_error();
	text = get_text(argc, argv);
	frequency = get_frequency(text);
	nodes = get_nodes(frequency);
	nodes_copy = get_nodes_copy(nodes, lst_size(frequency));
	master = create_tree(nodes, lst_size(frequency));
	huffman_code(master, ft_strdup(""), frequency);
	compressed = compress_text(frequency, text);
	share_memory(compressed, frequency, nodes_copy);
	segment = read_shm();
	verify_text_integrity(segment.mem, text);
	dettach_segment(segment);
	clear_all(frequency, master, nodes, text, compressed);
	return (0);
}
