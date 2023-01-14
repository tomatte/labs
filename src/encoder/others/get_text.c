/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:10:21 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/14 10:27:15 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../encoder.h"

static char	*extract_text(char *arg)
{
	int		fd;
	char	*text;

	fd = open(arg, O_RDONLY);
	if (fd < 0)
		text = strdup(arg);
	else
		text = read_file(fd);
	return (text);
}

static void	join_and_free(char **text, char *str)
{
	char	*new;

	new = ft_strjoin(*text, str);;
	free(*text);
	free(str);
	*text = new;
}

char	*get_text(int argc, char **argv)
{
	char	*text;
	int		i;
	

	i = 1;
	text = strdup("");
	while (i < argc)
	{
		join_and_free(&text, extract_text(argv[i]));
		i++;
	}
	return (text);
}
