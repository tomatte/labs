/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   share_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:00:57 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/11 14:21:03 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../encoder.h"

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

void	share_memory(char *binary, t_lst *frequency)
{
	int		shmid;
	key_t	key;
	void	*buff;
	t_data	data;

	key = get_key();
	shmid = get_block(key, strlen(binary) + 1);
	buff = shmat(shmid, NULL, 0);
	ft_memmove(buff, binary, strlen(binary) + 1);
}
