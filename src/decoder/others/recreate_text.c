/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recreate_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:47:08 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/15 13:50:56 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../decoder.h"

static char	*mount_tree_text(t_tree *tree, unsigned char *compressed)
{
	unsigned char	*bits;
	t_tree			*node;
	char			*text;
	int				size;
	int				i;
	int				j;

	ft_memmove(&size, compressed, sizeof(int));
	bits = (unsigned char *) malloc(sizeof(char) * (size));
	ft_memmove(bits, compressed + sizeof(int), size);
	node = tree;
	text = strdup("");
	i = 1;
	while (i < size)
	{
		j = 7;
		while (j >= 0)
		{
			if (bits[0] == 0 && i == size - 1)
				break ;
			if (i == size - 1)
				bits[0]--;
			if (bits[i] & (1 << j))
				node = node->right;
			else
				node = node->left;
			if (!node->left && !node->right)
			{
				ft_str_push_char(&text, node->c);
				node = tree;
			}
			j--;
		}
		if (bits[0] == 0 && i == size - 1)
			break ;
		i++;
	}
	return (text);
}

char	*recreate_text(t_tree *tree, unsigned char *data)
{
	char	*text;
	int		size;
	int		i;
	int		j;

	text = mount_tree_text(tree, data);
	return (text);
}
