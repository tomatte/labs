/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_frequency.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:39:19 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/10 12:15:14 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../encoder.h"

t_lst	*get_frequency(char *text)
{
	int		i;
	t_lst	*frequency;
	t_lst	*node;

	frequency = lst_new(*text);
	i = 1;
	while (text[i])
	{
		node = lst_find(frequency, text[i]);
		if (!node)
			lst_push(frequency, lst_new(text[i]));
		else
			node->times++;
		i++;
	}
	return (frequency);
}
