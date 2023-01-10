/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:55:51 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/09 20:57:37 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../encoder.h"

t_lst	*lst_find(t_lst *lst, char c)
{
	while (lst)
	{
		if (lst->c == c)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
