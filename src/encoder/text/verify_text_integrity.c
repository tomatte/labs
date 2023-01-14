/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_text_integrity.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:30:27 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/14 13:56:21 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../encoder.h"

static int	ft_ustrncmp(unsigned char *s1, unsigned char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	if (!n)
		return (0);
	while (s1[i] || s2[i])
	{
		if (i + 1 == n)
			break ;
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	verify_text_integrity(unsigned char *decompressed, unsigned char *original)
{
	if (!ft_ustrncmp(decompressed, original, ft_strlen(original)))
		printf("Integrity: perfect!\n");
	else
		printf("Integrity: failed!\n");
	printf("-------------------------------------------------------\n");
}
