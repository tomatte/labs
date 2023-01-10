/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:08:15 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/09 21:11:09 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../encoder.h"

void	lst_push(t_lst *lst, t_lst *node)
{
	if (!lst || !node)
		return ;
	while (lst->next)
		lst = lst->next;
	lst->next = node;
}
