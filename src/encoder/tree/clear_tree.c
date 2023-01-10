/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:15:32 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/10 10:19:38 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../encoder.h"

void	clear_tree(t_tree *tree)
{
	t_tree	*left;
	t_tree	*right;

	if (!tree)
		return;
	if (!tree->left && !tree->right)
	{
		free(tree);
		return ;
	}
	left = tree->left;
	right = tree->right;
	free(tree);
	clear_tree(left);
	clear_tree(right);
}
