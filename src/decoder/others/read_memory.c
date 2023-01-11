/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:59:32 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/11 14:19:55 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../decoder.h"

static key_t	get_key()
{
	key_t	key;

	key = ftok("./src/encoder/encoder.c", 1);
	if (key < 0)
	{
		printf("Key error!\n");
		exit(1);
	}
	return (key);
}

static key_t	get_block(key_t key)
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


void	read_memory(void)
{
	key_t			key;
	int				shmid;
	size_t			size;
	char			*mem;
	struct shmid_ds	shm_info;

	key = get_key();
	shmid = get_block(key);
	printf("read shmid: %d\n", shmid);
	mem = shmat(shmid, NULL, 0);
	shmctl(shmid, IPC_STAT, &shm_info);
	size = shm_info.shm_segsz;
	printf("FUCKING BINARY: %s\n", mem);
	printf("red size: %ld\n", size);
}
