/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_shm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:33:14 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/12 18:38:30 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../encoder.h"

static key_t	get_block(key_t key)
{
	int	shmid;

	shmid = shmget(key, 0, 0);
	if (shmid < 0)
	{
		printf("Block error at read_shm.c\n");
		exit(1);
	}
	return (shmid);
}

void	read_shm(int key)
{
	char	*data;
	int		shmid;

	shmid = get_block(key);
	data = shmat(shmid, NULL, 0);
	printf("%s\n", data);
	shmdt(data);
	shmctl(shmid, IPC_RMID, NULL);
}
