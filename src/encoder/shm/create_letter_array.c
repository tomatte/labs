/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_letter_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:44:49 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/11 14:48:22 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../encoder.h"

char	*create_letter_array(t_lst *frequency)
{
	char	*letters;
	int		i;

	letters = (char *) malloc(sizeof(char) * (lst_size(frequency) + 1));
	if (!letters)
		return (NULL);
	i = 0;
	while (frequency)
	{
		letters[i] = frequency->c;
		i++;
		frequency = frequency->next;
	}
	letters[i] = '\0';
	return (letters);
}
