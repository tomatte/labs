/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:41:48 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/09 20:45:14 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../encoder.h"

t_lst	*lst_new(char c)
{
	t_lst	*new;

	new = (t_lst *) malloc(sizeof(t_lst));
	new->c = c;
	new->times = 1;
	new->next = NULL;
	return (new);
}
