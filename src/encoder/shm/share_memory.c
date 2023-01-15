/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   share_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:00:57 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/15 12:43:06 by dbrandao         ###   ########.fr       */
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

	shmid = shmget(key, size, 0644 | IPC_CREAT);
	if (shmid < 0)
	{
		printf("Block error!\n");
		exit(1);
	}
	return (shmid);
}

void	share_memory(unsigned char *compressed, t_lst *frequency, t_tree *nodes_copy)
{
	unsigned char	*mem;
	unsigned char	*data;
	key_t			key;
	int				shmid;
	int				size_data;

	join_data(compressed, frequency, &data, &size_data, nodes_copy);
	key = get_key();
	shmid = get_block(key, size_data);
	if (shmid < 0)
	{
		free(data);
		return ;
	}
	mem = shmat(shmid, NULL, 0);
	ft_memmove(mem, data, size_data);
	printf("Message compressed and saved on shared memory!\n");
	shmdt(mem);
	free(data);
}
