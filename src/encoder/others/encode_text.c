/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:17:06 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/10 12:24:37 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../encoder.h"

static char	*join_and_free(char *s1, char *s2)
{
	char	*big;

	if (!s1 || !s2)
		return (NULL);
	big = ft_strjoin(s1, s2);
	free(s1);
	return (big);
}

char	*encode_text(t_lst *frequency, char *text)
{
	char	*encoded;

	encoded = strdup("");
	while (*text)
	{
		encoded = join_and_free(encoded, lst_find(frequency, *text)->code);
		text++;
	}
	return (encoded);
}
