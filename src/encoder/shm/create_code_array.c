/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_code_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:25:40 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/13 15:52:21 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../encoder.h"

static void	fill_codes(char **codes, t_lst *frequency)
{
	int	i;

	i = 0;
	while (frequency)
	{
		codes[i] = ft_strdup(frequency->code);
		i++;
		frequency = frequency->next;
	}
}

char	**create_code_array(t_lst *frequency)
{
	int	size;
	char	**codes;

	size = lst_size(frequency);
	codes = (char **) malloc(sizeof(char *) * size);
	if (!codes)
		return (NULL);
	fill_codes(codes, frequency);
	return (codes);
}
