/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frequency.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:39:19 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/09 21:02:26 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./encoder.h"

static char	*get_text(char *filename)
{
	int		fd;
	char	*text;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	text = read_file(fd);
	return (text);
}

void	frequency(char *filename)
{
	char	*text;
	t_lst	*frequency;

	text = get_text(filename);
	printf("%s\n\n", text);
	frequency = lst_new('w');
	frequency->next = lst_new('z');
	printf("letter: %c\n", lst_find(frequency, 'w')->c);
}
