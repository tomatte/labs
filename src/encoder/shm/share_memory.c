/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   share_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:00:57 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/11 17:47:48 by dbrandao         ###   ########.fr       */
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

void	share_memory(char *binary, t_lst *frequency)
{
	int		shmid;
	key_t	key;
	char	*mem;
	char	*data;
	int		size_data;

	join_data(binary, frequency, &data, &size_data);
	printf("binary: %s\nletters: %s\nsize_data: %d\n", data, (data) + strlen(data) + 1, size_data);
	key = get_key();
	shmid = get_block(key, size_data);
	mem = shmat(shmid, NULL, 0);
	ft_memmove(mem, data, size_data);
}
