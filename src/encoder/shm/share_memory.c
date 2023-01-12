/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   share_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:00:57 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/12 18:40:27 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../encoder.h"

static key_t	get_key()
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

static key_t	get_block(key_t key, int size)
{
	int	shmid;

	shmid = shmget(key, size, 0644 | IPC_CREAT | IPC_EXCL);
	if (shmid < 0)
	{
		read_shm(key);
		return (-1);
	}
	return (shmid);
}

void	share_memory(unsigned char *compressed, t_lst *frequency)
{
	unsigned char	*mem;
	unsigned char	*data;
	key_t			key;
	int				shmid;
	int				size_data;

	join_data(compressed, frequency, &data, &size_data);
	key = get_key();
	shmid = get_block(key, size_data);
	if (shmid < 0)
	{
		free(data);
		return ;
	}
	mem = shmat(shmid, NULL, 0);
	ft_memmove(mem, data, size_data);
	printf("Message compressed and saved on shared memory! Now is time to execute decoder program.\n");
	free(data);
}
