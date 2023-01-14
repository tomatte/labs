/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_shm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:33:14 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/14 13:57:12 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../encoder.h"

static key_t	get_block(key_t key)
{
	int	shmid;

	printf("Waiting for decompression...\n");
	while (1)
	{
		shmid = shmget(key, 0, 0);
		if (shmid >= 0)
			break ;
		sleep(1);
	}
	return (shmid);
}

static key_t	get_key(void)
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

t_segment	read_shm(void)
{
	unsigned char	*data;
	t_segment		segment;
	int				shmid;
	int				key;

	key = get_key();
	shmid = get_block(key);
	data = shmat(shmid, NULL, 0);
	printf("\n--------------- DECODED MESSAGE ---------------\n\n");
	printf("%s", data);
	segment.mem = data;
	segment.shmid = shmid;
	return (segment);
}
