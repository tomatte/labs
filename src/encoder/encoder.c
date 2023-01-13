/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:44:58 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/13 12:12:33 by dbrandao         ###   ########.fr       */
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

static void	clear_all(t_lst *lst, t_tree *tree, t_tree **nodes, char *text, char *compressed)
{
	free(text);
	free(nodes);
	lst_clear(lst);
	clear_tree(tree);
	free(compressed);
}

int	main(int argc, char **argv)
{
	t_lst	*frequency;
	t_tree	**nodes;
	t_tree	*master;
	char	*text;
	char	*compressed;

	if (argc <= 1)
		exit_error();
	text = get_text(argc, argv);
	frequency = get_frequency(text);
	nodes = get_nodes(frequency);
	master = create_tree(nodes, lst_size(frequency));
	huffman_code(master, ft_strdup(""), frequency);
	//print_lst(frequency);
	compressed = compress_text(frequency, text);
	//encode_to_char(frequency, text);
	//printf("encoded: %s\n", encoded);
	share_memory(compressed, frequency);
	clear_all(frequency, master, nodes, text, compressed);
	//print_tree(master);
	return (0);
}
