/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:10:21 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/10 12:11:34 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../encoder.h"

char	*get_text(char *filename)
{
	int		fd;
	char	*text;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	text = read_file(fd);
	return (text);
}
