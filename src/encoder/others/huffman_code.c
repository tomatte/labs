/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huffman_code.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 08:29:46 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/10 10:31:02 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../encoder.h"
#include <string.h>

static char	*join_and_free(char *s1, char *s2)
{
	char	*big;

	if (!s1 || !s2)
		return (NULL);
	big = ft_strjoin(s1, s2);
	free(s2);
	return (big);
}

void	huffman_code(t_tree *tree, char *bits, t_lst *lst)
{
	char	*aux;

	if (!tree)
		return ;
	if (!tree->left && !tree->right)
	{
		lst_find(lst, tree->c)->code = bits;
		return ;
	}
	huffman_code(tree->left, join_and_free(bits, strdup("0")), lst);
	huffman_code(tree->right, join_and_free(bits, strdup("1")), lst);
	free(bits);
}

/*

	bits == ""

	bits == "" + "0"
	free("")
	free("0")

	bits == "0" + "0"
	free2

	bits == "00" + "1"
	free2


  */