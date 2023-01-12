/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalize_shm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:10:49 by dbrandao          #+#    #+#             */
/*   Updated: 2023/01/12 15:49:59 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../decoder.h"


static void	send_response(int key)
{
	int		shmid;
	char	*mem;
	char	*response;

	response = strdup("ESSA EH A RESPOSTA!\n");
	shmid = shmget(key, strlen(response) + 1, 0644 | IPC_CREAT);
	mem = shmat(shmid, NULL, 0);
	ft_memmove(mem, response, strlen(response) + 1);
	free(response);
}

void	finalize_shm(unsigned char *data)
{
	int		shmid;
	key_t	key;
	char	*response;

	key = get_key();
	shmid = get_block(key);
	shmdt(data);
	shmctl(shmid, IPC_RMID, NULL);
	send_response(key);
}
