/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:59:32 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/11 21:31:49 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../decoder.h"

key_t	get_key(void)
{
	key_t	key;

	key = ftok("./src/encoder/encoder.h", 1);
	if (key < 0)
	{
		printf("Key error!\n");
		exit(1);
	}
	return (key);
}

key_t	get_block(key_t key)
{
	int	shmid;

	shmid = shmget(key, 0, 0);
	if (shmid < 0)
	{
		printf("Block error!\n");
		exit(1);
	}
	return (shmid);
}

void	read_memory(char **data)
{
	key_t			key;
	int				shmid;

	key = get_key();
	shmid = get_block(key);
	printf("read shmid: %d\n", shmid);
	*data = shmat(shmid, NULL, 0);
}
