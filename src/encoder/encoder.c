/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:44:58 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/09 19:47:05 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./encoder.h"

static void	exit_error(void)
{
	printf("Needs a filename!\n");
	exit(1);
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
		exit_error();
	frequency(argv[1]);
	printf("encoder!\n");
	return (0);
}
