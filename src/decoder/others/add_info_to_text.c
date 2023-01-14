/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_info_to_text.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:40:12 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/14 13:55:55 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../decoder.h"

static void	join_and_free(char **text, char *str)
{
	char	*new;

	new = ft_strjoin(*text, str);;
	free(*text);
	free(str);
	*text = new;
}

static char	*get_exec_time(t_time mtime)
{
	double	exec_time;
	char	exec_time_str[20];

 	exec_time = ((double) (mtime.end - mtime.start)) / CLOCKS_PER_SEC;
	sprintf(exec_time_str, "%f", exec_time);
	return (strdup(exec_time_str));
}

void	add_info_to_text(char **text, unsigned char *data, t_time mtime)
{
	char	*info;
	char	*exec_time;
	int		size_compressed;
	int		size_text;

	exec_time = get_exec_time(mtime);
	ft_memmove(&size_compressed, data, sizeof(int));
	size_text = strlen(*text);
	info = strdup("\n\n-------- INFORMATION ABOUT DECODING PROCESS --------\nText full size: ");
	join_and_free(&info, ft_itoa(size_text));
	join_and_free(&info, strdup(" bytes\nCompressed size: "));
	join_and_free(&info, ft_itoa(size_compressed));
	join_and_free(&info, strdup(" bytes\nDecompression time: "));
	join_and_free(&info, exec_time);
	join_and_free(&info, strdup("s\n"));
	join_and_free(text, info);
}
