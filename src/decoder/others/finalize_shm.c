/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalize_shm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:10:49 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/14 10:43:12 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../decoder.h"


static void	send_response(char *text, int  shmid)
{
	char	*mem;

	mem = shmat(shmid, NULL, 0);
	ft_memmove(mem, text, strlen(text) + 1);
}

static key_t	get_response_key(void)
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

key_t	get_response_block(key_t key, int size)
{
	int	shmid;

	shmid = shmget(key, size, 0644 | IPC_CREAT);
	if (shmid < 0)
	{
		printf("Block error!\n");
		exit(1);
	}
	return (shmid);
}


static void	remove_old_memory(unsigned char *data, int shmid)
{
	shmdt(data);
	shmctl(shmid, IPC_RMID, NULL);
}

void	finalize_shm(unsigned char *data, char *text, int old_shmid)
{
	int		shmid;
	key_t	key;

	key = get_response_key();
	shmid = get_response_block(key, ft_strlen(text) + 1);
	remove_old_memory(data, old_shmid);
	send_response(text, shmid);
	printf("Message decoded and saved to shared memory.\n");
}
