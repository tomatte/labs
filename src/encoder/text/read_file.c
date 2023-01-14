/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:18:58 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/09 22:01:26 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../encoder.h"

static void	mem_clear(void **p)
{
	if (*p)
	{
		free(*p);
		*p = NULL;
	}
}

static char	*join_and_free(char *s1, char *s2)
{
	char	*result;

	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		s2 = ft_strdup("");
	result = ft_strjoin(s1, s2);
	mem_clear((void *) &s1);
	mem_clear((void *) &s2);
	return (result);
}

char	*read_file(int fd)
{
	char	*map;
	char	*aux;

	map = NULL;
	while (1)
	{
		aux = get_next_line(fd);
		if (!aux)
			return (map);
		map = join_and_free(map, aux);
	}
}
