/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_text_integrity.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:30:27 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/15 14:24:44 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../encoder.h"

void	verify_text_integrity(char *decompressed, char *original)
{
	if (!ft_strncmp(decompressed, original, ft_strlen(original)))
		printf("Integrity: perfect!\n");
	else
		printf("Integrity: failed!\n");
	printf("-------------------------------------------------------\n");
}
