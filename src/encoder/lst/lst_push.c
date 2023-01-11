/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:08:15 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/11 17:56:06 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../encoder.h"

void	lst_push(t_lst *lst, t_lst *node)
{
	if (!node || !lst)
		return ;
	while (lst->next)
		lst = lst->next;
	lst->next = node;
}
