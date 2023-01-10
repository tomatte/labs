/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:10:02 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/10 10:14:39 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../encoder.h"

void	lst_clear(t_lst *lst)
{
	t_lst	*aux;

	while (lst)
	{
		aux = lst;
		lst = lst->next;
		free(aux->code);
		free(aux);
	}
}
