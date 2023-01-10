/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:44:58 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/09 23:14:52 by dbrandao         ###   ########.fr       */
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
		printf("%c\t(%d)\n", lst->c, lst->times);
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

int	main(int argc, char **argv)
{
	t_lst	*frequency;
	t_tree	**nodes;

	if (argc <= 1)
		exit_error();
	frequency = get_frequency(argv[1]);
	nodes = get_nodes(frequency);
	print_nodes(nodes, lst_size(frequency));
	return (0);
}
